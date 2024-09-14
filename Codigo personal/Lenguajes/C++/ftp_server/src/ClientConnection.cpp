//****************************************************************************
//                         REDES Y SISTEMAS DISTRIBUIDOS
//                      
//                     2º de grado de Ingeniería Informática
//                       
//              This class processes an FTP transaction.
// 
//****************************************************************************



#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cerrno>
#include <netdb.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h> 
#include <iostream>
#include <dirent.h>

#include "common.h"

#include "ClientConnection.h"
#include "FTPServer.h"




ClientConnection::ClientConnection(int s) {
    int sock = (int)(s);
  
    char buffer[MAX_BUFF];

    control_socket = s;
    // Check the Linux man pages to know what fdopen does.
    fd = fdopen(s, "a+");
    if (fd == NULL){
	std::cout << "Connection closed" << std::endl;

	fclose(fd);
	close(control_socket);
	ok = false;
	return ;
    }
    
    ok = true;
    data_socket = -1;
    parar = false;
   
  
  
};


ClientConnection::~ClientConnection() {
 	fclose(fd);
	close(control_socket); 
  
}


int connect_TCP( uint32_t address,  uint16_t  port) {
    struct sockaddr_in sin;
    struct hostent *hent;
    int s;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    
    // if(hent = gethostbyaddr((char *)&address, sizeof(address), AF_INET)) 
    //     memcpy(&sin.sin_addr, hent->h_addr, hent->h_length);
    if (sin.sin_addr.s_addr = address == INADDR_NONE)
         errexit("No puedo resolver el nombre \"%s\"\n", hent);
    
     
    s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0)
       errexit("No se puede crear el socket: %s\n", strerror(errno));

    if(connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
       errexit("No se puede conectar con %s: %s\n", hent, strerror(errno));

    return s;

}






void ClientConnection::stop() {
    close(data_socket);
    close(control_socket);
    parar = true;
  
}





    
#define COMMAND(cmd) strcmp(command, cmd)==0

// This method processes the requests.
// Here you should implement the actions related to the FTP commands.
// See the example for the USER command.
// If you think that you have to add other commands feel free to do so. You 
// are allowed to add auxiliary methods if necessary.

void ClientConnection::WaitForRequests() {
    if (!ok) {
	 return;
    }
    
    fprintf(fd, "220 Service ready\n");
  
    while(!parar) {

      fscanf(fd, "%s", command);
      if (COMMAND("USER")) {
	    fscanf(fd, "%s", arg);
	    fprintf(fd, "331 User name ok, need password\n");
      }
      else if (COMMAND("PWD")) {
	   
      }
      else if (COMMAND("PASS")) {
        fscanf(fd, "%s", arg);
        if(strcmp(arg,"1234") == 0){
            fprintf(fd, "230 User logged in\n");
        }
        else{
            fprintf(fd, "530 Not logged in.\n");
            parar = true;
        }
	   
      }
      else if (COMMAND("PORT")) {
        std::cout << "PORT" << std::endl;

      /*el comando por ejemplo PORT 127,0,0,1,4,2
    hay que declarar 6 enteros para los 6 valores
    int a1, a2, a3, a4, p1, p2;
    fscanf(fd, "%d,%d,%d,%d,%d,%d", &a1, &a2, &a3, &a4, &p1, &p2);
    uint32_t adress = (a1 << 24) | (a2 << 16) | (a3 << 8) | a4;      recoger el valor de la ip si no funciona se invierte el orden de los valores (a4,a3,a2,a1)
    uint16_t port = (p1 << 8) | p2;                                  inicializar el puerto con los valores de p1 y p2
    data_socket = connect_TCP(adress, port);
    fprintf(fd, "200 OK\n");
      */
      int a1, a2, a3, a4, p1, p2;
      fscanf(fd, "%d,%d,%d,%d,%d,%d", &a1, &a2, &a3, &a4, &p1, &p2);
      uint32_t adress = (a4 << 24) | (a3 << 16) | (a2 << 8) | a1;
      uint16_t port = (p1 << 8) | p2;
      data_socket = connect_TCP(adress, port);
      fprintf(fd, "200 OK\n");

      }
      else if (COMMAND("PASV")) {
	  std::cout << "PASV" << std::endl;
///////////////////////////////////////////////////////////////////////////////////////
      int s = define_socket_TCP(0);

      struct sockaddr_in sin;
      socklen_t len = sizeof(sin);
      getsockname(s, (struct sockaddr *)&sin, &len);
      uint16_t port = sin.sin_port;

      int part1 = (port >> 8) & 0xff;
      int part2 = port & 0xff;
      fprintf(fd, "227 Entering Passive Mode (127,0,0,1,%d,%d)\n", part2, part1);
      fflush(fd);
      data_socket = accept(s, (struct sockaddr*)&sin, &len); // s, &fsin, &alen
      close(s);

///////////////////////////////////////////////////////////////////////////////////////
      }
      else if (COMMAND("CWD")) {
      }
      else if (COMMAND("STOR") ) {
	    std::cout << "STOR" << std::endl;
      // char* arg;
      fscanf(fd, "%s", arg);

      printf("STOR");
        char buffer[MAX_BUFF];
        FILE *f = fopen(arg, "rb");
        if(f == NULL){
          fprintf(fd, "550 Failed to open file.\n");
          continue;
        }
        
        fprintf(fd, "150 File status okay; about to open data connection.\n");
        fflush(fd);
        while (1) {
          int n = recv(data_socket, buffer, MAX_BUFF, 0);
          fwrite(buffer, 1, n, f);
          if(n <= MAX_BUFF) break;
        }
        fprintf(fd, "226 Closing data connection. Requested file action successful.\n");
        fclose(f);
        close(data_socket);

      }
      else if (COMMAND("RETR")) {
	   std::cout << "RETR" << std::endl;
      char buffer[MAX_BUFF];
     fscanf(fd, "%s", arg);
      FILE *f = fopen(arg, "rb");
      if(f == NULL){
          fprintf(fd, "550 Failed to open file.\n");
          continue;
      }
      fprintf(fd, "150 File status okay; about to open data connection.\n");
      while (1) {
          int n = fread(buffer, 1, MAX_BUFF, f);
          if(n <= 0) break;
          send(data_socket, buffer, n, 0);
      }
      fprintf(fd, "226 Closing data connection. Requested file action successful.\n");
      fclose(f);
      close(data_socket);

      }
      else if (COMMAND("LIST")) {
	   std::cout << "LIST" << std::endl;	

      // opendir() abre un directorio y devuelve un puntero de tipo DIR.       REVISAR LA SECCIÓN 3 DEL MANUAL

      DIR *dir = opendir(".");
      if(dir == NULL){
          fprintf(fd, "550 Failed to open directory.\n");
          continue;
      }
      fprintf(fd, "150 Here comes the directory listing.\n");
      struct dirent *entry;
      while ((entry = readdir(dir)) != NULL) {
        send(data_socket, entry->d_name, strlen(entry->d_name), 0);
      }
      fprintf(fd, "226 Directory send OK.\n");
      fflush(fd);
      closedir(dir);
      close(data_socket);

      // readdir() lee el siguiente registro del directorio.
      // closedir() cierra el directorio.
      }
      else if (COMMAND("SYST")) {
           fprintf(fd, "215 UNIX Type: L8.\n");   
      }

      else if (COMMAND("TYPE")) {
	  fscanf(fd, "%s", arg);
	  fprintf(fd, "200 OK\n");   
      }

     else if (COMMAND("SIZE")) {
	     fscanf(fd, "%s", arg);
	     fprintf(fd, "502 Command not implemented.\n"); fflush(fd);
      }
     
      else if (COMMAND("QUIT")) {
        fprintf(fd, "221 Service closing control connection. Logged out if appropriate.\n");
        close(data_socket);	
        parar=true;
        break;
      }
  
      else  {
	    fprintf(fd, "502 Command not implemented.\n"); fflush(fd);
	    printf("Comando : %s %s\n", command, arg);
	    printf("Error interno del servidor\n");
	
      }
      
    }
    
    fclose(fd);

    
    return;
  
};
