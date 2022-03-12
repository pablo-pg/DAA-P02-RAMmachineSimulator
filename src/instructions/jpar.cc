/**
 * @file jpar.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/jpar.h"

void JParInstruction::execute(Memory& mem) const {
  if (mode == Mode::label) {
    if (mem.registers[ACCUMULATOR_REG] % 2 == 0) {
      mem.program_counter = operand;
    } else {
      mem.program_counter += 1;
    }
  } else {
    throw InvalidMode(to_string());
  }
}

std::string JParInstruction::to_string() const {
  return JPAR_INSTRUCTION_ID + std::string(" ") + std::to_string(operand);
}
