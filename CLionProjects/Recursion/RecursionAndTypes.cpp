#include <iostream>
using namespace std;

void headRecursion(int n) {
    // Base case
    if (n == 0) {
        return;
    }

    // Recursive call
    headRecursion(n - 1);

    // Action on current call
    cout << n << endl;
}

void tailRecursion(int n) {
    // Base case
    if (n == 0) {
        return;
    }

    // Action on current call
    cout << n << endl;

    // Recursive call
    tailRecursion(n - 1);
}

int main() {
    int n = 4;

    cout << "HEAD RECURSION" << endl;
    headRecursion(n); // 1, 2, 3, 4

    cout << endl;
    cout << "TAIL RECURSION" << endl;
    tailRecursion(n);

    return 0;
}
