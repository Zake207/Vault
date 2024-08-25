#include "Subprocess_class.h"
#include "netcp_tools.h"

int main(int argc, char *argv[]) {
  ////////////////////////////////////////////
  struct sigaction term_action = {0};
  term_action.sa_handler = &term_signal_handler;
  // term_action.sa_flags = SA_RESTART;

  sigaction(SIGTERM, &term_action, NULL);
  sigaction(SIGINT, &term_action, NULL);
  sigaction(SIGHUP, &term_action, NULL);
  sigaction(SIGQUIT, &term_action, NULL);

  // struct sigaction segv_action = {0};
  // segv_action.sa_handler = &segv_signal_handler;

  // sigaction( SIGSEGV, &segv_action, NULL );
  ////////////////////////////////////////////
  bool option_listening{false}, option_comm{false};
  std::string NombreArchivo{}, redirected_io{};
  std::vector<std::string> comm_args{};
  std::vector<std::string_view> args(argv + 1, argv + argc);
  for (auto i = args.begin(), end = args.end(); i != end; ++i) {
    if (*i == "-h" || *i == "--help") {
      usage();
      exit(0);
    } else if (*i == "-l") {
      option_listening = true;
      std::cout << "Detectada opcion -l" << std::endl;
    } else if (*i == "-c") {
      option_comm = true;
      std::cout << "Detectada opcion -c" << std::endl;
      bool bool_standar{false}, bool_error{false}, in_bool_standar{false},
          in_bool_error{false};
      if (option_listening == false) {
        if (*(i + 1) == "-1") {
          bool_standar = true;
          ++i;
        }
        if (*(i + 1) == "-2") {
          bool_error = true;
          ++i;
        }
        if (*(i + 2) == "-1") {
          bool_standar = true;
          ++i;
        }
        if (*(i + 2) == "-2") {
          bool_error = true;
          ++i;
        }
        OptionSelectorOut(bool_standar, bool_error, redirected_io);
      }
      if (option_listening == true) {
        if (*(i + 1) == "-1") {
          in_bool_standar = true;
          ++i;
        }
        if (*(i + 1) == "-2") {
          in_bool_error = true;
          ++i;
        }
        if (*(i + 2) == "-1") {
          in_bool_standar = true;
          ++i;
        }
        if (*(i + 2) == "-2") {
          in_bool_error = true;
          ++i;
        }
        OptionSelectorIn(in_bool_standar, in_bool_error, redirected_io);
      }
      for (auto j = i + 1; j != end; ++j) {
        std::string str_pivote{*j};
        comm_args.push_back(str_pivote);
      }
      subprocess command(comm_args, redirected_io);
      command.exec();
      // netcp_receive_comm(command.stdin_fd());
      break;
    } else {
      NombreArchivo = *i;
    }
  }
  if (!option_listening && !option_comm) {
    netcp_send_file(NombreArchivo);
    if (quit_requested == true) {
      return 1;
    }
    return 0;
  }
  if (option_listening && !option_comm) {
    netcp_receive_file(NombreArchivo);
    if (quit_requested == true) {
      return 1;
    }
    return 0;
  }
}
