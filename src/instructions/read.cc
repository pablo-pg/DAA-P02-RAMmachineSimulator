/**
 * @file read.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/read.h"


int read_number(std::fstream& input) {
  std::string number_str;
  std::getline(input, number_str);
  int number;
  try {
    number = std::stoi(number_str);
  } catch(std::exception& e) {
    throw InvalidInput(number_str);
  }
  return number;
}

void ReadInstruction::execute(Memory& mem) const {
  switch (mode) {
  case Mode::inmediate:
    throw InvalidRead(to_string());
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    mem.registers[operand] = read_number(mem.input);
    break;
  case Mode::indirect:
    mem.registers[mem.registers[operand]] = read_number(mem.input);
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.input_head += 1;
  mem.program_counter += 1;
}

std::string ReadInstruction::to_string() const {
  return READ_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}
