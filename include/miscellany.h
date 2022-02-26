/**
 * @file miscenally.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief Espacio de nombres genérico para imprimir con colores y emojis
 * @version 0.2
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 * Usage:
 *  std::cout << bold << "Hello World" << reset;
 *  std::cout << bold << green << "Hello" << reset << underline << " World" << reset;
 *  std::cout << Emoji::smile;
 */

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
  #include <windows.h>
  #error No se pudo compilar en Windows
#endif  // Si se compila en Windows

#if defined(__APPLE__) && defined(__MACH__)
  #error No se pudo compilar en iOS
#endif


#ifndef MISCELLANY_H_
#define MISCELLANY_H_


#include <ostream>


// Sacado de https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
namespace Colour {
enum Code {
    RESET = 0,
    BOLD = 1,
    UNDERLINE = 4,

    FG_WHITE = 37,
    FG_BLACK = 30,
    FG_RED,
    FG_GREEN,
    FG_YELLOW,
    FG_BLUE,
    FG_MAGENTA,
    FG_CYAN,

    FG_B_WHITE = 97,
    FG_B_BLACK = 90,
    FG_B_RED,
    FG_B_GREEN,
    FG_B_YELLOW,
    FG_B_BLUE,
    FG_B_MAGENTA,
    FG_B_CYAN,
};

class ModCol {
 public:
  explicit ModCol(Code pCode) : code_(pCode) {}
  friend std::ostream& operator<<(std::ostream& os, const ModCol& mod) {
    return os << "\033[" << mod.code_ << "m";
  }
 private:
  Code code_;
};
};  // namespace Colour


Colour::ModCol bold(Colour::Code::BOLD);
Colour::ModCol underline(Colour::Code::UNDERLINE);
Colour::ModCol reset(Colour::Code::RESET);

Colour::ModCol red(Colour::Code::FG_RED);
Colour::ModCol green(Colour::Code::FG_GREEN);
Colour::ModCol blue(Colour::Code::FG_BLUE);


namespace Emoji {  // Sacado de https://emojipedia.org/
  const char* smile = "\U0001F600";   // 😀
  const char* smile2 = "\U0001F601";  // 😁
  const char* laught = "\U0001F602";  // 😂
  const char* cool = "\U0001F60E";    // 😎
};  // namespace Emoji


#endif  // MISCELLANY_H_
