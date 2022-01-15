//
// Created by Ryan.Zurrin001 on 1/14/2022.
//

#ifndef COMPLEXNUMBER_COMPLEX_H
#define COMPLEXNUMBER_COMPLEX_H
#include <iostream>

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex();
    Complex(double real, double imaginary);

    Complex(const Complex &other);
    ~Complex();
    [[nodiscard]] double getReal() const;
    [[nodiscard]] double getImaginary() const;
    Complex operator+(const Complex &other) const;
    Complex& operator+=(const Complex &other);
    Complex operator-(const Complex &other) const;
    Complex& operator-=(const Complex &other);
    Complex operator*(const Complex &other) const;
    Complex& operator*=(const Complex& rhs);
    Complex operator/(const Complex &other) const;
    Complex& operator/=(const Complex& rhs);
    Complex& operator=(const Complex &other);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

Complex::Complex() : real(0), imaginary(0) {}

Complex::Complex(double real, double imaginary) :
real(real), imaginary(imaginary) {}

Complex::Complex(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;
}

Complex::~Complex() {
    real = 0;
    imaginary = 0;
}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

Complex Complex::operator+(const Complex &other) const {
    return {real + other.real, imaginary + other.imaginary};
}

Complex Complex::operator-(const Complex &other) const {
    return {real - other.real, imaginary - other.imaginary};
}

Complex Complex::operator*(const Complex &other) const {
    return {real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real};
}

Complex Complex::operator/(const Complex &other) const {
    return {(real * other.real + imaginary * other.imaginary) /
            (other.real * other.real + other.imaginary * other.imaginary),
            (imaginary * other.real - real * other.imaginary) /
            (other.real * other.real + other.imaginary * other.imaginary)};
}

Complex& Complex::operator=(const Complex &other) = default;

std::ostream &operator<<(std::ostream &os, const Complex &c) {
    os << c.real << " + " << c.imaginary << "i";
    return os;
}

Complex &Complex::operator+=(const Complex &other) {
    real += other.real;
    imaginary += other.imaginary;
    return *this;
}

Complex &Complex::operator-=(const Complex &other) {
    real -= other.real;
    imaginary -= other.imaginary;
    return *this;
}

Complex &Complex::operator*=(const Complex &rhs) {
    double real_ = this->real * rhs.real - this->imaginary * rhs.imaginary;
    double imaginary_ = this->real * rhs.imaginary + this->imaginary * rhs.real;
    this->real = real_;
    this->imaginary = imaginary_;
    return *this;
}

Complex &Complex::operator/=(const Complex &rhs) {
    double real_ = (this->real * rhs.real + this->imaginary * rhs.imaginary) /
                   (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);
    double imaginary_ = (this->imaginary * rhs.real - this->real * rhs.imaginary) /
                        (rhs.real * rhs.real + rhs.imaginary * rhs.imaginary);
    this->real = real_;
    this->imaginary = imaginary_;
    return *this;
}

#endif //COMPLEXNUMBER_COMPLEX_H
