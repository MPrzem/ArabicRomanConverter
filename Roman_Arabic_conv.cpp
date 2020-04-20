#include "Roman_Arabic_conv.h"

    std::array<std::string, 9> unitsLUT{ { "I", "II", "III","IV","V","VI","VII","VIII","IX" } };
    std::array<std::string, 9> tensLUT{ { "X", "XX", "XXX","XL","L","LX","LXX","LXXX","XC" } };
    std::array<std::string, 9> hundredsLUT{ { "C", "CC", "CCC","CD","D","DC","DCC","DCCC","CM" } };
    std::array<std::string, 4> thousandsLUT{ { "M", "MM","MMM" } };
    std::array<std::string, 9> LUTs[3] = { hundredsLUT,tensLUT,unitsLUT };



    inline std::string RomanArabicConverter::take_roman_thousands(int* number) {

        const int thousand = *number / 1000;
        *number %= 1000;
        const bool is_500 = (bool)(*number / 500);

        if (thousand == 0)
            return "";
     //   else if (thousand == 1 && is_500)
       //     return "MD";
        return thousandsLUT[thousand - 1];
    }

    inline std::string RomanArabicConverter::roman_translate(std::array<std::string, 9> LUT, int multipler, int* number) {

        const int index = *number / multipler;
        *number %= multipler;
        if (index > 0)
            return LUT[index - 1];
        else
            return "";

    }
    std::string RomanArabicConverter::to_Roman(int arabic) {

        std::string roman = take_roman_thousands(&arabic);
        int multipler = 100;
        for (unsigned char i = 0; i < 3; ++i) {

            roman += roman_translate(LUTs[i], multipler, &arabic);
            multipler /= 10;
        }
        return roman;

    }
