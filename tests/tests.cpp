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
