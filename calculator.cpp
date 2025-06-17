#include <iostream>
using namespace std;

int main() {
   
    cout << "-----------------------------" << endl;
    cout << " Welcome to Simple Calculator " << endl;
    cout << "-----------------------------" << endl;

    
    double number1, number2, result;
    char operation;

   
    cout << "Enter the first number: ";
    cin >> number1;

    cout << "Enter the second number: ";
    cin >> number2;


    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;


    if (operation == '+') {
        result = number1 + number2;
        cout << "Result: " << number1 << " + " << number2 << " = " << result << endl;
    } else if (operation == '-') {
        result = number1 - number2;
        cout << "Result: " << number1 << " - " << number2 << " = " << result << endl;
    } else if (operation == '*') {
        result = number1 * number2;
        cout << "Result: " << number1 << " * " << number2 << " = " << result << endl;
    } else if (operation == '/') {
        if (number2 == 0) {
            cout << "Error: Division by zero is not allowed!" << endl;
        } else {
            result = number1 / number2;
            cout << "Result: " << number1 << " / " << number2 << " = " << result << endl;
        }
    } else {
        cout << "Invalid operation! Please use +, -, *, or /." << endl;
    }
    cout << "Thank you for using the calculator!" << endl;

    return 0;
}

