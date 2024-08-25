# !/bin/bash

###DECLARACION DE VARIABLES
option_view=0		#Comprueba si se marcó la opción -v o -vall
option_v=0		#Comprueba si se eligio la opcion -v
option_vall=0		#Comprueba si se eligio la opcion -vall
nombre=			#Nombre del proceso
ejecutable=		#Nombre del proceso con sus parámetros
attach=0		#1 si se selecciona -nattach
flags_strace=		#Parámetros del comando strace
PID=			#Pid del proceso a seguir si attach == 1
ID=$(uuidgen)		#Codigo del la ejecucion del comando que se acoplara al nombre del archivo creado
n_trace=0
tracer_process=		#Nombre del proceso que monitoriza a un proceso de usuario
pattach=0
nattach=0
lista_nattch=
lista_pattch=
guion="-"
###DECLARACION DE FUNCIONES
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
usage() {		#Muestra el funcionamiento de scdebug
echo 'scdebug [-h] [-sto arg] [-v | -vall] [ -nattch progtoattach] [prog [arg1 ...]]'
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
funcion_attach(){	#Rastrea el PID del proceso mas reciente con el mismo nombre
PID=$(ps -eo pid,comm | grep $nombre | sort -nr | head -n1 | awk '{print $1}')
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
view() {
if [[ "$option_v" = 1 ]] && [[ "$option_vall" = 1 ]]; then
	echo "ERROR: no se puede ejecutar -v junto a -vall" 1>&2           #comprueba que no se solapen los comandos
else

    if [ "$option_v" == 1 ]; then					#Si se marco -v se mostrara el fichero mas nuevo una lista de comandos
	for comando in $ejecutable; do
		if [ -e $HOME/.scdebug/$comando ]; then
		  echo =====COMMAND: $comando=====
		  echo =====TRACE FILE: $(ls -lt $HOME/.scdebug/$comando | awk '{print $9}' | head -n2)=====
		  echo =====TIME: $(ls -lt $HOME/.scdebug/$comando | awk '{print $6" "$7" "$8}' | head -n2)=====
		else
		  echo ""
		  echo "ERROR: no se detectó ningun registro de traza del comando $comando" 1>&2	
		  echo ""
		fi
	done
    	echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
    fi

    if [ "$option_vall" == 1 ]; then					#Si se marco -vall se mostrarán todos lo ficheros de una lista de comandos
	for comando in $ejecutable; do
	    if [ -e $HOME/.scdebug/$comando ]; then
		for fichero in $HOME/.scdebug/$comando/*; do 
			echo =====COMMAND: $comando=====
			echo =====TRACE FILE: $fichero=====
			echo =====TIME: $(ls -lt $fichero | awk '{print $6" "$7" "$8}')=====
		done
		echo " "
		echo " "
	    else
		echo ""
		echo "ERROR: no se detectó ningun registro de traza del comando $comando" 1>&2
		echo ""
	    fi
	done
    fi
fi
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#FUNCION QUE MUESTRA EL PID Y NOMBRE DE LOS PROCESOS SEGUIDOS Y EL PID Y NOMBRE DE LOS QUE LOS SIGUEN
show_process() {
for pid in $(ps -u $USER -o pid); do
	if [ -e /proc/$pid/status ]; then
		tracer_process=$(cat /proc/$pid/status | grep TracerPid: | awk '{print $2}')
		if [ "$tracer_process" != "0" ]; then
			ps -o pid,comm --no-header $pid | tr -s ' ' ' '
			echo " SEGUIDO POR "
			ps -o pid,comm --no-header $tracer_process | tr -s ' ' ' '
			echo " "
		fi

	fi
done
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#Funcion que asesina a los procesos del usuario que estan siendo trazados y a los trazadores de estos
kill_trace() {
for pid in $(ps -u $USER -o pid); do
        if [ -e /proc/$pid/status ]; then
                tracer_process=$(cat /proc/$pid/status | grep TracerPid: | awk '{print $2}')
                if [ "$tracer_process" != "0" ]; then
			kill $tracer_process
			if [ "$?" == "1" ]; then
				echo "=== $tracer_process FATAL ERROR:NO PUDO SER ELIMINADO, NO SE PERMITE" 1>&2
			fi
			kill $pid
			if [ "$?" == "1" ]; then
				echo "=== $pid FATAL ERROR: NO PUDO SER ELIMINADO, NO SE PERMITE" 1>&2
			fi
		fi
        fi
done
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

###CREACION DE DIRECTORIOS
Crea_directorios() {
if test -e $HOME/.scdebug; then                 # si existe el primer directorio comprueba el siguiente
        if test -e $HOME/.scdebug/$nombre; then
                false
        else
                mkdir $HOME/.scdebug/$nombre    # si no existe lo crea
        fi


else                                            # en caso de que el primero no exista se crean ambos directorios
        mkdir $HOME/.scdebug
        mkdir $HOME/.scdebug/$nombre
fi
RUTA="$HOME/.scdebug/$nombre/trace_$ID.txt"
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

###LECTURA DE LOS FLAGS INTRODUCIDOS
if [ "$1" = "" ]; then
	show_process
	echo "ERROR: No se detectan parametros" 1<&2
	exit 1
fi
while [ "$1" != "" ]; do
    case $1 in					#En este case se lee por linea de comandos los flags introducidos
    	-h | --help )
        	usage
        	exit
       	;;
	-kill | -k)
		kill_trace
		if [ "$?" = "1" ]; then
                	echo "ERROR: Algun proceso no se pudo eliminar correctamente o  no hay procesos que eliminar." 1>&2
			exit 1
        	fi
	;;
    	-sto )
	    	shift
            	flags_strace=$1
        ;;
    	-v)
	    	option_view=1
           	option_v=1
        ;;
	-vall)
	    	option_view=1
	    	option_vall=1
	;;
	-nattch )
	    	attach=1
	    	nattach=1
        ;;
	-pattch)
		attach=1
		pattach=1

	;;
    	*)
		nombre=$1
	    	while [ $# -gt 0 ]; do	#Lectura del programa a monitorizar con sus respectivos parámetros
			ejecutable=$ejecutable" "$1
			shift
	    	done
    esac
    shift
done
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Funcion que comprueba si -v o -vall se llego a marcar alguna vez
if [ "$option_view" == 1 ]; then						
	view
	if [ "$?" = "0" ]; then
                false
        else
               echo "ERROR: No hay registros de traza" 1>&2
    	fi
else
	show_process
fi
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
###FUNCIONALIDAD DE ATTACH

if [ "$attach" == 0 ]; then
	Crea_directorios
	if [ "$?" = "1" ]; then
                echo "ERROR: no se pudo crear el directorio de $ejecutable" 1>&2	#Comprueba que se pudo crear el directorio
                exit 1
        fi
	if [ "$ejecutable" = "" ]; then
               echo "ERROR: no se pudo leer ningun programa a monitorizar" 1>&2             #Si no lee programas
               exit 1
        fi
########################################################################################################################################
	if [ -x $nombre ]; then								#DUDA: como hago para que man pase el filtro
                false
        else
               echo "ERROR: $nombre no válido" 1>&2					#Comprueba si el ejecutable pasado es correcto
               exit 1
        fi
########################################################################################################################################

	strace $flags_strace -o $RUTA $ejecutable					#Ejecucion de strace sin el attach
	if [ "$?" = "1" ]; then
		echo "ERROR: no se pudo hacer la traza de $ejecutable" 1>&2		#Si hubo algun problema da el mensaje de error y sale
		exit 1
	fi
else
########################################################################################################################################

#if [[ "$nattach" = 1 ]] && [[ "$pattach" = 1 ]]; then
#        echo "ERROR: no se puede ejecutar -nattch junto a -pattch" 1>&2           #comprueba que no se solapen los comandos
#else
	if [ "$nattach" == 1 ]; then
		for comando in $ejecutable; do						# Por cada comando leido
			ID=$(uuidgen)
			if [[ $comando =~ ^[$guion](.*) ]]; then			# Comprueba que no sea un parametro de un proceso
				false
			else
				nombre=$comando						# Guarda su nombre y obtiene su pid
               			funcion_attach
				if [ -e /proc/$PID/status ]; then			# Si exite el fichero de ese pid realiza la traza
					seguido=$(cat /proc/$PID/status | grep "Tracer" | awk '{print $2}')
					if [ "$seguido" = 0 ]; then			# La traza se hara solo si el pid no esta siendo trazado
						Crea_directorios
						strace $flags_strace -p $PID -o $RUTA &                    	#Ejecucion del strace con el attach
						if [ "$?" = "1" ]; then 
							echo "ERROR: no se pudo hacer la traza de $nombre" 1>&2
						fi
					else
						echo "ERROR: el proceso $nombre esta siendo seguido por el pid $seguido" 1>&2
					fi
				else
					echo "ERROR: El pid $PID no puede ser trazado" 1>&2
				fi	
			fi
		done
	fi
	if [ "$pattach" == 1 ]; then
		for PID in $ejecutable; do								# Resvisa todos los pid introducidos
		ID=$(uuidgen)										# Generando un id nuevo para cada uno
		if [ -e /proc/$PID/status ]; then							# Comprueba que exite el fichero del pid
			seguido=$(cat /proc/$PID/status | grep "Tracer" | awk '{print $2}')
			if [ $seguido = "0" ]; then							# si ese pid no esta siendo seguido se le
				nombre=$(cat /proc/$PID/status | grep "Name:" | awk '{print $2}')	# hace un traza
                		Crea_directorios
                		strace $flags_strace -p $PID -o $RUTA &
                                if [ "$?" = "1" ]; then 
                                	echo "ERROR: no se pudo hacer la traza de $nombre" 1>&2		# Escribiendo los errores pertinentes si
                                fi									# si se requiriese
			else
				echo "ERROR: El pid $PID no puede ser trazado" 1>&2
			fi
		else
                        echo "ERROR: pid o ruta no valida para $PID" 1>&2
                fi
		done
	fi
    fi
#fi
########################################################################################################################################

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
