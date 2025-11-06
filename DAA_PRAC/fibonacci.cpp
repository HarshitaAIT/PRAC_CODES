#include <iostream>
using namespace std;

int stepCount = 0;

int fibonacci(int n) {
    stepCount++; 
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the term (n) for Fibonacci: ";
    cin >> n;

    int result = fibonacci(n);

    cout << "Fibonacci(" << n << ") = " << result << endl;
    cout << "Step count = " << stepCount << endl;

    return 0;
}
