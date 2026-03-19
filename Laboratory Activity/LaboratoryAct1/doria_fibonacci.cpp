#include <iostream>
using namespace std;

int fibo(int n){
    int a = 0, b = 1, nextTerm;
    
    if (n == 0) return 0;
    for (int i = 2; i <= n; i++) {
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << n << "-th Fibonacci number is: " << fibo(n) << "\n";

    return 0;
  // this is the dynamic approach
}

/*
#include <iostream>
using namespace std;


int recursion(int num){
   if (num == 0) return 0;
   if (num == 1) return 1;
   if (num == 2) return 2;
   
   return recursion(num-1) + recursion(num-2);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    cout << n << "-th Fibonacci number is: " << recursion(n-1); 
}

// this is the recursive approach
*/
