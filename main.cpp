#include <iostream>
#include "Roman_Arabic_conv.h"

int main() {
    RomanArabicConverter conv;

    std::cout << conv.to_Roman(1728);
    return 0;
}
