/**
 * @file macros.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MACROS_H_
#define MACROS_H_

#include <string>

/****************************** INSTRUCTIONS *********************************/

#define LOAD_INSTRUCTION_ID std::string("load")
#define STORE_INSTRUCTION_ID std::string("store")
#define ADD_INSTRUCTION_ID std::string("add")
#define SUB_INSTRUCTION_ID std::string("sub")
#define MULT_INSTRUCTION_ID std::string("mult")
#define DIV_INSTRUCTION_ID std::string("div")
#define READ_INSTRUCTION_ID std::string("read")
#define WRITE_INSTRUCTION_ID std::string("write")
#define JUMP_INSTRUCTION_ID std::string("jump")
#define JGTZ_INSTRUCTION_ID std::string("jgtz")
#define JZERO_INSTRUCTION_ID std::string("jzero")
#define HALT_INSTRUCTION_ID std::string("halt")
#define INMEDIATE_MODE_SYMBOL "="
#define INDIRECT_MODE_SYMBOL "*"
#define LABEL_SYMBOL ":"
#define COMMENT_SYMBOL ";"
#define ACCUMULATOR_REG 0

enum Mode { inmediate, direct, indirect, label, halt };


#endif  // MACROS_H_
