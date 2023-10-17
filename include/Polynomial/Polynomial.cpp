#ifndef INCLUDE_Polynomial_Polynomial_H_
#define INCLUDE_Polynomial_Polynomial_H_

#include <Vector.cpp>
#include <stdexcept>
#include <cmath>
#include <complex>
#include <utility>
#include <iostream>
using namespace std;

namespace polynomials {

	template<typename T>
	class Polynomial {
		Vector<T> _coefficients;
	public:
		Polynomial();
		Polynomial(int max_level);
		Polynomial(const Vector<T>& other);

		Vector<T>& get_coeffs();
		Polynomial<T> set(T coeff, int level);
		T compute(T argument);

		Polynomial<T> operator+=(const Polynomial<T>& other);
		Polynomial<T> operator+(const Polynomial<T>& other)const;
		Polynomial<T> operator -= (const Polynomial<T>& other);
		Polynomial<T> operator-(const Polynomial<T>& other)const;
		Polynomial<T> operator*(const T num) const;
		T& operator[](int level);
		T operator[](int level) const;
		bool operator==(Polynomial<T>& other) const;
		bool operator!=(Polynomial<T>& other) const;

		Polynomial<T> shrink_to_fit();
		Polynomial<T>& operator=(Polynomial<T> other);
		Polynomial<T>& expand(int level);
		~Polynomial() = default;
		const T coeff_at(int index) const;
		friend std::ostream& operator<<(std::ostream& out, const Polynomial<T>& poly) {
			int degree = poly._coefficients.get_size() - 1;

			for (int i = degree; i >= 0; --i) {
				T coeff = poly.coeff_at(i);
				if (i < degree) {
					out << " + ";
				}
				if (i > 0) {
					out << coeff << "x^" << i;
				}
				else {
					out << coeff;
				}
			}
			return out;
		};
	};

	template<typename T>
	Polynomial<T>::Polynomial() {
		this->_coefficients = Vector<T>();
	}

	template<typename T>
	Polynomial<T>::Polynomial(int max_level) {
		this->_coefficients = Vector<T>(max_level);
	}

	template<typename T>
	Polynomial<T>::Polynomial(const Vector<T>& other) {
		_coefficients = other;
	}

	template<typename T>
	Vector<T>& Polynomial<T>::get_coeffs() {
		return _coefficients;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::set(T coeff, int level) {
		if (level < 0) { throw runtime_error("Invalid level"); }
		if (level > _coefficients.get_size()) {
			expand(level);
			_coefficients[level - 1] = coeff;
			return *this;
		}
		_coefficients[level] = coeff;
		return *this;
	}

	template<typename T>
	T Polynomial<T>::compute(T arg) {
		T sum = 0;
		for (int i = 0; i < _coefficients.get_size(); ++i) {
			sum += static_cast<T>(_coefficients[i]) * static_cast<T>(pow(arg, i));
		}
		return sum;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator+=(const Polynomial<T>& other) {
		_coefficients += other._coefficients;
		return *this;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& other) const {
		int maxSize = std::max(_coefficients.get_size(), other._coefficients.get_size());
		Polynomial<T> result(maxSize);

		for (int i = 0; i < maxSize; ++i) {
			T coeff1 = (i < _coefficients.get_size()) ? _coefficients[i] : 0;
			T coeff2 = (i < other._coefficients.get_size()) ? other._coefficients[i] : 0;

			result._coefficients[i] = coeff1 + coeff2;
		}

		return result;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator-=(const Polynomial<T>& other) {
		_coefficients -= other._coefficients;
		return *this;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& other) const {
		int maxSize = std::max(_coefficients.get_size(), other._coefficients.get_size());
		Polynomial<T> result(maxSize);

		for (int i = 0; i < maxSize; ++i) {
			T coeff1 = (i < _coefficients.get_size()) ? _coefficients[i] : 0;
			T coeff2 = (i < other._coefficients.get_size()) ? other._coefficients[i] : 0;

			result._coefficients[i] = coeff1 - coeff2;
		}

		return result;
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::operator*(T skal) const {
		int maxSize = std::max(_coefficients.get_size(), _coefficients.get_size());
		Polynomial<T> result(maxSize);

		for (int i = 0; i < maxSize; ++i) {
			T coeff1 = (i < _coefficients.get_size()) ? _coefficients[i] : 0;

			result._coefficients[i] = coeff1 * skal;
		}

		return result;
	}

	template<typename T>
	Polynomial<T> operator*(const T num, Polynomial<T>& poly) {
		int maxSize = poly.get_coeffs().get_size();
		Polynomial<T> result(maxSize);

		for (int i = 0; i < maxSize; ++i) {
			T coeff1 = (i < poly.get_coeffs().get_size()) ? poly.get_coeffs()[i] : 0;

			result.get_coeffs()[i] = coeff1 * num;
		}

		return result;
	}

	template<typename T>
	T& Polynomial<T>::operator[](int level) {
		if (level < 0 || level >= _coefficients.get_size()) {
			throw runtime_error("Invalid level");
		}
		return _coefficients[level];
	}
	template<typename T>
	T Polynomial<T>::operator[](int level) const {
		if (level < 0 || level >= _coefficients.get_size()) {
			throw runtime_error("Invalid level");
		}
		return _coefficients[level];
	}

	template<typename T>
	bool Polynomial<T>::operator==(Polynomial<T>& other) const {
		return (this->_coefficients == other._coefficients);
	}

	template<typename T>
	bool Polynomial<T>::operator!=(Polynomial<T>& other) const {
		return (this->_coefficients != other._coefficients);
	}

	template<typename T>
	Polynomial<T> Polynomial<T>::shrink_to_fit() {
		int newSize = _coefficients.get_size();

		while (newSize > 0 && _coefficients[newSize - 1] == T(0)) {
			newSize--;
		}

		Polynomial<T> result(newSize);

		for (int i = 0; i < newSize; i++) {
			result._coefficients[i] = _coefficients[i];
		}
		_coefficients = result._coefficients;
		return *this;
	}

	template<typename T>
	const T Polynomial<T>::coeff_at(int index) const {
		return _coefficients[index];
	}

	template<typename T>
	Polynomial<T>& Polynomial<T>::operator=(Polynomial<T> other) {
		std::swap(_coefficients, other._coefficients);
		return *this;
	}

	template<typename T>
	Polynomial<T>& Polynomial<T>::expand(int level) {
		Polynomial<T> temp(level);
		for (int i = 0; i < _coefficients.get_size(); ++i) {
			temp[i] = _coefficients[i];
		}
		_coefficients = temp.get_coeffs();
		return *this;
	}

	template<typename T>
	std::pair<T, T> root_search(Polynomial<T> poly) {
		if (poly.get_coeffs().get_size() < 3) {
			throw std::runtime_error("Polynomial must be of degree 2");
		}

		T c = poly[0];
		T b = poly[1];
		T a = poly[2];

		T discriminant = b * b - 4 * a * c;

		if (discriminant < 0 && (!std::is_same<T, std::complex<float>>::value || !std::is_same<T, std::complex<double>>::value)) {
			throw std::runtime_error("No real roots for non-complex data type");
		}

		T root1 = (-b + sqrt(discriminant)) / (2 * a);
		T root2 = (-b - sqrt(discriminant)) / (2 * a);

		return std::make_pair(root1, root2);
	}

	template<>
	std::pair<std::complex<float>, std::complex<float>> root_search(Polynomial<std::complex<float> > poly) {
		if (poly.get_coeffs().get_size() < 3) {
			throw runtime_error("Polynomial must be of degree 2");
		}

		complex<float> c = poly[0];
		complex<float> b = poly[1];
		complex<float> a = poly[2];

		complex<float> discriminant = b * b - 4.0f * a * c;

		complex<float> root1 = (-b + sqrt(discriminant)) / (2.0f * a);
		complex<float> root2 = (-b - sqrt(discriminant)) / (2.0f * a);

		return std::make_pair(root1, root2);
	}

	template<>
	std::pair<std::complex<double>, std::complex<double>> root_search(Polynomial<std::complex<double> > poly) {
		if (poly.get_coeffs().get_size() < 3) {
			throw runtime_error("Polynomial must be of degree 2");
		}

		complex<double> c = poly[0];
		complex<double> b = poly[1];
		complex<double> a = poly[2];

		complex<double> discriminant = b * b - 4.0 * a * c;

		complex<double> root1 = (-b + sqrt(discriminant)) / (2.0 * a);
		complex<double> root2 = (-b - sqrt(discriminant)) / (2.0 * a);

		return std::make_pair(root1, root2);
	}

	template <typename T1, typename T2>
	std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
		os << "(" << p.first << ", " << p.second << ")";
		return os;
	}
}
#endif