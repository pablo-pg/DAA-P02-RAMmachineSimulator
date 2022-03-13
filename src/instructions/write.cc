/**
 * @file write.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/write.h"

void WriteInstruction::execute(Memory& mem) const {
  switch (mode) {
  case Mode::inmediate:
    mem.output << operand << "\n";
    mem.str_output.push_back(std::to_string(operand));
    
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    if (operand == ACCUMULATOR_REG) {
      throw InvalidWrite(to_string());
    }
    mem.output << mem.registers[operand] << "\n";
    mem.str_output.push_back(std::to_string(mem.registers[operand]));
    break;
  case Mode::indirect:
    mem.output << mem.registers[mem.registers[operand]] << "\n";
    mem.str_output.push_back(std::to_string(mem.registers[mem.registers[operand]]));
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.output_head += 1;
  mem.program_counter += 1;
}

std::string WriteInstruction::to_string() const {
  return WRITE_INSTRUCTION_ID + std::string(" ") +
    mode_to_string(mode) + std::to_string(operand);
}
