#include "netcp_tools.h"
#pragma once

class subprocess {
 private:
  std::string redirected_io_{};
  std::vector<std::string> comm_args_{};
  std::vector<const char*> comm_args_c_str_{};
  int pipe_[2];
  pid_t child_pid_{1};

  std::error_code Create_pipe() {
    int pipe_fd_ = pipe(pipe_);
    if (pipe_fd_ < 0) {
      return std::error_code(errno, std::system_category());
    }



    std::cout << "#  Tuberia creada." << std::endl;
    return std::error_code(0, std::system_category());
  }
  void ArgsConverter(std::vector<std::string> args_str) {
    for (int i = 0; i < args_str.size(); ++i) {
      comm_args_c_str_.push_back(args_str[i].c_str());
    }
    comm_args_c_str_.push_back(NULL);
  }
  bool Alive(const pid_t pid) {  // True si el proceso hijo esta ejecutandose,
                                 // false en el resto
    int status{};
    pid_t pid_result = waitpid(pid, &status, WNOHANG);
    if (pid_result == 0) {
      return true;
    } else {
      return false;
    }
  }

 public:
  subprocess(const std::vector<std::string>& args, std::string redirected_io) {
    std::cout << "#  Constructor de la clase subprocess invocado." << std::endl;
    redirected_io_ = redirected_io;
    comm_args_ = args;
    Create_pipe();
    ArgsConverter(comm_args_);
    std::cout << "#  Objeto creado." << std::endl;
  }

  std::error_code exec() {  // Crea proceso hijo y ejecuta el comando indicado
    child_pid_ = fork();
    if (child_pid_ == 0) {
      // std::cout << "Soy el hijo y voy a ejecutar el siguiente comando: " <<
      // comm_args_[0] << std::endl; std::cout << "El tipo de operación es " +
      // redirected_io_ << std::endl; std::cout << "Mi pid es " << child_pid_ <<
      // std::endl;
      if (redirected_io_ == "out") {
        std::cout << "Se realizará un OUT" << std::endl;
        close(pipe_[0]);
        dup2(pipe_[1], STDOUT_FILENO);
        close(pipe_[1]);
        execvp(comm_args_c_str_[0],
               const_cast<char* const*>(comm_args_c_str_.data()));
      }
      if (redirected_io_ == "outerr") {
        std::cout << "Se realizará un OUTERR" << std::endl;
        close(pipe_[0]);
        dup2(pipe_[1], STDERR_FILENO);
        close(pipe_[1]);
        execvp(comm_args_c_str_[0],
               const_cast<char* const*>(comm_args_c_str_.data()));
      }
      if (redirected_io_ == "out outerr") {
        std::cout << "Se realizará un AMBAS SALIDAS" << std::endl;
        close(pipe_[0]);
        dup2(pipe_[1], STDOUT_FILENO);
        dup2(pipe_[1], STDERR_FILENO);
        close(pipe_[1]);
        execvp(comm_args_c_str_[0],
               const_cast<char* const*>(comm_args_c_str_.data()));
      }
      if (redirected_io_ == "in") {
        std::cout << "Se realizará un IN" << std::endl;
        close(pipe_[1]);
        dup2(pipe_[0], STDIN_FILENO);
        close(pipe_[0]);
        execvp(comm_args_c_str_[0],
               const_cast<char* const*>(comm_args_c_str_.data()));
      }
      if (redirected_io_ == "inerr") {
        std::cout << "Se realizará un INERR" << std::endl;
        close(pipe_[1]);
        dup2(pipe_[0], STDERR_FILENO);
        close(pipe_[0]);
        execvp(comm_args_c_str_[0],
               const_cast<char* const*>(comm_args_c_str_.data()));
      }
      if (redirected_io_ == "in inerr") {
        std::cout << "Se realizará un AMBAS ENTRADAS" << std::endl;
        close(pipe_[1]);
        dup2(pipe_[0], STDIN_FILENO);
        dup2(pipe_[0], STDERR_FILENO);
        close(pipe_[0]);
        execvp(comm_args_c_str_[0],
               const_cast<char* const*>(comm_args_c_str_.data()));
      }
      return std::error_code(0, std::system_category());
    } else if (child_pid_ > 0) {
      // std::cout << "Soy el padre" << std::endl;
      // if (Alive(child_pid_)) std::cout << "mi hijo vive" << std::endl;
      if (redirected_io_ == "out" || redirected_io_ == "outerr" ||
          redirected_io_ == "out outerr") {
        close(pipe_[1]);
        int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);  // SOCKET
        if (sock_fd < 0) {
          std::cout << "#  Ha ocurrido un error al crear el socket"
                    << std::endl;
          return std::error_code(errno, std::system_category());
        }
        std::string ipaddress{"127.0.0.1"};  //  DIRECCIÓN
        uint16_t port{8080};
        if (!getenvar("NETCP_IP").empty()) {
          ipaddress = getenvar("NETCP_IP");
        }
        if (!getenvar("NETCP_PORT").empty()) {
          port = std::stoi(getenvar("NETCP_PORT"));
        }
        auto local_address = make_ip_address(ipaddress, port);
        bool sending = true;
        while (sending) {
          if (quit_requested == true) {
            std::cout << "quit requested" << std::endl;
            close_descriptor(pipe_[0]);
            close_descriptor(sock_fd);
            return std::error_code(0, std::system_category());
          }
          std::vector<uint8_t> buffer(16ul * 1024);
          read_file(pipe_[0], buffer);
          if (buffer.size() == 0) {
            buffer.resize(0);
            send_to(sock_fd, buffer, local_address.value());
            sending = false;
          }
          for (int i = 0; i < buffer.size(); i += 1024) {
            std::vector<uint8_t> subbuffer(1024);
            int k = 0;
            for (int j = i; k < 1024 && j != buffer.size(); ++j, ++k) {
              if (quit_requested == true) {
                std::cout << "quit requested" << std::endl;
                close_descriptor(pipe_[0]);
                close_descriptor(sock_fd);
                return std::error_code(0, std::system_category());
              }
              subbuffer[k] = buffer[j];
            }
            subbuffer.resize(k);
            send_to(sock_fd, subbuffer, local_address.value());
          }
        }
        close(pipe_[0]);
        close(sock_fd);
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      }
      if (redirected_io_ == "in" || redirected_io_ == "inerr" ||
          redirected_io_ == "in inerr") {
        close(pipe_[0]);
        netcp_receive_comm(pipe_[1]);
        close(pipe_[1]);
      }
      if (quit_requested == true) {
        if (Alive(child_pid_)) {
          kill(child_pid_, SIGINT);
        }
      }
      return std::error_code(0, std::system_category());
    }
    return std::error_code(0, std::system_category());
  }
  // std::error_code wait() {    // Espera a que el proceso hijo termine
  //     // PORQUE NO USO ALIVE
  //     // EN QUE SE DIFERENCIA CON ALIVE
  //     // ULTIMAS 2 PAGINAS DEL GUION
  // }
  // std::error_code kill() {    // Mata al proceso hijo

  // }
  // pid_t pid() {               // Devuelve el pid del hijo y -1 si no se esta
  // ejecutando el comando

  // }
  int stdin_fd() {  // devuelve el descriptor del archivo de entrada estandar
    return pipe_[0];
  }
  int stdout_fd() { 
    return pipe_[1]; 
  }
};