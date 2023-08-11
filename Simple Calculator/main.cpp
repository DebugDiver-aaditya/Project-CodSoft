#include <iostream>

class Calculator {
public:
    float add(float num1, float num2) {
        return num1 + num2;
    }

    float subtract(float num1, float num2) {
        return num1 - num2;
    }

    float multiply(float num1, float num2) {
        return num1 * num2;
    }

    float divide(float num1, float num2) {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            throw std::runtime_error("Division by zero is not allowed.");
        }
    }
};

int main() {
    Calculator calculator;

    float num1, num2;
    char operation;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    float result;

    try {
        switch (operation) {
            case '+':
                result = calculator.add(num1, num2);
                break;
            case '-':
                result = calculator.subtract(num1, num2);
                break;
            case '*':
                result = calculator.multiply(num1, num2);
                break;
            case '/':
                result = calculator.divide(num1, num2);
                break;
            default:
                std::cout << "Invalid operation.\n";
                return 1; // Exit with an error code
        }

        std::cout << "Result: " << result << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1; // Exit with an error code
    }

    return 0;
}
