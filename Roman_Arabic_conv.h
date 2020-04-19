#ifndef Roman_Arabic_conv
#define Roman_Arabic_conv
#include <string>
#include <array>

 std::array<std::string, 9> unitsLUT{{ "I", "II", "III","IV","V","VI","VII","VIII","IX" } };
 std::array<std::string, 9> tenssLUT{ { "X", "XX", "XXX","XL","L","LX","LXX","LXXX","XC" } };
 std::array<std::string, 9> unitsLUT{ { "C", "CC", "CCC","CD","D","DC","DCC","DCCC","CM" } };
 std::array<std::string, 4> unitsLUT{ { "M", "MD", "MM","MMM" } };


#endif // !Roman_Arabic_conv
