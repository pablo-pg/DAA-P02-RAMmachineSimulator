/**
 * @file ram_generator.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RAM_GENERATOR_H_
#define RAM_GENERATOR_H_

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include "./macros.h"
#include "./ram.h"

class InputAlreadySet: public std::exception {
 public:
  const char* what() const noexcept;
};

class OutputAlreadySet: public std::exception {
 public:
  const char* what() const noexcept;
};

class InstructionsAlreadySet: public std::exception {
 public:
  const char* what() const noexcept;
};

class InputNotSet: public std::exception {
 public:
  const char* what() const noexcept;
};

class OutputNotSet: public std::exception {
 public:
  const char* what() const noexcept;
};

class InstructionsNotSet: public std::exception {
 public:
  const char* what() const noexcept;
};

class InvalidInstructionPart: public std::exception {
 protected:
  mutable std::string message;
 public:
  InvalidInstructionPart(const std::string& s);
};

class InvalidOperation: public InvalidInstructionPart {
  using InvalidInstructionPart::InvalidInstructionPart;
 public:
  const char* what() const noexcept;
};

class InvalidLabel: public InvalidInstructionPart {
  using InvalidInstructionPart::InvalidInstructionPart;
 public:
  const char* what() const noexcept;
};

class InvalidOperand: public InvalidInstructionPart {
  using InvalidInstructionPart::InvalidInstructionPart;
 public:
  const char* what() const noexcept;
};

class InvalidDebug: public std::exception {
 public:
  const char* what() const noexcept;
};

class DebugNoSet: public std::exception {
 public:
  const char* what() const noexcept;
};


class RAMBuilder {
 public:
  RAMBuilder();
  RAM* build(std::vector<std::string> str_input);
  void read_instructions_from(std::fstream& input);
  void set_input_stream(std::fstream& input);
  void set_output_stream(std::fstream& input);
  void set_debug(int debug_mode);
  int get_debug() const;

 private:
  bool input_set;
  bool output_set;
  bool instructions_set;
  bool debug_set;
  int debug;
  std::vector<Instruction*> instructions;
  std::fstream input;
  std::fstream output;
  std::vector<std::string> ssinput;
  std::vector<std::string> ssoutput;
};

#endif  // RAM_GENERATOR_H_
