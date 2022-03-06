/**
 * @file instruction.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <string>
#include "include/memory.h"

const std::string NUMBER_OPERAND_CHAR = "=";
const std::string INDIRECT_OPERAND_CHAR = "*";

enum opType {number, label};

struct Operand {
  opType type;
};

struct number : Operand {
  opType type = opType::number;
  double value;
};

struct label : Operand {
  opType type = opType::label;
  std::string value;
};


enum Mode {
  inmediate, direct, indirect, label
};

class Instruction {
 public:
  Instruction();
  ~Instruction();
  virtual void execute(Memory&) const;
 protected:
  Mode mode;
  Operand* operand;

};

#endif  // INSTRUCTION_H_
