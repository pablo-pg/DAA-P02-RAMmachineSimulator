/**
 * @file ram_generator.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "../include/ram_generator.h"

const char* InputAlreadySet::what() const noexcept {
  return "Input stream was already set";
}

const char* OutputAlreadySet::what() const noexcept {
  return "Output stream was already set";
}

const char* InstructionsAlreadySet::what() const noexcept {
  return "Instructions were already set";
}

const char* InputNotSet::what() const noexcept {
  return "Input stream wasn't set";
}

const char* OutputNotSet::what() const noexcept {
  return "Output stream wasn't set";
}

const char* InstructionsNotSet::what() const noexcept {
  return "Instructions weren't set";
}

InvalidInstructionPart::InvalidInstructionPart(const std::string& s) {
  message = s;
}

const char* InvalidOperation::what() const noexcept {
  message = std::string("INVALID INSTRUCTION: ") + message;
  return message.c_str();
}

const char* InvalidLabel::what() const noexcept {
  message = std::string("INVALID LABEL: ") + message;
  return message.c_str();
}

const char* InvalidOperand::what() const noexcept {
  message = std::string("INVALID OPERAND: ") + message;
  return message.c_str();
}

const char* InvalidDebug::what() const noexcept {
  return "The debug mode is invalid";
}

const char* DebugNoSet::what() const noexcept {
  return "Debug mode wasn't set";
}

RAMBuilder::RAMBuilder() {
  input_set = false;
  output_set = false;
  instructions_set = false;
}

std::unordered_map<std::string, int>
get_labels(std::vector<std::string>& lines) {
  std::unordered_map<std::string, int> labels;
  for (size_t i = 0; i < lines.size(); i++) {
    size_t index = lines[i].find(LABEL_SYMBOL);
    if (index == std::string::npos) {
      continue;
    }
    labels.insert({lines[i].substr(0, index), i});
    lines[i] = lines[i].substr(index + 1);
  }
  return labels;
}

void remove_spaces(std::string& string) {
  string.erase(std::remove_if(
    string.begin(),
    string.end(),
    [](unsigned char x){return std::isspace(x);}),
    string.end());
}

void remove_comments(std::string& string) {
  size_t index = string.find(COMMENT_SYMBOL);
  if (index != std::string::npos) {
    string.erase(index);
  }
}

void to_lowercase(std::string& string) {
  std::transform(
    string.begin(),
    string.end(),
    string.begin(),
    [](unsigned char c){ return std::tolower(c); });
}

std::vector<std::string> get_unparsed_instructions(std::fstream& input) {
  std::vector<std::string> unparsed_instructions;
  std::string line;
  while (!input.eof()) {
    std::getline(input, line);
    remove_spaces(line);
    remove_comments(line);
    to_lowercase(line);
    if (!line.empty()) {
      unparsed_instructions.push_back(line);
    }
  }
  return unparsed_instructions;
}

std::pair<Mode, int> parse_operand(std::string line) {
  Mode mode;
  if (line.find(INMEDIATE_MODE_SYMBOL) == 0) {
    mode = Mode::inmediate;
  } else if (line.find(INDIRECT_MODE_SYMBOL) == 0) {
    mode = Mode::indirect;
  } else {
    mode = Mode::direct;
  }
  int operand;
  try {
    if (mode == Mode::direct) {
      operand = std::stoi(line);
    } else {
      operand = std::stoi(line.substr(1));
    }
  } catch (std::exception& e) {
    throw InvalidOperand(line);
  }
  return {mode, operand};
}

int parse_label(std::string label,
                std::unordered_map<std::string, int>& labels) {
  auto key_value_iter = labels.find(label);
  if (key_value_iter == labels.end()) {
    throw InvalidLabel(label);
  }
  return std::get<int>(*key_value_iter);
}

Instruction* parse_instruction(std::string line,
                               std::unordered_map<std::string, int>& labels) {
  Mode mode;
  int operand;
  if (line.find(LOAD_INSTRUCTION_ID) == 0) {
    std::tie(mode, operand) =
      parse_operand(line.substr(LOAD_INSTRUCTION_ID.size()));
    return new LoadInstruction(operand, mode);
  } else if (line.find(STORE_INSTRUCTION_ID) == 0) {
    std::tie(mode, operand) =
      parse_operand(line.substr(STORE_INSTRUCTION_ID.size()));
    return new StoreInstruction(operand, mode);
  } else if (line.find(ADD_INSTRUCTION_ID) == 0) {
    std::tie(mode, operand) =
      parse_operand(line.substr(ADD_INSTRUCTION_ID.size()));
    return new AddInstruction(operand, mode);
  } else if (line.find(SUB_INSTRUCTION_ID) == 0) {
    std::tie(mode, operand) =
      parse_operand(line.substr(SUB_INSTRUCTION_ID.size()));
    return new SubInstruction(operand, mode);
  } else if (line.find(MULT_INSTRUCTION_ID) == 0) {
    std::tie(mode, operand) =
      parse_operand(line.substr(MULT_INSTRUCTION_ID.size()));
    return new MultInstruction(operand, mode);
  } else if (line.find(DIV_INSTRUCTION_ID) == 0) {
    std::tie(mode, operand) =
      parse_operand(line.substr(DIV_INSTRUCTION_ID.size()));
    return new DivInstruction(operand, mode);
  } else if (line.find(READ_INSTRUCTION_ID) == 0) {
    std::tie(mode, operand) =
      parse_operand(line.substr(READ_INSTRUCTION_ID.size()));
    return new ReadInstruction(operand, mode);
  } else if (line.find(WRITE_INSTRUCTION_ID) == 0) {
    std::tie(mode, operand) =
      parse_operand(line.substr(WRITE_INSTRUCTION_ID.size()));
    return new WriteInstruction(operand, mode);
  } else if (line.find(JUMP_INSTRUCTION_ID) == 0) {
    operand = parse_label(line.substr(JUMP_INSTRUCTION_ID.size()), labels);
    return new JumpInstruction(operand, Mode::label);
  } else if (line.find(JGTZ_INSTRUCTION_ID) == 0) {
    operand = parse_label(line.substr(JGTZ_INSTRUCTION_ID.size()), labels);
    return new JGTZInstruction(operand, Mode::label);
  } else if (line.find(JZERO_INSTRUCTION_ID) == 0) {
    operand = parse_label(line.substr(JZERO_INSTRUCTION_ID.size()), labels);
    return new JZeroInstruction(operand, Mode::label);
  } else if (line.find(JPAR_INSTRUCTION_ID) == 0) {               //////////////< MODI
    operand = parse_label(line.substr(JPAR_INSTRUCTION_ID.size()), labels);
    return new JParInstruction(operand, Mode::label);
  } else if (line.find(HALT_INSTRUCTION_ID) == 0) {
    return new HaltInstruction(0, Mode::halt);
  } else {
    throw InvalidOperation(line);
  }
}

std::vector<Instruction*> parse_instructions(std::vector<std::string>& lines,
                                             std::unordered_map<std::string, int>& labels) {
  std::vector<Instruction*> instructions;
  for (const std::string& s : lines) {
    instructions.push_back(parse_instruction(s, labels));
  }
  return instructions;
}

std::vector<Instruction*> get_instructions_from_file(std::fstream& input) {
  std::vector<Instruction*> instructions;
  std::vector<std::string> lines = get_unparsed_instructions(input);
  input.close();
  std::unordered_map<std::string, int> labels = get_labels(lines);
  return parse_instructions(lines, labels);
}

RAM* RAMBuilder::build() {
  if (!input_set) {
    throw InputNotSet();
  } else if (!output_set) {
    throw OutputNotSet();
  } else if (!instructions_set) {
    throw InstructionsNotSet();
  } else if (!debug_set) {
    throw DebugNoSet();
  }
  input_set = false;
  output_set = false;
  instructions_set = false;
  RAM* ram = new RAM(instructions, input, output, debug);

  return ram;
}


void RAMBuilder::read_instructions_from(std::fstream& input) {
  if (instructions_set) {
    throw InstructionsAlreadySet();
  }
  instructions = get_instructions_from_file(input);
  instructions_set = true;
}

void RAMBuilder::set_input_stream(std::fstream& input) {
  if (input_set) {
    throw InputAlreadySet();
  } else {
    this->input.swap(input);
    input_set = true;
  }
}

void RAMBuilder::set_output_stream(std::fstream& output) {
  if (output_set) {
    throw OutputAlreadySet();
  } else {
    this->output.swap(output);
    output_set = true;
  }
}

void RAMBuilder::set_debug(int debug_mode) {
  if ((debug_mode == 0) || (debug_mode == 1) || (debug_mode == 2)) {
    debug = debug_mode;
    debug_set = true;
  } else {
    throw InvalidDebug();
  }
}

int RAMBuilder::get_debug() const {
  return debug;
}


