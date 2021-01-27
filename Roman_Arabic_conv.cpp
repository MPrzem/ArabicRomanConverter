#include "Roman_Arabic_conv.h"

    inline std::string RomanArabicConverter::take_roman_thousands(int* number) {

        const size_t thousand = *number / 1000;
        *number %= 1000;

        if (thousand == 0||thousand>4)
            return "";
        return thousandsLUT[thousand - 1];
    }

    inline std::string RomanArabicConverter::roman_translate(std::array<std::string, 9> LUT, int multipler, int* number) {

        const size_t index = *number / multipler;
        *number %= multipler;
        if (index > 0 && index<9)
            return LUT[index - 1];
        else
            return "";

    }
    std::string RomanArabicConverter::to_Roman(int arabic) {
        if (arabic < 5000) {
            std::string roman = take_roman_thousands(&arabic);
            int multipler = 100;
            for (unsigned char i = 0; i < 3; ++i) {

                roman += roman_translate(LUTs[i], multipler, &arabic);
                multipler /= 10;
            }
            if (arabic != 0)
                return "";// Ten fragment nigdy nie powinien być osiągnięty, ozacza to ze nie wszystkie cyfry mogły być odkodowane
            return roman;
        }
        else return "";//Liczba zbyt duża dla podstawowej wersji systemu rzymskiego
    }
    int RomanArabicConverter::to_Arabic(std::string roman) {


        int multipler = 100;
        int arabic =  arabic_translate(roman, thousandsLUT, 1000);
        for (unsigned char i = 0; i < 3; ++i) {

            arabic += arabic_translate(roman,LUTs[i], multipler);
            multipler /= 10;
        }
        if (roman != "")
            return -1;//error nie wszystkie znaki udało się rozkodować
        return arabic;
    }




    template<std::size_t SIZE>
    int RomanArabicConverter::arabic_translate(std::string& roman, std::array<std::string, SIZE> LUT, int multipler) {
        int rom_length = roman.length();
        int elem_lenth;
        for (int i = LUT.size()-1; i >=0 ; i--) {
            elem_lenth = LUT[i].length();
            if(rom_length >= elem_lenth)
            if (roman.compare(0, elem_lenth, LUT[i]) == 0) {
                roman = roman.substr(elem_lenth, rom_length);
                return (i+1) * multipler;
            }
        }
        return 0;

    }


