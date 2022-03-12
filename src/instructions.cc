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

#include "../include/instructions/include_instr.h"

InvalidInstruction::InvalidInstruction(const std::string& s) {
  message = s;
}

const char* InvalidMode::what() const noexcept {
  message = std::string("This instruction has an invalid mode: ") + message;
  return message.c_str();
}

const char* InvalidStore::what() const noexcept {
  message = std::string("The STORE instruction can't be used with an inmediate operand")
    + message;
  return message.c_str();
}

const char* InvalidRead::what() const noexcept {
  message = std::string("The READ instruction can't be used with an inmediate operand")
    + message;
  return message.c_str();
}

const char* InvalidInput::what() const noexcept {
  message = std::string("The READ instruction read something invalid: ")
    + message;
  return message.c_str();
}

const char* InvalidWrite::what() const noexcept {
  message = std::string("The WRITE instruction can't be used to write the content of the accumulator: ")
    + message;
  return message.c_str();
}

const char* DivisionByZero::what() const noexcept {
  message = std::string("Can't divide by zero! Happened in instruction: ")
    + message;
  return message.c_str();
}

const char* ExecutionEnd::what() const noexcept {
  return "The execution finished succesfully";
}

Instruction::Instruction(int operand, Mode mode) {
  this->operand = operand;
  this->mode = mode;
}

std::string mode_to_string(Mode mode) {
  switch (mode) {
  case Mode::inmediate:
    return INMEDIATE_MODE_SYMBOL;
    break;
  case Mode::indirect:
    return INDIRECT_MODE_SYMBOL;
    break;
  case Mode::direct:
  case Mode::label:
  case Mode::halt:
    break;
  }
  return "";
}

void LoadInstruction::execute(Memory& mem) const {
  int value;
  switch (mode) {
  case Mode::inmediate:
    mem.registers[ACCUMULATOR_REG] = operand;
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    value = mem.registers[operand];
    mem.registers[ACCUMULATOR_REG] = value;
    break;
  case Mode::indirect:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    value = mem.registers[mem.registers[operand]];
    mem.registers[ACCUMULATOR_REG] = value;
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string LoadInstruction::to_string() const {
  return LOAD_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}

void StoreInstruction::execute(Memory& mem) const {
  int value;
  switch (mode) {
  case Mode::inmediate:
    throw InvalidStore(to_string());
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    value = mem.registers[ACCUMULATOR_REG];
    mem.registers[operand] = value;
    break;
  case Mode::indirect:
    value = mem.registers[ACCUMULATOR_REG];
    mem.registers[mem.registers[operand]] = value;
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string StoreInstruction::to_string() const {
  return STORE_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}

void AddInstruction::execute(Memory& mem) const {
  int value;
  switch (mode) {
  case Mode::inmediate:
    mem.registers[ACCUMULATOR_REG] += operand;
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    value = mem.registers[operand];
    mem.registers[ACCUMULATOR_REG] += value;
    break;
  case Mode::indirect:
    value = mem.registers[mem.registers[operand]];
    mem.registers[ACCUMULATOR_REG] += value;
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string AddInstruction::to_string() const {
  return ADD_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}

void SubInstruction::execute(Memory& mem) const {
  int value;
  switch (mode) {
  case Mode::inmediate:
    mem.registers[ACCUMULATOR_REG] -= operand;
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    value = mem.registers[operand];
    mem.registers[ACCUMULATOR_REG] -= value;
    break;
  case Mode::indirect:
    value = mem.registers[mem.registers[operand]];
    mem.registers[ACCUMULATOR_REG] -= value;
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string SubInstruction::to_string() const {
  return SUB_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}

void MultInstruction::execute(Memory& mem) const {
  int value;
  switch (mode) {
  case Mode::inmediate:
    mem.registers[ACCUMULATOR_REG] *= operand;
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    value = mem.registers[operand];
    mem.registers[ACCUMULATOR_REG] *= value;
    break;
  case Mode::indirect:
    value = mem.registers[mem.registers[operand]];
    mem.registers[ACCUMULATOR_REG] *= value;
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string MultInstruction::to_string() const {
  return MULT_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}

void DivInstruction::execute(Memory& mem) const {
  int value;
  switch (mode) {
  case Mode::inmediate:
    if (operand == 0) {
      throw DivisionByZero(to_string());
    }
    mem.registers[ACCUMULATOR_REG] /= operand;
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    if (mem.registers[operand] == 0) {
      throw DivisionByZero(to_string());
    }
    value = mem.registers[operand];
    mem.registers[ACCUMULATOR_REG] /= value;
    break;
  case Mode::indirect:
    if (mem.registers[mem.registers[operand]] == 0) {
      throw DivisionByZero(to_string());
    }
    value = mem.registers[mem.registers[operand]];
    mem.registers[ACCUMULATOR_REG] /= value;
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string DivInstruction::to_string() const {
  return DIV_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand); 
}

int read_number(std::fstream& input) {
  std::string number_str;
  std::getline(input, number_str);
  int number;
  try {
    number = std::stoi(number_str);
  } catch(std::exception& e) {
    throw InvalidInput(number_str);
  }
  return number;
}

void ReadInstruction::execute(Memory& mem) const {
  switch (mode) {
  case Mode::inmediate:
    throw InvalidRead(to_string());
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    mem.registers[operand] = read_number(mem.input);
    break;
  case Mode::indirect:
    mem.registers[mem.registers[operand]] = read_number(mem.input);
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string ReadInstruction::to_string() const {
  return READ_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}

void WriteInstruction::execute(Memory& mem) const {
  switch (mode) {
  case Mode::inmediate:
    mem.output << operand << "\n";
    break;
  case Mode::direct:
    if ((size_t)operand >= mem.registers.size()) {
      mem.registers.resize(mem.registers.size() + 1);
    }
    if (operand == ACCUMULATOR_REG) {
      throw InvalidWrite(to_string());
    }
    mem.output << mem.registers[operand] << "\n";
    break;
  case Mode::indirect:
    mem.output << mem.registers[mem.registers[operand]] << "\n";
    break;
  default:
    throw InvalidMode(to_string());
  }
  mem.program_counter += 1;
}

std::string WriteInstruction::to_string() const {
  return WRITE_INSTRUCTION_ID + std::string(" ") +
   mode_to_string(mode) + std::to_string(operand);
}

void JumpInstruction::execute(Memory& mem) const {
  if (mode == Mode::label) {
    mem.program_counter = operand;
  } else {
    throw InvalidMode(to_string());
  }
}

std::string JumpInstruction::to_string() const {
  return JUMP_INSTRUCTION_ID + std::string(" ") + std::to_string(operand);
}

void JGTZInstruction::execute(Memory& mem) const {
  if (mode == Mode::label) {
    if (mem.registers[ACCUMULATOR_REG] > 0) {
      mem.program_counter = operand;
    } else {
      mem.program_counter += 1;
    }
  } else {
    throw InvalidMode(to_string());
  }
}

std::string JGTZInstruction::to_string() const {
  return JGTZ_INSTRUCTION_ID + std::string(" ") + std::to_string(operand);
}

void JZeroInstruction::execute(Memory& mem) const {
  if (mode == Mode::label) {
    if (mem.registers[ACCUMULATOR_REG] == 0) {
      mem.program_counter = operand;
    } else {
      mem.program_counter += 1;
    }
  } else {
    throw InvalidMode(to_string());
  }
}

std::string JZeroInstruction::to_string() const {
  return JZERO_INSTRUCTION_ID + std::string(" ") + std::to_string(operand);
}

void JParInstruction::execute(Memory& mem) const {
  if (mode == Mode::label) {
    if (mem.registers[ACCUMULATOR_REG] % 2 == 0) {
      mem.program_counter = operand;
    } else {
      mem.program_counter += 1;
    }
  } else {
    throw InvalidMode(to_string());
  }
}

std::string JParInstruction::to_string() const {
  return JPAR_INSTRUCTION_ID + std::string(" ") + std::to_string(operand);
}

void HaltInstruction::execute(Memory& mem) const {
  throw ExecutionEnd();
}

std::string HaltInstruction::to_string() const {
  return HALT_INSTRUCTION_ID;
}
