/**
 * @file store.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/store.h"

void StoreInstruction::execute(Memory& mem) const {
  int value;
  switch (mode) {
  case Mode::inmediate:
    throw InvalidStore(to_string());
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    value = mem.registers[ACCUMULATOR_REG];
    mem.registers[operand] = value;
    break;
  case Mode::indirect:
    value = mem.registers[ACCUMULATOR_REG];
    mem.registers[mem.registers[operand]] = value;
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string StoreInstruction::to_string() const {
  return STORE_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}
