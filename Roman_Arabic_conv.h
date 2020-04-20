#ifndef Roman_Arabic_conv
#define Roman_Arabic_conv
#include <string>
#include <array>


 std::array<std::string, 9> unitsLUT{{ "I", "II", "III","IV","V","VI","VII","VIII","IX" } };
 std::array<std::string, 9> tensLUT{ { "X", "XX", "XXX","XL","L","LX","LXX","LXXX","XC" } };
 std::array<std::string, 9> hundredsLUT{ { "C", "CC", "CCC","CD","D","DC","DCC","DCCC","CM" } };
 std::array<std::string, 4> thousandsLUT{ { "M", "MM","MMM" } };
std::array<std::string, 9> LUTs[3] =  {hundredsLUT,tensLUT,unitsLUT} ;



 std::string take_roman_thousands(int *number) {

     const int thousand = *number / 1000;
     *number %= 1000;
     const bool is_500 = (bool)*number / 500;

     if (thousand == 0)
         return "";
     else if (thousand == 1 && is_500)
         return "MD";
     return thousandsLUT[thousand];
 }

 std::string  roman_translate(std::array<int, 9> LUT, int multipler, int *number ) {

     const int index = *number / multipler;
     *number %= multipler;
     if (index > 0)
         return LUT[index];
     else
         return "";

 }
 std::string to_Roman(int arabic) {

     std::string roman = take_roman_thousands(&arabic);
     for (unsigned char i = 0; i < 3; ++i) {

         roman += roman_translate(LUTs[i], 10 ^ i);
     }
         


 }






#endif // !Roman_Arabic_conv
