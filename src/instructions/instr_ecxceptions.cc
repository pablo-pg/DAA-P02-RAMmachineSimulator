/**
 * @file instr_ecxceptions.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/instructions/instr_exceptions.h"


InvalidInstruction::InvalidInstruction(const std::string& s) {
  message = s;
}

const char* InvalidMode::what() const noexcept {
  message = std::string("This instruction has an invalid mode: ") + message;
  return message.c_str();
}

const char* InvalidStore::what() const noexcept {
  message = std::string("The STORE instruction can't be used with an inmediate operand")
    + message;
  return message.c_str();
}

const char* InvalidRead::what() const noexcept {
  message = std::string("The READ instruction can't be used with an inmediate operand")
    + message;
  return message.c_str();
}

const char* InvalidInput::what() const noexcept {
  message = std::string("The READ instruction read something invalid: ")
    + message;
  return message.c_str();
}

const char* InvalidWrite::what() const noexcept {
  message = std::string("The WRITE instruction can't be used to write the content of the accumulator: ")
    + message;
  return message.c_str();
}

const char* DivisionByZero::what() const noexcept {
  message = std::string("Can't divide by zero! Happened in instruction: ")
    + message;
  return message.c_str();
}
