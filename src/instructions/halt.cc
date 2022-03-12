/**
 * @file halt.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/halt.h"


void HaltInstruction::execute(Memory& mem) const {
  throw ExecutionEnd();
}

std::string HaltInstruction::to_string() const {
  return HALT_INSTRUCTION_ID;
}
