#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Fungsi untuk menghitung faktorial
long long factorial(int n) {
    if (n < 0) return -1; // Error untuk bilangan negatif
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main () {
    string op;
    double num1, num2;
    int choice;

    cout << "=== SCIENTIFIC CALCULATOR ===" << endl;
    cout << "Pilih mode kalkulator:" << endl;
    cout << "1. Operasi Dasar (+, -, *, /)" << endl;
    cout << "2. Operasi Scientific" << endl;
    cout << "Masukkan pilihan (1/2): ";
    cin >> choice;
    
    if (choice == 1) {
        // Mode kalkulator dasar
        char basic_op;
        cout << "Masukkan operator (+, -, *, /): ";
        cin >> basic_op;

        cout << "Masukkan dua angka: ";
        cin >> num1 >> num2;

        switch(basic_op) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;

            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;

            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;

            case '/':
                if(num2 != 0)
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                else
                    cout << "Error: Pembagian dengan nol tidak diperbolehkan." << endl;
                break;

            default:
                cout << "Error: Operator tidak valid." << endl;
                break;
        }
    }
    else if (choice == 2) {
        // Mode scientific calculator
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
        
        cout << "\nMasukkan operasi: ";
        cin >> op;

        if (op == "pow") {
            cout << "Masukkan base dan eksponen: ";
            cin >> num1 >> num2;
            cout << num1 << "^" << num2 << " = " << pow(num1, num2) << endl;
        }
        else if (op == "sqrt") {
            cout << "Masukkan angka: ";
            cin >> num1;
            if (num1 >= 0)
                cout << "√" << num1 << " = " << sqrt(num1) << endl;
            else
                cout << "Error: Tidak dapat menghitung akar kuadrat dari bilangan negatif." << endl;
        }
        else if (op == "log") {
            cout << "Masukkan angka: ";
            cin >> num1;
            if (num1 > 0)
                cout << "log(" << num1 << ") = " << log10(num1) << endl;
            else
                cout << "Error: Logaritma hanya dapat dihitung untuk bilangan positif." << endl;
        }
        else if (op == "ln") {
            cout << "Masukkan angka: ";
            cin >> num1;
            if (num1 > 0)
                cout << "ln(" << num1 << ") = " << log(num1) << endl;
            else
                cout << "Error: Logaritma natural hanya dapat dihitung untuk bilangan positif." << endl;
        }
        else if (op == "sin") {
            cout << "Masukkan sudut (derajat): ";
            cin >> num1;
            double radian = num1 * M_PI / 180.0;
            cout << "sin(" << num1 << "°) = " << sin(radian) << endl;
        }
        else if (op == "cos") {
            cout << "Masukkan sudut (derajat): ";
            cin >> num1;
            double radian = num1 * M_PI / 180.0;
            cout << "cos(" << num1 << "°) = " << cos(radian) << endl;
        }
        else if (op == "tan") {
            cout << "Masukkan sudut (derajat): ";
            cin >> num1;
            double radian = num1 * M_PI / 180.0;
            cout << "tan(" << num1 << "°) = " << tan(radian) << endl;
        }
        else if (op == "exp") {
            cout << "Masukkan eksponen: ";
            cin >> num1;
            cout << "e^" << num1 << " = " << exp(num1) << endl;
        }
        else if (op == "fact") {
            int n;
            cout << "Masukkan bilangan bulat: ";
            cin >> n;
            long long result = factorial(n);
            if (result == -1)
                cout << "Error: Faktorial tidak dapat dihitung untuk bilangan negatif." << endl;
            else
                cout << n << "! = " << result << endl;
        }
        else if (op == "abs") {
            cout << "Masukkan angka: ";
            cin >> num1;
            cout << "|" << num1 << "| = " << abs(num1) << endl;
        }
        else {
            cout << "Error: Operasi scientific tidak valid." << endl;
        }
    }
    else {
        cout << "Error: Pilihan tidak valid." << endl;
    }

    return 0;
}