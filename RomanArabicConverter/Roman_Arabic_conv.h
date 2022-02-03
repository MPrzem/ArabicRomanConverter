#pragma once
#include <array>

class RomanArabicConverter {
    std::array<std::string, 9> unitsLUT{ { "I", "II", "III","IV","V","VI","VII","VIII","IX" } };
    std::array<std::string, 9> tensLUT{ { "X", "XX", "XXX","XL","L","LX","LXX","LXXX","XC" } };
    std::array<std::string, 9> hundredsLUT{ { "C", "CC", "CCC","CD","D","DC","DCC","DCCC","CM" } };
    std::array<std::string, 4> thousandsLUT{ { "M", "MM","MMM","MMMM" } };
    std::array<std::string, 9> LUTs[3] = { hundredsLUT,tensLUT,unitsLUT };

    std::string roman_thousands_translate(int* number);
    std::string  roman_translate(std::array<std::string, 9> LUT, int multipler, int* number);

    template<std::size_t SIZE>
    int arabic_translate(std::string& roman, std::array<std::string, SIZE> LUT, int multipler);

    public:
    std::string to_Roman(int arabic);
    int to_Arabic(std::string roman);
};
