#include "complex_number.h"
#include <iostream>
#include <string>

complex input_complex_number()
{
    double a, b;
    std::cout << "Please input the real part of the number:: ";
    std::cin >> a;

    std::cout << "Please input the imaginary part of the number:: ";
    std::cin >> b;

    return complex(a, b);
}

void add_or_subtract()
{
    char choice;
    do
    {
        std::cout << "(A)dd or (S)ubtract\n";
        std::cin >> choice;
    } while (choice != 'A' && choice != 'a' && choice != 'S' && choice != 's');

    complex z, w, v;
    if (choice == 'A' || choice == 'a')
    {
        std::cout << "z + w = v\n";
        std::cout << "Complex number z:\n";
        z = input_complex_number();

        std::cout << "Complex number w:\n";
        w = input_complex_number();

        v = addition(z, w);
    }
    else
    {
        std::cout << "z - w = v\n";
        std::cout << "Complex number z:\n";
        z = input_complex_number();

        std::cout << "Complex number w:\n";
        w = input_complex_number();

        v = subtraction(z, w);
    }

    std::cout << "The result is\n" << v.print_complex_number() << "\n";
}

void multiply(){
    char choice;
    do
    {
        std::cout << "Multiply by (S)calar or (C)omplex number\n";
        std::cin >> choice;
    } while (choice != 'C' && choice != 'c' && choice != 'S' && choice != 's');
    if(choice == 's' or choice == 'S'){
        double scalar;
        std::cout << "λz = λ(a+bi)\n" << "Please input Scalar λ:";
        std::cin >> scalar;

        std::cout << "Complex number z:\n";
        complex z = input_complex_number();

        complex w = multiplication(z, scalar);
        std::cout << "The Result is\n" << w.print_complex_number() << "\n";      
    }
    else{
        complex z, w;
        std::cout << "v = z + w\n";

        std::cout << "Complex number z:\n";
        complex z = input_complex_number();

        std::cout << "Complex number w:\n";
        complex w = input_complex_number();

        complex v = multiplication(z,w);
        std::cout << "The result is\n" << w.print_complex_number() << "\n";
    }
}

void divide(){
    char choice;
    do
    {
        std::cout << "Divide by (S)calar or (C)omplex number\n";
        std::cin >> choice;
    } while (choice != 'C' && choice != 'c' && choice != 'S' && choice != 's');
    if(choice == 's' or choice == 'S'){
        double scalar;
        std::cout << "λz = λ(a+bi)\n" << "Please input Scalar λ:";
        std::cin >> scalar;

        std::cout << "Complex number z:\n";
        complex z = input_complex_number();

        complex w = division(z, scalar);
        std::cout << "The Result is\n" << w.print_complex_number() << "\n";      
    }
    else{
        complex z, w;
        std::cout << "v = z + w\n";

        std::cout << "Complex number z:\n";
        complex z = input_complex_number();

        std::cout << "Complex number w:\n";
        complex w = input_complex_number();

        complex v = division(z,w);
        std::cout << "The result is\n" << w.print_complex_number() << "\n";
    }
}

void magnitude(){
    std::cout << "|z| = |a+ib|\n" << "Complex number z:\n";

    complex z = input_complex_number();

    std::cout << "The result is: \n" << z.magnitude() << "\n"; 
}

void arguement(){
    std::cout << "arg(z) = arg(a+ib) = arctan(a/b)\n" << "Complex numberz: \n";

    complex z = input_complex_number();

    std::cout << "The result is: \n" << z.arguement() << "\n";

}

// TODO: Write program
int main()
{
    // bool calculate_again = true;
    // do
    // {
    //     std::cout << "Do you want to (a)dd, (s)ubtract, (d)ivide or (m)ultiply\n";
    // } while (calculate_again);

    add_or_subtract();
}