#include <iostream>
using namespace std;
class Complex
{
public:
    double real;
    double imag;

    Complex()
    {
        real = 0.0;
        imag = 0.0;
    }
    Complex(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
    }

    void printNum()
    {
        cout << this->real << " + " << this->imag << "i" << endl;
    }
    Complex operator+(Complex &obj)
    {
        Complex temp;
        temp.real = this->real + obj.real;
        temp.imag = this->imag + obj.imag;
        return temp;
    }
    Complex operator-(Complex &obj)
    {
        Complex temp;
        temp.real = this->real - obj.real;
        temp.imag = this->imag - obj.imag;
        return temp;
    }
    Complex operator*(Complex &obj)
    {
        Complex temp;
        temp.real = ((this->real) * (obj.real)) - ((this->imag) * (obj.imag));
        temp.imag = ((this->real) * (obj.imag)) + ((this->imag) * (obj.real));

        return temp;
    }
    Complex operator<<(Complex &obj)
    {
        cout << this->real << " + " << this->imag << "i" << endl;
    }
    friend ostream &operator<<(ostream &output, Complex &obj)
    {
        output << obj.real << " + " << obj.imag << "i" << endl;
        return output;
    }
    friend istream &operator>>(istream &input, Complex &obj)
    {
        // output << obj.real << " + " << obj.imag << "i" << endl;
        // return output;
        cout << "Enter real number" << endl;
        input >> obj.real;
        cout << "Enter imaginary number" << endl;
        input >> obj.imag;
        return input;
    }
};

int main()
{
    Complex c1, c2, c3, c4, c5, c6;
    int choice;

    while (true)
    {
        cout << "\nMenu: \n";
        cout << "1. Input two complex numbers\n";
        cout << "2. Add the complex numbers\n";
        cout << "3. Subtract the complex numbers\n";
        cout << "4. Multiply the complex numbers\n";
        cout << "5. Display All above the complex numbers and operations betn them\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter first complex number (format: real imaginary): ";
            cin >> c1;
            cout << "Enter second complex number (format: real imaginary): ";
            cin >> c2;
            break;
        case 2:
            c3 = c1 + c2;
            cout << "Sum of the complex numbers: " << c3 << endl;
            break;
        case 3:
            int choice;
            while (true)
            {
                cout << "\nMenu: \n";
                cout << "1. Wanna do Complex 1  - Complex 2\n";
                cout << "2. Wanna do Complex 2  - Complex 1\n";
                cin >> choice;
                if (choice == 1)
                {
                    c4 = c1 - c2;
                    cout << "Difference of the complex numbers: " << c4 << endl;
                    break;
                }
                else if (choice == 2)
                {
                    c4 = c2 - c1;
                    cout << "Difference of the complex numbers: " << c4 << endl;
                    break;
                }
                else
                {
                    cout << "Invalid Choice ,try again" << endl;
                }
            }
            break;
        case 4:
            c5 = c1 * c2;
            cout << "Product of the complex numbers: " << c5 << endl;
            break;
        case 5:
            c3 = c1 + c2;
            c4 = c1 - c2;
            c5 = c2 - c1;
            c6 = c2 * c1;
            cout << "First Complex Number: " << c1 << endl;
            cout << "Second Complex Number: " << c2 << endl;
            cout << "Sum: " << c3 << endl;
            cout << "Difference of Complex 1 - Complex2: " << c4 << endl;
            cout << "Difference of Complex 2 - Complex1: " << c5 << endl;
            cout << "Product: " << c6 << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}