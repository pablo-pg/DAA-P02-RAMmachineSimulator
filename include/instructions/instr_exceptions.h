/**
 * @file instr_exceptions.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INSTRUCTIONS_INSTR_EXCEPTIONS_H_
#define INSTRUCTIONS_INSTR_EXCEPTIONS_H_

#include <string>
#include <fstream>
#include "../macros.h"

class InvalidInstruction: public std::exception {
 protected:
  mutable std::string message;
 public:
  explicit InvalidInstruction(const std::string& s);
};

class InvalidMode: public InvalidInstruction {
  using InvalidInstruction::InvalidInstruction;
 public:
  const char* what() const noexcept;
};

class InvalidStore: public InvalidInstruction {
  using InvalidInstruction::InvalidInstruction;
 public:
  const char* what() const noexcept;
};

class InvalidRead: public InvalidInstruction {
  using InvalidInstruction::InvalidInstruction;
 public:
  const char* what() const noexcept;
};

class InvalidInput: public InvalidInstruction {
  using InvalidInstruction::InvalidInstruction;
 public:
  const char* what() const noexcept;
};

class InvalidWrite: public InvalidInstruction {
  using InvalidInstruction::InvalidInstruction;
 public:
  const char* what() const noexcept;
};

class DivisionByZero: public InvalidInstruction {
  using InvalidInstruction::InvalidInstruction;
 public:
  const char* what() const noexcept;
};


#endif  // INSTRUCTIONS_INSTR_EXCEPTIONS_H_

