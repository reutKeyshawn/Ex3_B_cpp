#include <iostream>
#include <string>
#include <stdbool.h>
#include <complex>
#include "solver.hpp"

using namespace std;

namespace solver
{

    RealVariable operator-(const RealVariable &r, const double d)
    {
        return RealVariable(r.a, r.b, r.c - d);
    }
    RealVariable operator*(const RealVariable &r, const double d) { return RealVariable(r.a * d, r.b * d, r.c * d); }
    RealVariable operator*(const double d, const RealVariable &r) { return RealVariable(r.a * d, r.b * d, r.c * d); }
    RealVariable operator/(const RealVariable &r, const double d)
    {
        if (d == 0)
            throw std::runtime_error(std::string("Exception - Divide with zero"));
        return RealVariable(r.a / d, r.b / d, r.c / d);
    }
    RealVariable operator^(const RealVariable &r, const double d)
    {
        if (d == 2)
        {
            return r * r;
        }
        else if (d == 1)
        {
            return r;
        }
        else if (d == 0)
        {
            return RealVariable(0, 0, 1);
        }
        else
        {
            throw std::runtime_error(std::string("Exception - power greater than 2"));
        }
    }
    RealVariable operator+(const RealVariable &r, const double d)
    {
        return RealVariable(r.a, r.b, r.c + d);
    }
    RealVariable operator+(const double d, const RealVariable &r)
    {
        return RealVariable(r.a, r.b, r.c + d);
    }
    //right
    RealVariable operator-(const double d, const RealVariable &r)
    {
        return RealVariable(r.a, r.b, r.c - d);
    }

    RealVariable operator==(const double d, const RealVariable &r)
    {
        return d - r;
    }
    RealVariable operator==(const RealVariable &r, const double d)
    {
        return r - d;
    }

    //both
    RealVariable operator+(const RealVariable &l, const RealVariable &r)
    {
        return RealVariable(l.a + r.a, l.b + r.b, l.c + r.c);
    }
    RealVariable operator-(const RealVariable &l, const RealVariable &r)
    {
        return RealVariable(l.a - r.a, l.b - r.b, l.c - r.c);
    }
    RealVariable operator*(const RealVariable &l, const RealVariable &r)
    {
        if (l.a != 0 && (r.a != 0 || r.b != 0))
            throw std::runtime_error(std::string("Exception - Expo is too high"));
        if (l.b != 0 && r.a != 0)
            throw std::runtime_error(std::string("Exception - Expo is too high"));
        return RealVariable(l.a * r.a + l.b * r.b + l.c * r.c, l.b * r.c + l.c * r.b, l.c * r.c);
    }
    RealVariable operator/(const RealVariable &l, const RealVariable &r)
    {
        if (r.a == 0 && r.b == 0 && r.c == 0)
            throw std::runtime_error(std::string("Exception - Dividing with zero"));
        if (l.a == r.a && l.b == r.b && l.c == r.c)
            return RealVariable(0, 0, 1);
        if (r.a == 0 && r.b == 0)
            return RealVariable(l.a / r.c, l.b / r.c, l.c / r.c);
        throw std::runtime_error(std::string("Exception - Division is not possible"));
    }

    double solve(const RealVariable &e)
    {

        double discriminant;
        if (e.a == 0)
        {
            if ((e.b == 0) && (e.c != 0))
                throw std::runtime_error(std::string("Exception - not an equation"));
            return -e.c / e.b;
        }
        discriminant = e.b * e.b - 4 * e.a * e.c;
        if (discriminant >= 0)
            return (-e.b + sqrt(discriminant)) / (2 * e.a);

        throw std::runtime_error(std::string("Exception - equation is imaginary"));
    }

    //equal
    ComplexVariable operator==(const complex<double> d, const ComplexVariable &r) { return d - r; }
    ComplexVariable operator==(const ComplexVariable &l, const complex<double> d) { return l - d; }
    ComplexVariable operator==(const ComplexVariable &l, const ComplexVariable &r) { return l - r; }

    //left
    ComplexVariable operator+(const ComplexVariable &r, const complex<double> d)
    {
        return ComplexVariable(r.a, r.b, r.c + d);
    }
    ComplexVariable operator-(const ComplexVariable &r, const complex<double> d)
    {
        return ComplexVariable(r.a, r.b, r.c - d);
    }
    ComplexVariable operator*(const ComplexVariable &r, const complex<double> d)
    {
        return ComplexVariable(r.a * d, r.b * d, r.c * d);
    }

    ComplexVariable operator/(const ComplexVariable &r, const complex<double> d)
    {
        if (d.imag() == 0 && d.real() == 0)
            throw std::runtime_error(std::string("cannot divide! with zero"));
        return ComplexVariable(r.a / d, r.b / d, r.c / d);
    }

    ComplexVariable operator^(const ComplexVariable &r, const complex<double> d)
    {
        if (d.imag() != 0)
            throw std::runtime_error(std::string("The degree is greater than 2!"));

        if (d.real() == 2)
        {
            return r * r;
        }
        if (d.real() == 1)
        {
            return r;
        }
        if (d.real() == 0)
        {
            std::complex<double> a(0.0, 0.0);
            std::complex<double> b(0.0, 0.0);
            std::complex<double> c(1.0, 0.0);
            return ComplexVariable(a, b, c);
        }
        throw std::runtime_error(std::string("The degree is greater than 2!"));
    }

    ComplexVariable operator^(const ComplexVariable &r, const ComplexVariable &d)
    {
        if (d.a.imag() != 0 || d.b.imag() != 0 || d.c.imag() != 0)
            throw std::runtime_error(std::string("The degree is greater than 2!"));
        std::complex<double> zero(0.0, 0.0);
        if (d.a != zero || d.b != zero)
            throw std::runtime_error(std::string("The degree is greater than 2!"));
        if (d.c.real() == 2)
        {
            return r * r;
        }
        if (d.c.real() == 1)
        {
            return r;
        }
        if (d.c.real() == 0)
        {
            std::complex<double> a(0.0, 0.0);
            std::complex<double> b(0.0, 0.0);
            std::complex<double> c(1.0, 0.0);
            return ComplexVariable(a, b, c);
        }
        throw std::runtime_error(std::string("The degree is greater than 2!"));
    }

    //right
    ComplexVariable operator+(const complex<double> d, const ComplexVariable &r)
    {
        return ComplexVariable(r.a, r.b, r.c + d);
    }
    ComplexVariable operator-(const complex<double> d, const ComplexVariable &r)
    {
        return ComplexVariable(-r.a, -r.b, -r.c + d);
    }
    ComplexVariable operator*(const complex<double> d, const ComplexVariable &r)
    {
        return ComplexVariable(r.a * d, r.b * d, r.c * d);
    }
    ComplexVariable operator/(const complex<double> d, const ComplexVariable &r)
    {
        if (d.imag() == 0 && d.real() == 0)
            throw std::runtime_error(std::string("Exception - dividing with zero"));
        return ComplexVariable(r.a / d, r.b / d, r.c / d);
    }

    //both
    ComplexVariable operator+(const ComplexVariable &l, const ComplexVariable &r)
    {
        return ComplexVariable(l.a + r.a, l.b + r.b, l.c + r.c);
    }
    ComplexVariable operator-(const ComplexVariable &l, const ComplexVariable &r)
    {
        return ComplexVariable(l.a - r.a, l.b - r.b, l.c - r.c);
    }
    ComplexVariable operator*(const ComplexVariable &l, const ComplexVariable &r)
    {
        std::complex<double> zero(0.0, 0.0);
        if (l.a != zero && r.a != zero)
            throw std::runtime_error(std::string("The degree is greater than 2!"));
        if (l.a != zero && r.b != zero)
            throw std::runtime_error(std::string("The degree is greater than 2!"));
        if (l.b != zero && r.a != zero)
            throw std::runtime_error(std::string("The degree is greater than 2!"));

        return ComplexVariable(l.a * r.c + l.b * r.b + l.c * r.a, l.b * r.c + r.b * l.c, l.c * r.c);
    }
    ComplexVariable operator/(const ComplexVariable &l, const ComplexVariable &r)
    {
        std::complex<double> zero(0.0, 0.0);
        std::complex<double> one(1.0, 0.0);
        if (r.a == zero && r.b == zero && r.c == zero)
            throw std::runtime_error(std::string(" Dividing with zero"));
        if (l.a == r.a && l.b == r.b && l.c == r.c)
            return ComplexVariable(0, 0, one);
        if (r.a == zero && r.b == zero)
            return l / r.c;
        throw std::runtime_error(std::string("Division is not possible"));
    }

    complex<double> solve(const ComplexVariable &e)
    {
        std::complex<double> zero(0.0, 0.0);

        if (e.a == zero && e.b == zero && e.c == zero)
            return 0;

        if (e.a == zero)
        {
            if ((e.b == zero) && (e.c != zero))
                throw std::runtime_error(std::string(" no solution!"));
            else
                return -e.c / e.b;
        }

        complex<double> discriminant, four(4.0, 0.0), two(2.0, 0.0);

        discriminant = e.b * e.b - four * e.a * e.c;

        return (-e.b + sqrt(discriminant)) / (two * e.a);
    }
}; // namespace solver