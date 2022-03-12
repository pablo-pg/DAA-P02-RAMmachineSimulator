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
  memory.registers.resize(5);
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
      instructions_executed++;
    }
  } catch(ExecutionEnd& e) {}
  return instructions_executed;
}

const std::vector<Instruction*>& RAM::getInstructions() const {
  return instructions;
}
