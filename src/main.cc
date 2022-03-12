/**
 * @file main.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
 #include <windows.h>
 #error No se pudo compilar en Windows
#endif // Si se compila en Windows

#if defined(__APPLE__) && defined(__MACH__)
 #error No se pudo compilar en iOS
#endif


#include <iostream>
#include "../include/ram.h"
#include "../include/ram_generator.h"

void show_usage() {
  std::cout << "Usage:\n"
      << "./ram_sim ram_program.ram input_tape.in output_tape.out\n"
      << "Debug is optional and activates debug mode" << std::endl;
}

int main(int argc, char** argv) {
  if (argc == 2 && std::string(argv[1]) == "-h") {
    show_usage();
    return 0;
  }
  if (argc < 5) {
    std::cout << "Invalid number of arguments. Use -h to see the help"
              << std::endl;
    return 1;
  }
  std::fstream instructions_file(argv[1], std::ios::in);
  std::fstream input_file(argv[2], std::ios::in);
  std::fstream output_file(argv[3], std::ios::out | std::ios::trunc | std::ios::in);
  RAMBuilder builder;
  try {
    builder.read_instructions_from(instructions_file);
  } catch(std::exception& e) {
    std::cout << "An error ocurred while reading the instructions: " << e.what() << "\n";
    return 2;
  }
  builder.set_input_stream(input_file);
  builder.set_output_stream(output_file);
  builder.set_debug(std::stoi(std::string(argv[4])));
  RAM* ram;
  ram = builder.build();
  try {
    int instructions_executed = ram->execute();
    if (builder.get_debug() == 1 || builder.get_debug() == 2) {
      std::cout << "Execution finished succesfully after " << instructions_executed << " instructions\n";
    }
  } catch(std::exception& e) {
    std::cout << "An error ocurred during the execution: " << e.what() << "\n";
  }

  delete ram;
  return 0;
}
