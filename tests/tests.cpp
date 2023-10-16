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
//
//TEST(SequenceTests, SquareTest1) {
//
//    auto const Square1 = make_shared<SquareSequence>(2, 1);
//    auto const Square2 = make_shared<SquareSequence>(4, 2);
//    auto const Square3 = make_shared<SquareSequence>(6, 4);
//
//    EXPECT_EQ(Square1->compute_nth(), 5);
//    EXPECT_EQ(Square2->compute_nth(), 18);
//    EXPECT_EQ(Square3->compute_nth(), 40);
//}
//
//TEST(SequenceTests, SquareTest2) {
//
//    auto const Square1 = make_shared<SquareSequence>(3, 4);
//    auto const Square2 = make_shared<SquareSequence>(5, 3);
//    auto const Square3 = make_shared<SquareSequence>(7, 9);
//
//    EXPECT_EQ(Square1->compute_nth(), 13);
//    EXPECT_EQ(Square2->compute_nth(), 28);
//    EXPECT_EQ(Square3->compute_nth(), 58);
//}
//
//TEST(SequenceTests, SquareTest3) {
//
//    auto const Square1 = make_shared<SquareSequence>(1, -2);
//    auto const Square2 = make_shared<SquareSequence>(2, -3);
//    auto const Square3 = make_shared<SquareSequence>(5, -6);
//
//    EXPECT_EQ(Square1->compute_nth(), -1);
//    EXPECT_EQ(Square2->compute_nth(), 1);
//    EXPECT_EQ(Square3->compute_nth(), 19);
//}
//
//TEST(SequenceTests, FactorialTest0) {
//
//    auto const Factorial1 = make_shared<FactSequence>(0);
//
//    EXPECT_EQ(Factorial1->compute_nth(), 1);
//}
//
//TEST(SequenceTests, FactorialTest1) {
//
//    auto const Factorial1 = make_shared<FactSequence>(1);
//
//    EXPECT_EQ(Factorial1->compute_nth(), 1);
//}
//
//TEST(SequenceTests, FactorialTest4) {
//
//    auto const Factorial1 = make_shared<FactSequence>(4);
//
//    EXPECT_EQ(Factorial1->compute_nth(), 24);
//}
//
//TEST(SequenceTests, FactorialTest5) {
//
//    auto const Factorial1 = make_shared<FactSequence>(5);
//
//    EXPECT_EQ(Factorial1->compute_nth(), 120);
//}
//
//TEST(SequenceTests, SetShiftTest1) {
//
//    auto const Square1 = make_shared<SquareSequence>(1, 6);
//    Square1->set_shift(8);
//
//    int r1 = Square1->get_shift();
//
//    EXPECT_EQ(r1, 8);
//}
//
//TEST(SequenceTests, SetShiftTest2) {
//
//    auto const Square1 = make_shared<SquareSequence>(1, 6);
//    Square1->set_shift(-5);
//
//    int r1 = Square1->get_shift();
//
//    EXPECT_EQ(r1, -5);
//}
//

