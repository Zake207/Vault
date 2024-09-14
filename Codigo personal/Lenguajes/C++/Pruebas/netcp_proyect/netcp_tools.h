#pragma once
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <atomic>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

std::atomic<bool> quit_requested = false;

/// @brief manejador de señales que se encarga de suministrar un mensaje si
/// llevan las señales esperadas
/// @param signum Numero identificador de la señal que servirá para
/// identificarla
void term_signal_handler(int signum) {
  quit_requested = true;
  const char* message;
  if (signum == SIGTERM) {
    quit_requested = true;
    message = "Señal SIGTERM recibida.\n";
  } else if (signum == SIGINT) {
    quit_requested = true;
    message = "Señal SIGINT recibida.\n";
  } else if (signum == SIGHUP) {
    quit_requested = true;
    message = "Señal SIGHUP recibida.\n";
  } else if (signum == SIGQUIT) {
    quit_requested = true;
    message = "Señal SIGQUIT recibida.\n";
  } else {
    message = "Señal desconocida recibida.\n";
  }
  write(STDOUT_FILENO, message, strlen(message));
}

/// @brief  Función que muestra el funcionamiento y propósito del programa
void usage() {
  std::cout << "#  Programa diseñado para hacer envio de ficheros por sockets"
            << std::endl;
  std::cout << "#  Debe introducir el nombre de un archivo existente cuyo "
               "tamaño no supere 1 KiB"
            << std::endl;
}

/// @brief Funcion que abre el fichero a enviar
/// @param filename Nombre del fichero a abrir
/// @return El descriptor del fichero
int OpenFileSending(std::string filename) {
  int file_fd = open(filename.c_str(), O_RDONLY);
  if (file_fd == -1) {
    return -1;
  }
  return file_fd;
}

/// @brief Función que abre el fichero para introducir el mensaje recibido
/// @param filename Nombre que del fichero a editar
/// @return El descriptor de dicho fichero
int OpenFileRecieving(std::string filename) {
  int file_fd = open(filename.c_str(), O_WRONLY | O_CREAT, 0666);
  if (file_fd == -1) {
    return -1;
  }
  return file_fd;
}

/// @brief Función que englova getenv, comprueba la existencia de la variable de
/// entorno introducida
/// @param name nombre de la variable de entorno
/// @return El valor de la varibale de entorno si existe si no devuelve " "
std::string getenvar(const std::string& name) {
  char* value = getenv(name.c_str());
  if (value) {
    return std::string(value);
  } else {
    return std::string();
  }
}

/// @brief Función para medir la longitud de un archivo
/// @param filename nombre del archivo a medir
/// @return El tamaño del fichero
int FileSize(std::string filename) {
  struct stat stat_buf;
  int rc = stat(filename.c_str(), &stat_buf);
  return rc == 0 ? stat_buf.st_size : -1;
}

/// @brief Función encargada de leer el contenido de un fichero
/// @param fd El descriptor del fichero a leer
/// @param buffer Memoria utilizada para almacenar la lectura
/// @return Codigo de error de la operación
std::error_code read_file(int fd, std::vector<uint8_t>& buffer) {
  ssize_t bytes_read = read(fd, buffer.data(), buffer.size());
  if (bytes_read < 0) {
    return std::error_code(errno, std::system_category());
  }
  buffer.resize(bytes_read);
  return std::error_code(0, std::system_category());
}

/// @brief Crea una dirección válida para asociar a un socket
/// @param ip_address String que recoge la IP
/// @param port Puerto destino
/// @return Una direccón válida para enlazar
std::optional<sockaddr_in> make_ip_address(
    const std::optional<std::string>& ip_address, uint16_t port = 0) {
  sockaddr_in local_address{};
  local_address.sin_family = AF_INET;
  if (ip_address == " ") {
    local_address.sin_addr.s_addr = htonl(INADDR_ANY);
  } else {
    inet_aton(ip_address.value().data(),
              reinterpret_cast<in_addr*>(&local_address.sin_addr));
  }
  local_address.sin_port = htons(port);
  return local_address;
}

/// @brief Función de envió, envía message mediante un socket a la dirección
/// especificada
/// @param fd descriptor del socket
/// @param message mensaje a enviar
/// @param address dirección de envio
/// @return Código de error de la operación
std::error_code send_to(int fd, const std::vector<uint8_t>& message,
                        const sockaddr_in& address) {
  // std::cout << message.size() << std::endl;
  int sent =
      sendto(fd, message.data(), message.size(), 0,
             reinterpret_cast<const sockaddr*>(&address), sizeof(address));
  if (sent < 0) {
    return std::error_code(errno, std::system_category());
  } else {
    // std::cout << "#  MENSAJE ENVIADO DE MANERA EXITOSA" << std::endl;
    return std::error_code(0, std::system_category());
  }
}

/// @brief Cierra el descriptor especificado
/// @param descriptor Descriptor a cerrar
void close_descriptor(int descriptor) {
  int closed = close(descriptor);
  if (closed < 0) {
    std::cout << "#  descriptor: " << descriptor
              << " no pudo ser cerrado correctamente." << std::endl;
  } else {
    std::cout << "#  descriptor: " << descriptor << " cerrado correctamente."
              << std::endl;
  }
}

/// @brief Función que escribe el contenido recibido en el buffer en el Archivo
/// indicado por linea de parámetros
/// @param fd Descriptor del archivo a escribir
/// @param buffer Buffer usado para almacenar el contenido
/// @return El codigo de error de la función
std::error_code write_to(int fd, const std::vector<uint8_t>& buffer) {
  int written = write(fd, buffer.data(), buffer.size());
  if (written < 0)
    return std::error_code(errno, std::system_category());
  else
    return std::error_code(0, std::system_category());
  ;
}

/// @brief Compara las entradas para dar una salida
/// @param opt_1 primera entrada a comparar
/// @param opt_2 segunda entrada a comparar
/// @param redirections string que alacena la salida resultante
void OptionSelectorOut(bool opt_1, bool opt_2, std::string& redirections) {
  if (opt_1 && opt_2) redirections = "out outerr";
  if (!opt_1 && opt_2) redirections = "outerr";
  if (opt_1 && !opt_2) redirections = "out";
  if (!opt_1 && !opt_2) redirections = "out";
}

/// @brief Compara las entradas para dar una salida
/// @param opt_1 primera entrada a comparar
/// @param opt_2 segunda entrada a comparar
/// @param redirections string que almacena la salida resultante
void OptionSelectorIn(bool opt_1, bool opt_2, std::string& redirections) {
  if (opt_1 && opt_2) redirections = "in inerr";
  if (!opt_1 && opt_2) redirections = "inerr";
  if (opt_1 && !opt_2) redirections = "in";
  if (!opt_1 && !opt_2) redirections = "in";
}

/// @brief Recoge la información que llegue a una dirección la escribe en el
/// fichero de destino
/// @param fd Descriptor del fichero destino
/// @param buffer Memoria buffer donde se almacenará el contenido del envio
/// @param address Dirección (IP y Puerto) desde se recogerá el envio
/// @return Código de error de la función.
std::error_code recieve_from(int f_fd, int s_fd, std::vector<uint8_t>& buffer,
                             sockaddr_in& address) {
  socklen_t src_len = sizeof(address);
  bool fallo = false;
  while (!fallo) {
    /////////////////////////////////////////////////////////////////
    if (quit_requested == true) {
      std::cout << "#  Se ha recibido un señal de parada, abortando..."
                << std::endl;
      buffer.resize(0);
      write_to(f_fd, buffer);
      // close_descriptor(f_fd);
      // close_descriptor(s_fd);
      return std::error_code(0, std::system_category());
      fallo = true;
    }
    /////////////////////////////////////////////////////////////////
    int recieved = recvfrom(s_fd, buffer.data(), buffer.size(), 0,
                            reinterpret_cast<sockaddr*>(&address), &src_len);
    if (quit_requested == true) {
      std::cout << "#  Se ha recibido un señal de parada, abortando..."
                << std::endl;
      buffer.resize(0);
      write_to(f_fd, buffer);
      // close_descriptor(f_fd);
      // close_descriptor(s_fd);
      return std::error_code(0, std::system_category());
      fallo = true;
    }
    buffer.resize(recieved);
    if (buffer.size() <= 0) {
      buffer.resize(0);
      write_to(f_fd, buffer);
      fallo = true;
    }
    write_to(f_fd, buffer);
    usleep(16);
    if (quit_requested == true) {
      std::cout << "#  Se ha recibido un señal de parada, abortando..."
                << std::endl;
      buffer.resize(0);
      write_to(f_fd, buffer);
      // close_descriptor(f_fd);
      // close_descriptor(s_fd);
      return std::error_code(0, std::system_category());
      fallo = true;
    }
  }
  return std::error_code(0, std::system_category());
}

/// @brief Mediante un socket recoge la información enviada por otro proceso a
/// la dirección especificada
/// @param NombreArchivo String que recoge el nombre del archivo donde se
/// volcará el envío
/// @return Codigo de error de la operación, 0 si todo va bien.
std::error_code netcp_receive_comm(const int pipe_pid) {
  int file_fd = pipe_pid;
  if (file_fd < 0) {
    std::cout << "#  Ha ocurrido un error inesperado abriendo el archivo de "
                 "escritura."
              << std::endl;
    return std::error_code(errno, std::system_category());
  } else {
    std::vector<uint8_t> buffer(16ul * 1024 * 1024);  // Creacion del buffer
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);     // Definir Socket
    if (sock_fd < 0) {
      std::cout << "#  Ha ocurrido un error creando el socket." << std::endl;
      return std::error_code(errno, std::system_category());
    }
    std::cout << "#  Creando dirección..." << std::endl;
    std::string ipaddress{"127.0.0.1"};  //  DIRECCIÓN
    uint16_t port{8080};
    if (!getenvar("NETCP_IP").empty()) {
      ipaddress = getenvar("NETCP_IP");
    }
    if (!getenvar("NETCP_PORT").empty()) {
      port = std::stoi(getenvar("NETCP_PORT"));
    }
    auto local_address =
        make_ip_address(ipaddress, port);  // Creacion de la dirección
    int result =
        bind(sock_fd, reinterpret_cast<const sockaddr*>(&local_address),
             sizeof(local_address));  // Enlazado de la dirección
    if (result < 0) {
      std::cout << "#  Dirección no pudo ser enlazada al socket." << std::endl;
      return std::error_code(errno, std::system_category());
    }
    recieve_from(file_fd, sock_fd, buffer, local_address.value());
    ////////////////////////////////////////////////////////////////////////////////
    if (quit_requested == true) {
      std::cout << "quit recieved" << std::endl;
      close_descriptor(file_fd);
      close_descriptor(sock_fd);
      std::cout << "netcp: terminando debido a señal" << std::endl;
      return std::error_code(0, std::system_category());
    }
    ///////////////////////////////////////////////////////////////////////////////
    close_descriptor(sock_fd);
  }
  return std::error_code(0, std::system_category());
}
/// @brief Mediante un socket envia el contenido de un buffer que recoge el
/// contenido de un archivo, solo puede enviar hasta 16 MB
/// @param NombreArchivo String que recoge el nombre del archivo a enviar
/// @return Codigo de error de la función, 0 si todo fue bien
std::error_code netcp_send_file(const std::string& NombreArchivo) {
  int file_fd = OpenFileSending(NombreArchivo);  //  APERTURA DE FICHERO
  if (file_fd < 0) {
    std::cout << "netcp: No se pudo abrir el archivo de nombre'"
              << NombreArchivo << "'" << std::endl;
    return std::error_code(errno, std::system_category());
  } else {
    std::cout << "#  Se pudo abrir el archivo correctamente." << std::endl;

    std::cout << "#  Buffer creado con éxito." << std::endl;
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);  // CREACIÓN DE SOCKET
    if (sock_fd < 0) {
      std::cout << "#  Ha ocurrido un error al crear el socket" << std::endl;
      return std::error_code(errno, std::system_category());
    }
    std::cout << "#  Socket creado con éxito." << std::endl;
    std::cout << "#  Creando dirección..." << std::endl;
    std::string ipaddress{"127.0.0.1"};  //  DIRECCIÓN
    uint16_t port{8080};
    if (!getenvar("NETCP_IP").empty()) {
      ipaddress = getenvar("NETCP_IP");
    }
    if (!getenvar("NETCP_PORT").empty()) {
      port = std::stoi(getenvar("NETCP_PORT"));
    }
    auto local_address = make_ip_address(ipaddress, port);
    std::cout << "#  Dirección creada." << std::endl;
    bool sending = true;
    while (sending) {
      ////////////////////////////////////////////////////////////////////////////////
      if (quit_requested == true) {
        std::cout << "quit requested" << std::endl;
        close_descriptor(file_fd);
        close_descriptor(sock_fd);
        return std::error_code(0, std::system_category());
      }
      ///////////////////////////////////////////////////////////////////////////////
      std::vector<uint8_t> buffer(16ul *1024* 1024);
      read_file(file_fd, buffer);
      if (buffer.size() == 0) {
        buffer.resize(0);
        send_to(sock_fd, buffer, local_address.value());
        sending = false;
      }
      for (int i = 0; i < buffer.size(); i += 1024 * 16) {
        std::vector<uint8_t> subbuffer(1024 * 16ul);
        int k = 0;
        for (int j = i; k < 1024 * 16 && j != buffer.size(); ++j, ++k) {
          ////////////////////////////////////////////////////////////////////////////////
          if (quit_requested == true) {
            std::cout << "quit requested" << std::endl;
            close_descriptor(file_fd);
            close_descriptor(sock_fd);
            return std::error_code(0, std::system_category());
          }
          ////////////////////////////////////////////////////////////////////////////////
          subbuffer[k] = buffer[j];
        }
        subbuffer.resize(k);
        send_to(sock_fd, subbuffer, local_address.value());
        usleep(32);
      }
    }
    close_descriptor(file_fd);  //  FIN
    close_descriptor(sock_fd);
  }
  return std::error_code(0, std::system_category());
}

/// @brief Mediante un socket recoge la información enviada por otro proceso a
/// la dirección especificada
/// @param NombreArchivo String que recoge el nombre del archivo donde se
/// volcará el envío
/// @return Codigo de error de la operación, 0 si todo va bien.
std::error_code netcp_receive_file(const std::string& NombreArchivo) {
  int file_fd = OpenFileRecieving(NombreArchivo);
  if (file_fd < 0) {
    std::cout << "#  Ha ocurrido un error inesperado abriendo el archivo de "
                 "escritura."
              << std::endl;
    return std::error_code(errno, std::system_category());
  } else {
    std::vector<uint8_t> buffer(16ul * 1024 * 1024);  // Creacion del buffer
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);     // Definir Socket
    if (sock_fd < 0) {
      std::cout << "#  Ha ocurrido un error creando el socket." << std::endl;
      return std::error_code(errno, std::system_category());
    }
    std::cout << "#  Creando dirección..." << std::endl;
    std::string ipaddress{"127.0.0.1"};  //  DIRECCIÓN
    uint16_t port{8080};
    if (!getenvar("NETCP_IP").empty()) {
      ipaddress = getenvar("NETCP_IP");
    }
    if (!getenvar("NETCP_PORT").empty()) {
      port = std::stoi(getenvar("NETCP_PORT"));
    }
    auto local_address =
        make_ip_address(ipaddress, port);  // Creacion de la dirección
    int result =
        bind(sock_fd, reinterpret_cast<const sockaddr*>(&local_address),
             sizeof(local_address));  // Enlazado de la dirección
    if (result < 0) {
      std::cout << "#  Dirección no pudo ser enlazada al socket." << std::endl;
      return std::error_code(errno, std::system_category());
    }
    std::cout << "#  Realizando envío..." << std::endl;
    recieve_from(file_fd, sock_fd, buffer, local_address.value());
    ////////////////////////////////////////////////////////////////////////////////
    if (quit_requested == true) {
      std::cout << "quit recieved" << std::endl;
      std::cout << "netcp: terminando debido a señal" << std::endl;
      return std::error_code(0, std::system_category());
    }
    ///////////////////////////////////////////////////////////////////////////////
    close_descriptor(file_fd);
    close_descriptor(sock_fd);
  }
  return std::error_code(0, std::system_category());
}