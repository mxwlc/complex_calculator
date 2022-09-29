#include <iostream>
#include <cmath>
#include <string>

/// @brief Complex number of the form x+iy
struct complex
{
    double real, imaginary;

    /// @brief Default Constructor
    complex() : real(0), imaginary(0) {}

    /// @brief Constructor with all Parameters
    /// @param r Real
    /// @param i Imaginary
    complex(double r, double i) : real(r), imaginary(i) {}

    /// @brief Magnitude of a complex number
    /// @return returns |a+ib| as a double
    double modulus()
    {
        double magnitude_squared = std::pow(real, 2) + std::pow(imaginary, 2);
        return std::sqrt(magnitude_squared);
    }

    /// @brief Finds the arguement of a complex Number
    /// @return Returns arg(a+ib) as a Double
    double arguement()
    {
        double imaginary_over_real = imaginary / real;
        return std::atan(imaginary_over_real);
    }
    
    /// @brief Returns the complex conjugate z* of the complex number z
    /// @return returns z in the form x+iy
    complex conjugate(){
        complex temp = complex(real, -1*imaginary);
        return temp;
    }

    /// @brief Returns complex number in the form x+iy
    /// @return string "x+iy"
    std::string print_complex_number(){
        return std::to_string(real) + " + " + std::to_string(imaginary) + "i";  
    }
};

/// @brief Adds one complex number to another
/// @param z Complex number of the form x+iy
/// @param w Complex number of the form x+iy
/// @return Returns (a+ib) - (c+id) in the form x+iy
complex addition(complex z, complex w)
{
    complex v = complex((z.real + w.real), (z.imaginary + w.imaginary));
    return v;
}

/// @brief Subtracts one complex number from the other
/// @param z Complex number of the form x+iy
/// @param w Complex number of the form x+iy
/// @return Returns (a+ib) - (c+id) in the form x+iy
complex subtraction(complex z, complex w)
{
    complex v = complex((z.real - w.real), (z.imaginary - w.imaginary));
    return v;
}

/// @brief Returns the product of 2 complex numbers
/// @param z Complex number of the form x+iy
/// @param w Complex number of the form x+iy
/// @return Product of a and b of the form x+iy
complex multiplication(complex z, complex w)
{
    double a, b, c, d, x, y;
    a = z.real;
    b = z.imaginary;
    c = w.real;
    d = w.imaginary;

    x = (a) * (c) - (b) * (d);
    y = (a) * (d) + (b) * (c);
    complex v = complex(x, y);
    return v;
}

/// @brief Multiplies a complex number by a real scalar
/// @param a Complex number of the form x+iy
/// @param l Real Scalar
/// @return Returns λ(a+ib) in the form x+iy
complex multiplication(complex z, double l)
{
    complex w = complex(l * (z.real), l * (z.imaginary));
    return w;
}

/// @brief Divides 1 complex number z by another w
/// @param z Complex number of the form x+iy
/// @param w Complex number of the form x+iy
/// @return Returns z/w in the form x+iy
complex division(complex z, complex w)
{
    double a, b, c, d, x, y;
    a = z.real;
    b = z.imaginary;
    c = w.real;
    d = w.imaginary;

    x = ((a) * (c) + (b) * (d)) / (std::pow(c, 2) + std::pow(d, 2));
    y = ((b) * (c) - (a) * (d)) / (std::pow(c, 2) + std::pow(d, 2));

    complex v = complex(x, y);
    return v;
}

/// @brief Divides a complex number z by a scalar λ
/// @param z Complex number of the form x+iy
/// @param λ Scalar Double
/// @return Returns 1/λ*(a+bi) in the form x+iy
complex division(complex z, double λ)
{
    complex w = complex((z.real / λ), (z.imaginary / λ));
    return w;
}