/**
 * @file main.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
  #include <windows.h>
  #error No se pudo compilar en Windows
#endif  // Si se compila en Windows

#if defined(__APPLE__) && defined(__MACH__)
  #error No se pudo compilar en iOS
#endif


#include <iostream>
#include "../include/miscellany.h"


int main() {
  std::cout << "Hello World" << std::endl;
}
