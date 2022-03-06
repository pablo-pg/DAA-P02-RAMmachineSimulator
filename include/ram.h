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


#include "include/memory.h"
#include "include/instruction.h"

class RAM {
 protected:
  Memory memory;
  std::vector<Instruction*> instructions;
};


#endif  // RAM_H_
