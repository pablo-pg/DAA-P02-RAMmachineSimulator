/**
 * @file memory.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#include <sstream>
#include <string>
#include <vector>

struct Memory {
  unsigned int program_counter = 0;
  std::vector<int> registers;
  std::stringstream input;
  std::stringstream output;
};


#endif  // MEMORY_H_

