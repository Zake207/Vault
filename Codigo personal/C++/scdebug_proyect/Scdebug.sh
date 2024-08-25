# !/bin/bash

###DECLARACION DE VARIABLES
option_view=0		#Comprueba si se marcó la opción -v o -vall
option_v=0			#Comprueba si se eligio la opcion -v
option_vall=0		#Comprueba si se eligio la opcion -vall
nombre=				#Nombre del proceso
ejecutable=			#Nombre del proceso con sus parámetros
attach=0			#1 si se selecciona -nattach
flags_strace=		#Parámetros del comando strace
PID=				#Pid del proceso a seguir si attach == 1
ID=$(uuidgen)		#Codigo del la ejecucion del comando que se acoplara al nombre del archivo creado
n_trace=0
tracer_process=		#Nombre del proceso que monitoriza a un proceso de usuario
pattach=0			#Variable que se penodrá a 1 en caso de que se marque la opción pattch
nattach=0			#Variable que se penodrá a 1 en caso de que se marque la opción nattch
lista_nattch=		#Variable usada para recoger la lista de procesos de la funcionalidad nattch
lista_pattch=		#Variable usada para recoger la lista de procesos de la funcionalidad pattch
guion="-"			#Variable local de comprobación, usada para comprobar si una cadena de carácteres empieza por guion
###DECLARACION DE FUNCIONES
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
usage() {																									#Muestra el funcionamiento de scdebug
echo 'scdebug [-h] [-sto arg] [-k | -kill] [-v | -vall] [-S Commname programtopause] [prog [arg1 ...]] [ -nattch progstoattach] [ -pattch progstoattach]'
echo "-h | --help: Se ve la información relacionada con el proceso"
echo "-sto: Se le debe pasar una lista de argumentos válidos para strace estando esta lista entre comillas simples"
echo "-v | -vall: Muestra información realcionada con los ficheros de las trazas"
echo "-k | -kill: Mata a los procesos que estan siendo trazados y a los procesos trazadores"
echo "-nattch: Se le debe pasar una lista de nombre de procesos en ejecución para que el programa los monitorice"
echo "-pattch: Se le debe pasar una lista de pids de proceosos en ejecución para que el programa los monitorice"
echo "-S: Funcion Stop, este recoge el nombre pasado a continuacion para para el script renombrandolo con traced_ + Commname"
echo "######################################################################################################################################"
echo " "
}
launch_strace() {
	strace $flags_strace -o $RUTA $ejecutable >& /dev/null										#Ejecucion de strace sin el attach
	if [ "$?" = "1" ]; then
		echo "ERROR: no se pudo hacer la traza de ~~ $ejecutable ~~" | tee -a fallos.txt 1>&2 	#Si hubo algun problema da el mensaje de error y sale
	else
		echo "STRACE: de $ejecutable realizado con éxito"
	fi
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
funcion_attach(){	#Rastrea el PID del proceso mas reciente con el mismo nombre
PID=$(ps -eo pid,comm | grep $nombre | sort -nr | head -n1 | awk '{print $1}')
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
view() {
    if [ "$option_v" == 1 ]; then																			#Si se marco -v se mostrara el fichero mas nuevo una lista de comandos
	for comando in $ejecutable; do
		if [ -e $HOME/.scdebug/$comando ]; then
		  echo =====COMMAND: $comando=====
		  echo =====TRACE FILE: $(ls -lt $HOME/.scdebug/$comando | awk '{print $9}' | head -n2)=====
		  echo =====TIME: $(ls -lt $HOME/.scdebug/$comando | awk '{print $6" "$7" "$8}' | head -n2)=====
		else
		  echo ""
		  echo "ERROR: no se detectó ningun registro de traza del comando $comando" | tee -a fallos.txt 1>&2 
		  echo ""
		fi
	done
    	echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
    fi

    if [ "$option_vall" == 1 ]; then																		#Si se marco -vall se mostrarán todos lo ficheros de una lista de comandos
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
		echo "ERROR: no se detectó ningun registro de traza del comando $comando" | tee -a fallos.txt 1>&2 
		echo ""
	    fi
	done
    fi
}
funcion_nattch() {
	for comando in $lista_nattch; do																		# Por cada comando leido
		ID=$(uuidgen)
		if [[ $comando =~ ^[$guion](.*) ]]; then															# Comprueba que no sea un parametro de un proceso
			false
		else
			nombre=$comando																					# Guarda su nombre y obtiene su pid
            funcion_attach
			if [ -e /proc/$PID/status ]; then																# Si exite el fichero de ese pid realiza la traza
				seguido=$(cat /proc/$PID/status | grep "Tracer" | awk '{print $2}')
				if [ "$seguido" = 0 ]; then																	# La traza se hara solo si el pid no esta siendo trazado
					Crea_directorios
					strace $flags_strace -p $PID -o $RUTA & >& /dev/null                    								#Ejecucion del strace con el attach
					if [ "$?" = "1" ]; then 
						echo "ERROR: no se pudo hacer la traza de $nombre" | tee -a fallos.txt 1>&2 
					else
						echo "El proceso $comando esta siendo trazado..."
					fi
				else
					echo "ERROR: el proceso $nombre esta siendo seguido por el pid $seguido" | tee -a fallos.txt 1>&2 
				fi
			else
				echo "ERROR: $comando no puede ser trazado" | tee -a fallos.txt 1>&2 
			fi	
		fi
	done
}
funcion_pattch() {
	for PID in $lista_pattch; do																			# Resvisa todos los pid introducidos
		ID=$(uuidgen)																						# Generando un id nuevo para cada uno
		if [ -e /proc/$PID/status ]; then																	# Comprueba que exite el fichero del pid
			seguido=$(cat /proc/$PID/status | grep "Tracer" | awk '{print $2}')
			if [ $seguido = "0" ]; then																		# si ese pid no esta siendo seguido se le
				nombre=$(cat /proc/$PID/status | grep "Name:" | awk '{print $2}')							# hace un traza
                Crea_directorios
                strace $flags_strace -p $PID -o $RUTA & >& /dev/null
                if [ "$?" = "1" ]; then 
                    echo "ERROR: no se pudo hacer la traza de $nombre" | tee -a fallos.txt 1>&2 			# Escribiendo los errores pertinentes si
				else
					echo "El proceso $PID esta siendo trazado..."
                fi																							# si se requiriese
			else
				echo "ERROR: El pid $PID esta siendo seguido por $seguido" | tee -a fallos.txt 1>&2 
			fi
		else
            echo "ERROR: pid o ruta no valida para $PID" | tee -a fallos.txt  1>&2 
        fi
	done
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#FUNCION QUE MUESTRA EL PID Y NOMBRE DE LOS PROCESOS SEGUIDOS Y EL PID Y NOMBRE DE LOS QUE LOS SIGUEN
show_process() {
echo "PROCESOS EN PROCESO DE TRAZA:"
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
echo "######################################################################################################################################"
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#Funcion que asesina a los procesos del usuario que estan siendo trazados y a los trazadores de estos
kill_trace() {
for pid in $(ps -u $USER -o pid); do
    if [ -e /proc/$pid/status ]; then
        tracer_process=$(cat /proc/$pid/status | grep TracerPid: | awk '{print $2}') 
        if [ "$tracer_process" != "0" ]; then																#Si el proceso está siendo trazado
			kill $tracer_process																			#mata al proceso trazado y al trazador
			if [ "$?" == "1" ]; then
				echo "FATAL ERROR:NO PUDO SER ELIMINADO, NO SE PERMITE" | tee -a fallos.txt  1>&2 			#Soltando los errores pertinentes
			else
				echo "KILL: $tracer_process eliminado"
			fi
			kill $pid
			if [ "$?" == "1" ]; then
				echo "FATAL ERROR: NO PUDO SER ELIMINADO, NO SE PERMITE" | tee -a fallos.txt  1>&2 
			else
				echo "KILL: $pid eliminado"
			fi
		fi
    fi
done
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

###CREACION DE DIRECTORIOS
Crea_directorios() {
if test -e $HOME/.scdebug; then                 															# si existe el primer directorio comprueba el siguiente
    if test -e $HOME/.scdebug/$nombre; then
        false
    else
        mkdir $HOME/.scdebug/$nombre    																	# si no existe lo crea
    fi
else                                          																# en caso de que el primero no exista se crean ambos directorios
    mkdir $HOME/.scdebug
    mkdir $HOME/.scdebug/$nombre
fi
RUTA="$HOME/.scdebug/$nombre/trace_$ID.txt"
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				   COMIENZO DEL PROGRAMA PRINCIPAL
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

###LECTURA DE LOS FLAGS INTRODUCIDOS
if [ "$1" = "" ]; then
	show_process
	echo "ERROR: No se detectan parametros" | tee -a ./fallos.txt 1>&2
	exit 1
fi
while [ "$1" != "" ]; do
    case $1 in																								#En este case se lee por linea de comandos los flags introducidos
    	-h | --help )
        	usage
       	;;
		-kill | -k)
			kill_trace
			if [ "$?" = "1" ]; then
               	echo "ERROR: Algun proceso no se pudo eliminar correctamente o  no hay procesos que eliminar." | tee -a fallos.txt 1>&2 
        	fi
		;;
		-g | -gc | -ge)
			if [ "$1" = "-g" ]; then
				echo "-g"
			fi
			if [ "$1" = "-ge" ]; then
				echo "-ge"
			fi
			if [ "$1" = "-gc" ]; then
				echo "-gc"
			fi
		;;
		-S)
			shift
			CommName=$1
			ejecutable=$2
			shift
			while [ "$1" != "" ]; do  																		#Lectura del programa a monitorizar con sus respectivos parámetros
				shift
				ejecutable=$ejecutable" "$1
            done
			echo -n "traced_$CommName" > /proc/$$/comm
			echo "~~~ PROCESO traced_$CommName EN ESPERA"
			kill -SIGSTOP $$
			exec $ejecutable
			exit 0

		;;
    	-sto)
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
		-nattch)
			nattach=1
			shift
			while [ "$1" != "" ]; do
				if [[ "$2" = "-pattch" || "$2" = "-sto" || "$2" = "-k" || "$2" = "-kill" || "$2" = "-nattch" || "$2" = "-h" || "$2" = "--help" || "$2" = "-S" ]]; then
					lista_nattch=$lista_nattch" "$1
					break;
				else
					lista_nattch=$lista_nattch" "$1
					shift
				fi
			done
    	;;
		-pattch)
			pattach=1
			shift
			while [ "$1" != "" ]; do
				if [[ "$2" = "-pattch" || "$2" = "-sto" || "$2" = "-k" || "$2" = "-kill" || "$2" = "-nattch" || "$2" = "-h" || "$2" = "--help" || "$2" = "-S" ]]; then
					lista_pattch=$lista_pattch" "$1
					break;
				else
					lista_pattch=$lista_pattch" "$1
					shift
				fi
			done
		;;
		*)
            nombre=$1
			ejecutable=$1
            while [ "$1" != "" ]; do  																		#Lectura del programa a monitorizar con sus respectivos parámetros
				if [[ "$2" = "-pattch" || "$2" = "-sto" || "$2" = "-k" || "$2" = "-kill" || "$2" = "-nattch" || "$2" = "-h" || "$2" = "--help" ]]; then
					break;
				else
					shift
					ejecutable=$ejecutable" "$1
				fi
            done
    esac
    shift
done

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Funcion que comprueba si -v o -vall se llego a marcar alguna vez
if [ "$option_view" == 1 ]; then	
	if [[ $option_view = 1 && $nattach = 1 ]]; then
		echo "ATENCION: No se pueden ejecutar -nattch junto a v y vall"
	fi
	if [[ $option_view = 1 && $pattach = 1 ]]; then
		echo "ATENCION: No se pueden ejecutar -pattch junto a v y vall"
	fi				
	view
	if [ "$?" = "0" ]; then
            false
        else
            echo "ERROR: No hay registros de traza" | tee -a fallos.txt 1>&2 
    	fi
else
	show_process
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
###FUNCIONALIDAD DE ATTACH
    Crea_directorios
	if [ "$?" = "1" ]; then
        echo "ERROR: no se pudo crear el directorio de $ejecutable" | tee -a fallos.txt 1>&2 	#Comprueba que se pudo crear el directorio
    fi
	if [ "$ejecutable" = "" ]; then
        echo "ATENCIÓN: no se pudo leer ningun programa a monitorizar" | tee -a fallos.txt 1>&2             #Si no lee programas
    fi
########################################################################################################################################
	if [ -e /usr/bin/$nombre ]; then
        false
    else
        echo "ERROR: $nombre no válido" | tee -a fallos.txt 1>&2 					#Comprueba si el ejecutable pasado es correcto
        exit 1
    fi
########################################################################################################################################
	launch_strace &

	if [ "$nattach" = "1" ]; then																			# Función de nattch
		echo " "
		echo ===================
		echo "EJECUTANDO NATTCH"
		echo ===================
		echo " "
		funcion_nattch
	fi
	if [ "$pattach" = "1" ]; then																			# Función de pattch
		echo " "
		echo ===================
		echo "EJECUTANDO PATTCH"
		echo ===================
		echo " "
		funcion_pattch
	fi
fi
