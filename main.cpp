#include <iostream>
#include "Roman_Arabic_conv.h"

int main() {
    RomanArabicConverter conv;

    std::string roman = "MMMDCCCLXXXVIII";

   std::cout<< conv.to_Arabic(roman);
   std::string tmp = conv.to_Roman(3888);
    std::cout << conv.to_Roman(3888);
    return 0;
}
