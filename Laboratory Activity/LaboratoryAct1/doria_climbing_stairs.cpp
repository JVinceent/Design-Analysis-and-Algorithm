// john vincent doria

#include <iostream>
using namespace std;

int climb_stairs(int n) {
    // base cases
    if (n<=0) return 0;
    if (n==1) return 1;
    if (n==2) return 2;

    int a = 1;
    int b = 2;
    int next = 0;

    for (int i = 3; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return next;
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    cout << "Number of distinct ways: " << climb_stairs(n);
}


    