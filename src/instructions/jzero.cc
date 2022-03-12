/**
 * @file jzero.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/jzero.h"

void JZeroInstruction::execute(Memory& mem) const {
  if (mode == Mode::label) {
    if (mem.registers[ACCUMULATOR_REG] == 0) {
      mem.program_counter = operand;
    } else {
      mem.program_counter += 1;
    }
  } else {
    throw InvalidMode(to_string());
  }
}

std::string JZeroInstruction::to_string() const {
  return JZERO_INSTRUCTION_ID + std::string(" ") + std::to_string(operand);
}
