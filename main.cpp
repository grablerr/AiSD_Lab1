#include<Polynomial.cpp>
#include<iostream>
using namespace std;
using namespace polynomials;




int main() {
	Polynomial<int> pol1(7);

	pol1[0] = 1;
	pol1[1] = 2;
	pol1[2] = 3;

	cout << pol1 << endl;

	pol1.shrink_to_fit();

	cout << pol1 << endl;

	pol1.expand(5);

	cout << pol1 << endl;

}
