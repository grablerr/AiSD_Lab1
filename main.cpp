#include<Polynomial.cpp>
#include<iostream>
using namespace std;
using namespace polynomials;

int main() {
	auto pol2 = Polynomial<int>(3);
	auto pol4 = Polynomial<int>(3);
	auto pol3 = Polynomial<float>(5);

	pol2[0] = 1;
	pol2[1] = 2;
	pol2[2] = 3;

	pol3[0] = 1.2f;
	pol3[1] = 2.2f;
	pol3[2] = 3.2f;

	pol4[0] = 1;
	pol4[1] = 3;
	pol4[2] = 2;

	cout << "Int pol2 = " << pol2 << endl;
	cout << endl;
	cout << "Compute in pol2 x = 5 : " << pol2.compute(5) << endl;
	cout << "Int pol2 * 2 = " << pol2 * 2 << endl;
	cout << "2 * Int pol2 = " << 2 * pol2 << endl;
	cout << endl;
	cout << "Float pol 3 = " << pol3 << endl;
	cout << "Shrinked pol3 = " << pol3.shrink_to_fit() << endl;
	cout << "Setted pol3 = " << pol3.set(5.5f,100) << endl;
	cout << endl;
	cout << "Pol4 - " << pol4 << endl;
	cout << "Roots in pol4 - " << root_search(pol4) << endl;
	cout << endl;
	cout << "Try to search roots in pol2 = " << pol2 << endl;
	try {
		cout << root_search(pol2) << endl;
	}
	catch (...) { cout << "No real roots in pol2"; }
	cout << endl;
}

