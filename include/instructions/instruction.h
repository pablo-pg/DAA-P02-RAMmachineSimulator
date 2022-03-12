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

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <iostream>
#include <string>
#include <fstream>
#include "./macros.h"
#include "./memory.h"



class ExecutionEnd: public std::exception {
 public:
  const char* what() const noexcept;
};


std::string mode_to_string(Mode);

class Instruction {
 protected:
  int operand;
  Mode mode;
 public:
  Instruction(int operand, Mode mode);
  virtual ~Instruction() = default;
  virtual void execute(Memory& mem) const = 0;
  virtual std::string to_string() const = 0;
};


#endif  // INSTRUCTION_H_
