#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../Lab_05_3/Lab_05_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_G_GreaterOrEqualOne)
        {
            double x = 1.5;
            double expected = std::sin(1.5) / (std::cos(1.5) + 2);
            double actual = g(x);

            Assert::AreEqual(expected, actual, 0.00001);
        }

        TEST_METHOD(Test_G_Zero)
        {
            double x = 0.0;
            double expected = 1.0;
            double actual = g(x);

            Assert::AreEqual(expected, actual, 0.00001);
        }

        TEST_METHOD(Test_G_LessThanOne)
        {
            double x = 0.5;

            double expected = 1.0
                + std::pow(0.5, 2) / 1.0
                + std::pow(0.5, 4) / 2.0
                + std::pow(0.5, 6) / 6.0
                + std::pow(0.5, 8) / 24.0
                + std::pow(0.5, 10) / 120.0
                + std::pow(0.5, 12) / 720.0;

            double actual = g(x);

            Assert::AreEqual(expected, actual, 0.00001);
        }
    };
}