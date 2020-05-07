
#ifndef SOLVER_A_MASTER_SOLVER_HPP
#define SOLVER_A_MASTER_SOLVER_HPP

#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>
#include <complex>

using namespace std;
namespace solver
{

    class RealVariable
    {
    public:
        double a, b, c;

        RealVariable(double a, double b, double c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        RealVariable() : a(0), b(1), c(0){};

        //right
        friend RealVariable operator-(const double num, const RealVariable &x);
        friend RealVariable operator/(const double num, const RealVariable &x);
        friend RealVariable operator+(const double num, const RealVariable &x);
        friend RealVariable operator*(const double num, const RealVariable &x);
        friend RealVariable operator^(const double num, const RealVariable &x);

        //left
        friend RealVariable operator+(const RealVariable &x, const double num);
        friend RealVariable operator-(const RealVariable &x, const double num);
        friend RealVariable operator*(const RealVariable &x, const double num);
        friend RealVariable operator/(const RealVariable &x, const double num);
        friend RealVariable operator^(const RealVariable &x, const double num);

        //both
        friend RealVariable operator+(const RealVariable &x1, const RealVariable &x);
        friend RealVariable operator-(const RealVariable &x1, const RealVariable &x);
        friend RealVariable operator*(const RealVariable &x1, const RealVariable &x);
        friend RealVariable operator/(const RealVariable &x1, const RealVariable &x);
        friend RealVariable operator^(const RealVariable &x1, const RealVariable &x);
        //relevant for solve function
        friend RealVariable operator==(const double num, const RealVariable &x);
        friend RealVariable operator==(const RealVariable &x, const double num);
        friend RealVariable operator==(const RealVariable &x1, const RealVariable &x)
        {
            return x1 - x;
        }
        friend RealVariable operator==(const RealVariable &x, const double num);
    };

    class ComplexVariable
    {
    public:
        complex<double> a, b, c;

        ComplexVariable() : a(0), b(1, 0), c(0) {}

        ComplexVariable(complex<double> a, complex<double> b, complex<double> c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        //right
        friend ComplexVariable operator+(const complex<double> c, const ComplexVariable &y);
        friend ComplexVariable operator-(const complex<double> c, const ComplexVariable &y);
        friend ComplexVariable operator*(const complex<double> c, const ComplexVariable &y);
        friend ComplexVariable operator/(const complex<double> r, const ComplexVariable &d);
        friend ComplexVariable operator^(const complex<double> r, const ComplexVariable &d);

        //left
        friend ComplexVariable operator+(const ComplexVariable &y, const complex<double> c);
        friend ComplexVariable operator-(const ComplexVariable &y, const complex<double> c);
        friend ComplexVariable operator*(const ComplexVariable &y, const complex<double> c);
        friend ComplexVariable operator/(const ComplexVariable &y, const complex<double> c);
        friend ComplexVariable operator^(const ComplexVariable &y, const complex<double> c);
        //both
        friend ComplexVariable operator+(const ComplexVariable &y1, const ComplexVariable &y);
        friend ComplexVariable operator-(const ComplexVariable &y1, const ComplexVariable &y);
        friend ComplexVariable operator*(const ComplexVariable &y1, const ComplexVariable &y);
        friend ComplexVariable operator/(const ComplexVariable &y1, const ComplexVariable &y);
        friend ComplexVariable operator^(const ComplexVariable &y1, const ComplexVariable &y);
        //relevant for solve function
        friend ComplexVariable operator==(const complex<double> c, const ComplexVariable &y);
        friend ComplexVariable operator==(const ComplexVariable &y1, const complex<double> c);
        friend ComplexVariable operator==(const ComplexVariable &y1, const ComplexVariable &y);
    };

    //solve the equation with a function
    double solve(const RealVariable &e);
    complex<double> solve(const ComplexVariable &e);

}; // namespace solver

#endif