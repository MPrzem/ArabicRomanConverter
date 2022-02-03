#include <gtest/gtest.h>
#include "Roman_Arabic_conv.h"

struct CorrectDataTestParameters
{
    std::string Roman;
    int Arabic;
};

class CoverterCorrectValuesTests : public ::testing::TestWithParam<CorrectDataTestParameters> {
};

TEST_P(CoverterCorrectValuesTests, ShouldConvertToCorrectRoman) {
    CorrectDataTestParameters const& parameters = GetParam();
    RomanArabicConverter converter;
    auto result = converter.to_Arabic(parameters.Roman);
    ASSERT_EQ(result,parameters.Arabic);
}

TEST_P(CoverterCorrectValuesTests, ShouldConvertToCorrectArabic) {
    CorrectDataTestParameters const& parameters = GetParam();
    RomanArabicConverter converter;
    auto result = converter.to_Roman(parameters.Arabic);
    ASSERT_STREQ(result.c_str(),parameters.Roman.c_str());
}

INSTANTIATE_TEST_CASE_P(CorrectValues, CoverterCorrectValuesTests, ::testing::Values(
    CorrectDataTestParameters{"",0},
    CorrectDataTestParameters{"I",1},
    CorrectDataTestParameters{"XV",15},
    CorrectDataTestParameters{"XXII",22},
    CorrectDataTestParameters{"DCXLII",642},
    CorrectDataTestParameters{"CMXXX",930},
    CorrectDataTestParameters{"MMDXLIII",2543},
    CorrectDataTestParameters{"MMMDCCCLXXXVIII",3888},
    CorrectDataTestParameters{"MMMCMXCIX",3999},
    CorrectDataTestParameters{"MMMMCMXCIX",4999}
));
