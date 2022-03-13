/**
 * @file ram.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RAM_H_
#define RAM_H_

#include <vector>
#include "./instructions/include_instr.h"
#include "./memory.h"

class RAM {
 public:
  RAM(const std::vector<Instruction*>& instructions,
    std::fstream& input, std::fstream& output, int debug, 
    std::vector<std::string> str_input);
  ~RAM();
  int execute();
  const std::vector<Instruction*>& getInstructions() const;

 protected:
  int instructions_executed;
  bool debug;
  Memory memory;
  std::vector<std::string> str_input;
  std::vector<std::string> str_output;
  std::vector<Instruction*> instructions;
};


#endif  // RAM_H_
