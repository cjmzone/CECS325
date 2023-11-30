#include "BigInt.h"
#include <iostream>

// complete
BigInt::BigInt(){
    v.push_back(0);
}

// complete
BigInt::BigInt(int num){
    cout << "Entering BigInt()\n";
    if (num == 0) {
        v.push_back(0);
    }
    else{
        while(num > 0){
            char digit = num % 10; 
            v.push_back(digit);
            num = num / 10;
        }
    }
}

// Complete
BigInt::BigInt(string big) {
	for (int i = 0; i < big.size(); ++i) {
			//convert string to char starting backwards
			char digit  = big[big.size() - 1 - i] - '0';
			v.push_back(digit);
		}
};

// to do 
int BigInt::operator [] (int index){
	// If num is less than 0 or greater than or equal to the size of the BigInt,
	if (index < 0 || index >= v.size()){
		 throw std::out_of_range("Index out of range"); 
	} else {
		return v[index];
	}
}

// complete
int BigInt::size(){
	return v.size();
}

// complete
BigInt BigInt::operator+ (BigInt big) {
		BigInt Temp;
		Temp.v.pop_back();
		int maxSize = 0;
		int sum = 0;
		int carry = 0;

		// get the size of the biggest vector
		if (v.size() > big.v.size()) {
			maxSize = v.size();
		} else {
			maxSize = big.v.size();
		} 

		// loop through place values and add
		for (int i = 0; i < maxSize + 1; i++) {
			sum = carry;
			// add if there's a number
			if (i < v.size()) {
				sum += (int)v[i];
			}
			if (i < big.v.size()) {
				sum += (int)big.v[i];
			}
			//calculate carry number
			carry = sum / 10;
			Temp.v.push_back(sum % 10);
		}

		//remove zero at front
		while (Temp.v.size() > 1 && Temp.v.back() == 0) {
			Temp.v.pop_back();
		}
		
		return Temp;
}

// complete 
ostream& operator<<(ostream& out, const BigInt &big) {
	// assign an iterator to the end of v
	auto it = big.v.rbegin();

	// iterate through v until *it++ reaches the begining
	while (it != big.v.rend()) {
		out << int(*it++);
	}
	return out;
}