/**
 * @file jump.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/jump.h"

void JumpInstruction::execute(Memory& mem) const {
  if (mode == Mode::label) {
    mem.program_counter = operand;
  } else {
    throw InvalidMode(to_string());
  }
}

std::string JumpInstruction::to_string() const {
  return JUMP_INSTRUCTION_ID + std::string(" ") + std::to_string(operand);
}

