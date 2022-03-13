/**
 * @file ram.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "../include/ram.h"

RAM::RAM(const std::vector<Instruction*>& instructions,
 std::fstream& input, std::fstream& output, int debug_mode,
 std::vector<std::string> str_input) {
  this->instructions = instructions;
  memory.input.swap(input);
  memory.output.swap(output);
  memory.program_counter = 0;
  memory.str_input = str_input;
  instructions_executed = 0;
  memory.registers.resize(5);
  if (debug_mode == 2) {
    debug = true;
  }
}

RAM::~RAM() {
  instructions.resize(0);
}

int RAM::execute() {
  try {
    while (true) {
      instructions[memory.program_counter]->execute(memory);
      if (debug) {
        std::cout << "INSTRUCCIÓN " << instructions_executed + 1 << ": "
                  << instructions[memory.program_counter]->to_string() << std::endl
                  << "  MEMORIA: " << std::endl;
        for (size_t i = 0; i < memory.registers.size(); ++i) {
          std::cout << "    R[" << i << "] = " << memory.registers[i] << std::endl;
        }
        std::cout << "  CINTA ENTRADA:  ";
        for (size_t i = 0; i < memory.str_input.size(); ++i) {
          if ((int)i == memory.input_head - 1) {
            std::cout << "\033[1m" << memory.str_input[i] << "\033[0m" << " ";
          } else {
            std::cout << memory.str_input[i] << " ";
          }
        }
        std::cout << std::endl;
        std::cout << "  CINTA SALIDA:  ";
        for (size_t i = 0; i < memory.str_output.size(); ++i) {
          if ((int)i == memory.output_head - 1) {
            std::cout << "\033[1m" << memory.str_output[i] << "\033[0m" << " ";
          } else {
            std::cout << memory.str_output[i] << " ";
          }
        }
        std::cout << std::endl;
      }
      instructions_executed++;
    }
  } catch(ExecutionEnd& e) {}
  return instructions_executed;
}

const std::vector<Instruction*>& RAM::getInstructions() const {
  return instructions;
}
