#include <gtest/gtest.h>

#include <Polynomial.cpp>
using namespace polynomials;
using namespace std;


TEST(PolynomialTests, OperatorAndSetTests) {
	auto polynomial_i = Polynomial<int>(3);
	polynomial_i.set(2, 1);
	polynomial_i[0] = 1;

	auto a = polynomial_i[0];
	auto b = polynomial_i[1];

	EXPECT_EQ(a, 1);
	EXPECT_EQ(b, 2);

}

TEST(PolynomialTests, OperatorsPlusMinus) {
	auto polynomial_i1 = Polynomial<int>(3);
	auto polynomial_i2 = Polynomial<int>(3);
	auto polynomial_i3 = Polynomial<int>(3);
	auto polynomial_result_plus = Polynomial<int>(3);
	auto polynomial_result_minus = Polynomial<int>(3);
	bool result_plus = false;
	bool result_minus = false;
	
	polynomial_i1[0] = 1;
	polynomial_i1[1] = 1;
	polynomial_i1[2] = 1;

	polynomial_i2[0] = 2;
	polynomial_i2[1] = 2;
	polynomial_i2[2] = 2;

	polynomial_i3[0] = 3;
	polynomial_i3[1] = 3;
	polynomial_i3[2] = 3;

	polynomial_result_plus = polynomial_i1 + polynomial_i2;
	polynomial_result_minus = polynomial_i2 - polynomial_i1;

	if (polynomial_result_plus == polynomial_i3) { result_plus = true; };
	if (polynomial_result_minus == polynomial_i1) { result_minus = true; };


	EXPECT_EQ(result_plus, true);
	EXPECT_EQ(result_minus, true);

}

TEST(PolynomialTests, OperatorsEqualNotequal) {
	auto polynomial_i1 = Polynomial<int>(3);
	auto polynomial_i2 = Polynomial<int>(3);
	auto polynomial_i3 = Polynomial<int>(3);
	bool result_equal = false;
	bool result_not_equal = false;

	polynomial_i1[0] = 1;
	polynomial_i1[1] = 1;
	polynomial_i1[2] = 1;

	polynomial_i2[0] = 2;
	polynomial_i2[1] = 2;
	polynomial_i2[2] = 2;

	polynomial_i3[0] = 2;
	polynomial_i3[1] = 2;
	polynomial_i3[2] = 2;
	
	if (polynomial_i2 == polynomial_i3) { result_equal = true; };
	if (polynomial_i2 != polynomial_i1) { result_not_equal = true; };

	EXPECT_EQ(result_equal, true);
	EXPECT_EQ(result_not_equal, true);

}

