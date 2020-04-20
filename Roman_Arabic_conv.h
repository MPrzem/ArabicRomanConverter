#ifndef Roman_Arabic_conv
#define Roman_Arabic_conv
#include <string>
#include <array>

class RomanArabicConverter {

std::string take_roman_thousands(int* number);

std::string  roman_translate(std::array<std::string, 9> LUT, int multipler, int* number);
public:
std::string to_Roman(int arabic);

int arabic_translate(std::string& roman, std::array<std::string, 9> LUT, int multipler);
int to_Arabic(std::string roman);
};



#endif // !Roman_Arabic_conv
