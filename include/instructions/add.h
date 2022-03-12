/**
 * @file add.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <string>
#include "./instruction.h"
#include "../memory.h"

class AddInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};