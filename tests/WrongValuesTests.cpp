#include <gtest/gtest.h>
#include "Roman_Arabic_conv.h"


class WrongInputValuesTestsR2A : public ::testing::TestWithParam<std::string> {
};

class WrongInputValuesTestsA2R : public ::testing::TestWithParam<int> {
};



TEST_P(WrongInputValuesTestsR2A, ShouldConvertToCorrectRoman) {
    std::string input = GetParam();
    RomanArabicConverter converter;
    auto result = converter.to_Arabic(input);
    ASSERT_EQ(result,-1);
}

TEST_P(WrongInputValuesTestsA2R, ShouldConvertToCorrectArabic) {
    int input = GetParam();
    RomanArabicConverter converter;
    auto result = converter.to_Roman(input);
    ASSERT_STREQ(result.c_str(),"");
}


TEST(CoverterWrongValuesTests,ShouldThrowWhenNull){
    RomanArabicConverter converter;
    ASSERT_THROW(converter.to_Arabic(nullptr),std::logic_error);
}



INSTANTIATE_TEST_CASE_P(WrongValuesR2A, WrongInputValuesTestsR2A, ::testing::Values(
    "test",
    "i",
    "-X",
    "5"
));

INSTANTIATE_TEST_CASE_P(WrongValuesA2R, WrongInputValuesTestsA2R, ::testing::Values(
    -1,
    -5,
    5000,
    682123
));