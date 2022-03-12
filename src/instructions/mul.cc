/**
 * @file mul.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/mul.h"

void MultInstruction::execute(Memory& mem) const {
  int value;
  switch (mode) {
  case Mode::inmediate:
    mem.registers[ACCUMULATOR_REG] *= operand;
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    value = mem.registers[operand];
    mem.registers[ACCUMULATOR_REG] *= value;
    break;
  case Mode::indirect:
    value = mem.registers[mem.registers[operand]];
    mem.registers[ACCUMULATOR_REG] *= value;
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string MultInstruction::to_string() const {
  return MULT_INSTRUCTION_ID + std::string(" ") +
    mode_to_string(mode) + std::to_string(operand);
}
