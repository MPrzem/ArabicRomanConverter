#include <iostream>
#include "Roman_Arabic_conv.h"

int main() {
    RomanArabicConverter conv;
    std::array<std::string, 9> unitsLUT{ { "I", "II", "III","IV","V","VI","VII","VIII","IX" } };
    std::string X = "I";
   std::cout<< conv.arabic_translate(X, unitsLUT, 1);

    std::cout << conv.to_Roman(1728);
    return 0;
}
