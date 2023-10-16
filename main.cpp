#include<Polynomial.cpp>
#include<iostream>
using namespace std;
using namespace polynomials;




int main() {
	/*Polynomial<int> pol1(3);*/
	/*Polynomial<complex<double>> pol2(7);
	Polynomial<float> pol3(3);*/
	auto pol1 = Polynomial<complex<float>>(3);
	auto pol2 = Polynomial<int>(3);
	complex<double> CN1(3.3f, 1.9f);
	complex<double> CN2(4.6f, 2.7f);
	complex<double> CN3(4.9f, 7.2f);

	pol1[0] = CN1;
	pol1[1] = CN2;
	pol1[2] = CN3;

	pol2[0] = 1;
	pol2[1] = 2;
	pol2[2] = 3;

	cout<< "Complex<float> pol1= " << pol1 << endl;
	cout<< "Int pol2= " << pol2 << endl;

	cout << root_search(pol1) << endl;

	try {
		cout << root_search(pol2) << endl;
	}
	catch (...) { cout << "No real roots"; }
	
	
	
	
	//cout << pol2 << endl;

	//pol2 = pol1;

	//cout << pol1 << endl;
	//cout << pol2 << endl;
	//pol1[0] = 1;
	//pol1[1] = 2;
	//pol1[2] = 3;

	//pol2[0] = CN1;
	//pol2[1] = CN1;
	//pol2[2] = CN1;

	//pol3[0] = 1.1f;
	//pol3[1] = 2.2f;
	//pol3[2] = 3.3f;


	//cout << pol2 << endl;
	//cout << pol3 << endl;
	

	//cout << pol1 << endl;
	//

	//pol1.shrink_to_fit();

	//cout << pol1 << endl;

	//pol1.expand(5);

	//cout << pol1 << endl;

}

