#include<iostream>

using namespace std;

int addInt(int a, int b) {
    return a + b;
}

float addFloat(float a, float b) {
    return a + b;
}

template <typename T>
class calculator {
public:

    T add(T a, T b) {
        return a + b;
    }

    T subtract(T a, T b) {
        return a - b;
    }

    T multiply(T a, T b) {
        return a * b;
    }

    T divide(T a, T b) {
        if (b == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }

        return a / b;
    }

};


int main() {

    calculator<int> intCalc;

    cout << "Integer Addition: " << intCalc.add(5, 3) << endl; // Should print 8
    cout << "Integer Subtraction: " << intCalc.subtract(5, 3) << endl; // Should print 2

    calculator<float> floatCalc;
    cout << "Float Addition: " << floatCalc.add(5.5f, 3.2f) << endl; // Should print 8.7
    cout << "Float Subtraction: " << floatCalc.subtract(5.5f, 3.2f) << endl; // Should print 2.3
    
    cout << "Float Multiplication: " << floatCalc.multiply(5.5f, 3.2f) << endl; // Should print 17.6
    cout << "Float Division: " << floatCalc.divide(5.5f, 3.2f) << endl; // Should print 1.71875


    cin.get();

    return 0;
}
