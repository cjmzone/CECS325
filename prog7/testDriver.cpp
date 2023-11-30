#include "BigInt.h"
using namespace std;

// struct to store all details of 3n+1 sequences
struct ThreeNp1 {
    BigInt start;
    BigInt steps;
    BigInt max;
    BigInt odd;
    BigInt even;
};

/*
void print(ThreeNp1 temp){
    cout << "start: " << temp.start <<endl ;
    cout << "steps: " << temp.steps << endl;
    cout << "max: " << temp.max << endl;
    cout << "odds: " << temp.odd << endl;
    cout << "evens: " << temp.even << endl;
}
*/

int main(){
    //cout << INT_MAX << endl;
    //BigInt MAX(INT_MAX);
    //cout << "The largest integer is " << MAX << endl;
    BigInt Three("333"),Four(40);
    BigInt Seven = Three + Four;
    cout << "seven: " << Seven << endl;
    BigInt T(566),F(100);
    BigInt S = T + F;
    cout << "s: " << S << endl;
    int x = Three.size();
    int i = S.operator[](10);
    cout << "size: " << x << endl;
    cout << "number at index: " << i << endl;
    return 0;
}
