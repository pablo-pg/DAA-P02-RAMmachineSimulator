/**
 * @file instruction.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.2
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/instructions/include_instr.h"



const char* ExecutionEnd::what() const noexcept {
  return "The execution finished succesfully";
}

Instruction::Instruction(int operand, Mode mode) {
  this->operand = operand;
  this->mode = mode;
}

std::string mode_to_string(Mode mode) {
  switch (mode) {
  case Mode::inmediate:
    return INMEDIATE_MODE_SYMBOL;
    break;
  case Mode::indirect:
    return INDIRECT_MODE_SYMBOL;
    break;
  case Mode::direct:
  case Mode::label:
  case Mode::halt:
    break;
  }
  return "";
}

