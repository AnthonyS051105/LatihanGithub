#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class ScientificCalculator
{
private:
    long long factorial(int n)
    {
        if (n < 0)
            return -1; // Error untuk bilangan negatif
        if (n == 0 || n == 1)
            return 1;
        long long result = 1;
        for (int i = 2; i <= n; i++)
        {
            result *= i;
        }
        return result;
    }

    double convertToRadians(double degrees)
    {
        return degrees * M_PI / 180.0;
    }

    void displayScientificMenu()
    {
        cout << "\nOperasi Scientific yang tersedia:" << endl;
        cout << "pow - Pangkat (x^y)" << endl;
        cout << "sqrt - Akar kuadrat" << endl;
        cout << "log - Logaritma basis 10" << endl;
        cout << "ln - Logaritma natural" << endl;
        cout << "sin - Sinus (dalam derajat)" << endl;
        cout << "cos - Cosinus (dalam derajat)" << endl;
        cout << "tan - Tangen (dalam derajat)" << endl;
        cout << "exp - Eksponensial (e^x)" << endl;
        cout << "fact - Faktorial" << endl;
        cout << "abs - Nilai absolut" << endl;
    }

public:
    // Constructor
    ScientificCalculator()
    {
        cout << "=== SCIENTIFIC CALCULATOR ===" << endl;
    }

    // Destructor
    ~ScientificCalculator()
    {
        cout << "Calculator session ended. Thank you!" << endl;
    }

    // Basic arithmetic operations
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b)
    {
        if (b != 0)
            return a / b;
        throw invalid_argument("Division by zero is not allowed");
    }

    // Scientific operations
    double power(double base, double exponent) { return pow(base, exponent); }
    double squareRoot(double n)
    {
        if (n >= 0)
            return sqrt(n);
        throw invalid_argument("Cannot calculate square root of negative number");
    }
    double logarithm(double n)
    {
        if (n > 0)
            return log10(n);
        throw invalid_argument("Logarithm can only be calculated for positive numbers");
    }
    double naturalLog(double n)
    {
        if (n > 0)
            return log(n);
        throw invalid_argument("Natural logarithm can only be calculated for positive numbers");
    }
    double sine(double degrees) { return sin(convertToRadians(degrees)); }
    double cosine(double degrees) { return cos(convertToRadians(degrees)); }
    double tangent(double degrees) { return tan(convertToRadians(degrees)); }
    double exponential(double exponent) { return exp(exponent); }
    long long getFactorial(int n)
    {
        long long result = factorial(n);
        if (result == -1)
            throw invalid_argument("Factorial cannot be calculated for negative numbers");
        return result;
    }
    double absoluteValue(double n) { return abs(n); }

    // Display main menu
    void displayMainMenu()
    {
        cout << "Pilih mode kalkulator:" << endl;
        cout << "1. Operasi Dasar (+, -, *, /)" << endl;
        cout << "2. Operasi Scientific" << endl;
        cout << "3. Exit" << endl;
        cout << "Masukkan pilihan (1/2/3): ";
    }

    // Perform basic operations
    void performBasicOperations()
    {
        char op;
        double num1, num2;

        cout << "Masukkan operator (+, -, *, /): ";
        cin >> op;
        cout << "Masukkan dua angka: ";
        cin >> num1 >> num2;

        try
        {
            switch (op)
            {
            case '+':
                cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                break;
            default:
                cout << "Error: Operator tidak valid." << endl;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    // Perform scientific operations
    void performScientificOperations()
    {
        string op;
        double num1, num2;

        displayScientificMenu();
        cout << "\nMasukkan operasi: ";
        cin >> op;

        try
        {
            if (op == "pow")
            {
                cout << "Masukkan base dan eksponen: ";
                cin >> num1 >> num2;
                cout << num1 << "^" << num2 << " = " << power(num1, num2) << endl;
            }
            else if (op == "sqrt")
            {
                cout << "Masukkan angka: ";
                cin >> num1;
                cout << "√" << num1 << " = " << squareRoot(num1) << endl;
            }
            else if (op == "log")
            {
                cout << "Masukkan angka: ";
                cin >> num1;
                cout << "log(" << num1 << ") = " << logarithm(num1) << endl;
            }
            else if (op == "ln")
            {
                cout << "Masukkan angka: ";
                cin >> num1;
                cout << "ln(" << num1 << ") = " << naturalLog(num1) << endl;
            }
            else if (op == "sin")
            {
                cout << "Masukkan sudut (derajat): ";
                cin >> num1;
                cout << "sin(" << num1 << "°) = " << sine(num1) << endl;
            }
            else if (op == "cos")
            {
                cout << "Masukkan sudut (derajat): ";
                cin >> num1;
                cout << "cos(" << num1 << "°) = " << cosine(num1) << endl;
            }
            else if (op == "tan")
            {
                cout << "Masukkan sudut (derajat): ";
                cin >> num1;
                cout << "tan(" << num1 << "°) = " << tangent(num1) << endl;
            }
            else if (op == "exp")
            {
                cout << "Masukkan eksponen: ";
                cin >> num1;
                cout << "e^" << num1 << " = " << exponential(num1) << endl;
            }
            else if (op == "fact")
            {
                int n;
                cout << "Masukkan bilangan bulat: ";
                cin >> n;
                cout << n << "! = " << getFactorial(n) << endl;
            }
            else if (op == "abs")
            {
                cout << "Masukkan angka: ";
                cin >> num1;
                cout << "|" << num1 << "| = " << absoluteValue(num1) << endl;
            }
            else
            {
                cout << "Error: Operasi scientific tidak valid." << endl;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    // Main execution method
    void run()
    {
        int choice;
        bool continueRunning = true;

        while (continueRunning)
        {
            displayMainMenu();
            cin >> choice;

            switch (choice)
            {
            case 1:
                performBasicOperations();
                break;
            case 2:
                performScientificOperations();
                break;
            case 3:
                continueRunning = false;
                cout << "Exiting calculator..." << endl;
                break;
            default:
                cout << "Error: Pilihan tidak valid." << endl;
                break;
            }

            if (continueRunning)
            {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                cout << "\n"
                     << string(50, '-') << "\n"
                     << endl;
            }
        }
    }
};

int main()
{
    ScientificCalculator calculator;
    calculator.run();
    return 0;
}