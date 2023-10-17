#include<Polynomial.cpp>
#include<iostream>
using namespace std;
using namespace polynomials;

int main() {
	auto pol1 = Polynomial<complex<float>>(3);
	auto pol2 = Polynomial<int>(3);
	auto pol3 = Polynomial<float>(3);
	complex<double> CN1(3.3f, 1.9f);
	complex<double> CN2(4.6f, 2.7f);
	complex<double> CN3(4.9f, 7.2f);

	pol1[0] = CN1;
	pol1[1] = CN2;
	pol1[2] = CN3;

	pol2[0] = 1;
	pol2[1] = 2;
	pol2[2] = 3;

	pol3[0] = 1.2f;
	pol3[1] = 2.2f;
	pol3[2] = 3.2f;

	cout<< "Complex<float> pol1 = " << pol1 << endl;
	cout<< "Int pol2 = " << pol2 << endl;
	cout << "Int pol2 *2 = " << pol2 * 2 << endl;
	cout << "2 * Int pol2 = " << 2 * pol2 << endl;
	cout << "Float pol 3 = " << pol3 << endl;
	cout << "2.5 * Int pol3 = " << 2.5f * pol3 << endl;

	cout << root_search(pol1) << endl;

	try {
		cout << root_search(pol2) << endl;
	}
	catch (...) { cout << "No real roots"; }
}

