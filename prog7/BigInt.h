#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <limits.h>
#include <stdexcept>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::ostream;

class BigInt {
    public:
        BigInt ();                                            // Complete // default constructor
        BigInt (int);                                         // Complete // Paramaterized constructor
        BigInt (string);                                      // Complete // string constructor
        int operator [] (int);                                // Complete // returns the digit at the specified location
                                                                    // if the location is out of range,
                                                                     // throw a string called “index out of range”
        int size();                                           // Complete // return the number of digits in the BigInt
        BigInt operator+ (BigInt);                            // Complete // add 2 BigInts, return the sum

        BigInt operator++ ();                                 // prefix increment
        BigInt operator++ (int);                              // postfix increment  
        BigInt operator* (BigInt);                            // multiply operator 

        BigInt half();                                        // return half the value
        bool isOdd();                                         // true if the number is odd
        bool isEven();                                        // true if the number is even
        bool operator == (BigInt);                            // true if 2 BigInts are equal

        // cout << BigInt
        // you MUST use operator[] in here
        friend ostream& operator<<(ostream&, const BigInt&);

    private:
        vector<char> v;
};

#endif // BIGINT_H