#include <iostream>
#include <limits.h>
using namespace std;

int add(int a, int b) {
    cout << "Inside add function=> a:" << a << " b:" << b << endl;
    int c = 0;
    c = a + b;
    if (c > 0)
        cout << "no over flow\n";
    else
        throw "3.14";
    return c;
}

int main() {
    cout << "MAX INt:"<< INT_MAX << endl;
    try {
        cout << add(INT_MAX, 5) << endl;
        cout << "happy happy\n";
    }
    catch (...) {
        cout << "error caught:"<<endl;
    }
    
    cout << "lucky day!\n"; // if elese statement here
    return 0;
}