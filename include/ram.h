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
#include "./memory.h"
#include "./instructions/include_instr.h"

class RAM {
 public:
  RAM(const std::vector<Instruction*>& instructions,
    std::fstream& input, std::fstream& output, int debug);
  ~RAM();
  int execute();
  const std::vector<Instruction*>& getInstructions() const;

 protected:
  int instructions_executed;
  Memory memory;
  std::vector<Instruction*> instructions;
};


#endif  // RAM_H_
