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

    std::cout << "The result is\n"
              << v.print_complex_number() << "\n";
}

void multiply()
{
    char choice;
    do
    {
        std::cout << "Multiply by (S)calar or (C)omplex number\n";
        std::cin >> choice;
    } while (choice != 'C' && choice != 'c' && choice != 'S' && choice != 's');
    if (choice == 's' or choice == 'S')
    {
        double scalar;
        std::cout << "λz = λ(a+bi)\n"
                  << "Please input Scalar λ:";
        std::cin >> scalar;

        std::cout << "Complex number z:\n";
        complex z = input_complex_number();

        complex w = multiplication(z, scalar);
        std::cout << "The Result is\n"
                  << w.print_complex_number() << "\n";
    }
    else
    {
        std::cout << "v = z + w\n";

        std::cout << "Complex number z:\n";
        complex z = input_complex_number();

        std::cout << "Complex number w:\n";
        complex w = input_complex_number();

        complex v = multiplication(z, w);
        std::cout << "The result is\n"
                  << w.print_complex_number() << "\n";
    }
}

void divide()
{
    char choice;
    do
    {
        std::cout << "Divide by (S)calar or (C)omplex number\n";
        std::cin >> choice;
    } while (choice != 'C' && choice != 'c' && choice != 'S' && choice != 's');
    if (choice == 's' or choice == 'S')
    {
        double scalar;
        std::cout << "λz = λ(a+bi)\n"
                  << "Please input Scalar λ:";
        std::cin >> scalar;

        std::cout << "Complex number z:\n";
        complex z = input_complex_number();

        complex w = division(z, scalar);
        std::cout << "The Result is\n"
                  << w.print_complex_number() << "\n";
    }
    else
    {
        std::cout << "v = z + w\n";

        std::cout << "Complex number z:\n";
        complex z = input_complex_number();

        std::cout << "Complex number w:\n";
        complex w = input_complex_number();

        complex v = division(z, w);
        std::cout << "The result is\n"
                  << w.print_complex_number() << "\n";
    }
}

void modulus()
{
    std::cout << "|z| = |a+ib|\n"
              << "Complex number z:\n";

    complex z = input_complex_number();

    std::cout << "The result is: \n"
              << z.modulus() << "\n";
}

void arguement()
{
    std::cout << "arg(z) = arg(a+ib) = arctan(a/b)\n"
              << "Complex number z: \n";

    complex z = input_complex_number();

    std::cout << "The result is: \n"
              << z.arguement() << "\n";
}

void find_conjugate()
{
    std::cout << "Z = a+ib\n"
              << "Z* = a-ib\n"
              << "Complex number z: \n";

    complex z = input_complex_number();
    complex w = z.conjugate();
    std::cout << "The result is: \n"
              << w.print_complex_number() << "\n";
}
// TODO: Write program
int main()
{
    bool repeat = true;
    do
    {
        std::string choice;
        do
        {
            std::cout << "Welcome to the complex calculator\n"
                      << "Do you want to (A)dd or (S)ubtract, (M)ultiply, (D)ivide or (O)ther \n";
            std::cin >> choice;
        } while (choice != "A" && choice != "a" && choice != "S" && choice != "s" && choice != "M" && choice != "m" && choice != "D" && choice != "d" && choice != "O" && choice != "o");
        if (choice == "A" || choice == "a" || choice == "S" || choice == "s")
        {
            add_or_subtract();
        }
        else if (choice == "M" || choice == "m")
        {
            multiply();
        }
        else if (choice == "D" || choice == "d")
        {
            divide();
        }
        if (choice == "O" || choice == "o")
        {
            do
            {
                std::cout << "Do you want to find the (M)agnitude, (A)rguement or (C)omplex conjugate";
                std::cin >> choice;
            } while (choice != "M" && choice != "m" && choice != "A" && choice != "a" && choice != "C" && choice != "c");

            if (choice == "M" || choice == "m")
            {
                modulus();
            }
            else if (choice == "A" || choice == "a")
            {
                arguement();
            }
            else if (choice == "C" || choice == "c")
            {
                find_conjugate();
            }
        }
        do
        {
            std::cout << "Do you want to run the calculator again\n";
            std::cin >> choice;
        } while (choice != "Y" && choice != "y" && choice != "N" && choice != "n");
        if(choice == "N" || choice == "n"){
            repeat = false;
        }
    } while (repeat);
    return 0;
}