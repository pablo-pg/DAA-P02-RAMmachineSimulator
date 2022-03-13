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
 std::fstream& input, std::fstream& output, int debug_mode) {
  this->instructions = instructions;
  memory.input.swap(input);
  memory.output.swap(output);
  memory.program_counter = 0;
  instructions_executed = 0;
  memory.registers.resize(10);
  if (debug_mode == 2) {
    debug = true;
  }
}

RAM::~RAM() {
  for (Instruction* instruction : instructions) {
    delete instruction;
  }
}

int RAM::execute() {
  try {
    while (true) {
      instructions[memory.program_counter]->execute(memory);
      if (debug) {
        std::cout << "INSTRUCCIÓN " << instructions_executed + 1<< ": "
                  << instructions[memory.program_counter]->to_string() << std::endl
                  << "  MEMORIA: " << memory.registers.size() << std::endl;
        for (size_t i = 0; i < memory.registers.size(); ++i) {
          std::cout << "    R[" << i << "] = " << memory.registers[i] << std::endl;
        }
      }
      instructions_executed++;
    }
  } catch(ExecutionEnd& e) {}
  return instructions_executed;
}

const std::vector<Instruction*>& RAM::getInstructions() const {
  return instructions;
}
