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

// #include <iostream>
#include <string>
#include <fstream>
#include "./macros.h"
#include "./memory.h"

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

class ExecutionEnd: public std::exception {
 public:
  const char* what() const noexcept;
};


std::string mode_to_string();

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

class LoadInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class StoreInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class AddInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class SubInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class MultInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class DivInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class ReadInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class WriteInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class JumpInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class JGTZInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class JZeroInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};

class HaltInstruction : public Instruction {
 public:
  using Instruction::Instruction;
  void execute(Memory& mem) const;
  std::string to_string() const;
};
#endif  // INSTRUCTION_H_
