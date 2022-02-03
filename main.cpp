#include <iostream>
#include "Roman_Arabic_conv.h"

int main()
{
    RomanArabicConverter conv;
    std::cout << conv.to_Arabic("MMMDCCCLXXXVIII") << std::endl;
    std::cout << conv.to_Roman(3888);
    return 0;
}
