#include "BigInt.h"

// complete
BigInt::BigInt(){
    v.push_back(0);
}

// complete
BigInt::BigInt(int num){
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

// Complete // string constructor
BigInt::BigInt(string big) {
	for (int i = 0; i < big.size(); ++i) {
			//convert string to char starting backwards
			char digit  = big[big.size() - 1 - i] - '0';
			v.push_back(digit);
		}
};

//Complete // get the value at given index
int BigInt::operator [] (int index) const{
	// If num is less than 0 or greater than or equal to the size of the BigInt,
	if (index < 0 || index >= v.size()){
		 throw out_of_range("Index out of range D:"); 
	} else {
		return v[index];
	}
}

// Complete // returns the number of characters in vector
int BigInt::size() const {
	return v.size();
}

// Complete // add 2 BigInts, return the sum
BigInt BigInt::operator+ (BigInt big) {
		BigInt Result;
		Result.v.pop_back();
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
			Result.v.push_back(sum % 10);
		}

		// remove zero at front
		while (Result.v.size() > 1 && Result.v.back() == 0) {
			Result.v.pop_back();
		}
		return Result;
}

// Comeplte // prefix increment
BigInt BigInt::operator++ () {
	BigInt One(1);
	*this = *this + One; 
	return *this;
}

// Complete // postfix increment  
BigInt BigInt::operator++ (int num) {
	BigInt Result = *this;
	*this = *this + BigInt(1);
	return Result; 
}

// Complete // multiply operator
BigInt BigInt::operator*(BigInt big) {
	BigInt Result;
	int resultSize = v.size() + big.v.size();
	Result.v.resize(resultSize);

    // Initialize the result vector with the appropriate size
    // Result.v.resize(v.size() + big.v.size(), 0);

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < big.v.size(); ++j) {
			int position = i + j;
            int product = int(v[i]) * int(big.v[j]);
            Result.v[position] += product;

            // handle carry 
            if (Result.v[position] >= 10) {
                Result.v[position + 1] += Result.v[position] / 10;
                Result.v[position] = Result.v[position] % 10;
            }
        }
    }
    // Remove leading zeros
    while (Result.v.size() > 1 && Result.v.back() == 0 ) {
        Result.v.pop_back();
    }
    return Result;
}

// Complete // return half the value
BigInt BigInt::half() {
    BigInt Result;
    Result.v.pop_back();
    int carry = 0;

    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        int quotient = (*it + carry) / 2;
        carry = (*it % 2) * 10;
        Result.v.insert(Result.v.begin(), quotient);
    }

    while (Result.v.size() > 1 && Result.v.back() == 0) {
        Result.v.pop_back();
    }
    return Result;
}

// Complete // true if the number is odd
bool BigInt::isOdd(){
	if(v[0] % 2 == 0 ) {
		return false;
	} 
	return true; 
}

// complete // true if the number is even
bool BigInt::isEven(){
	if(v[0] % 2 == 0 ) {
		return true;
	} 
	return false; 
}

// complete // true if 2 BigInts are equal
bool BigInt::operator == (BigInt big)  {
    if (v.size() == big.v.size()) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != big.v[i]) {
                return false;  
            }
        }
        return true;  
    }
    return false; 
}

// Complete 
bool BigInt::operator<(BigInt big){
	if (v.size() != big.v.size()){
		return v.size() < big.v.size();
	} 
	for (int i = 0; i < v.size(); i++){
		if (v[i] != big.v[i]) {
			return v[i] < big.v[i];
		}
	}
	return false; 
}

// complete 
ostream& operator<<(ostream& out, const BigInt& big) {
    if (big.size() <= 8) {
        for (int i = big.size() - 1; i >= 0; i--) {
            out << big[i];
        }
    } else {
        out << big[big.size() - 1];
		out << ".";
        for (int i = big.size() - 2; i >= big.size() - 8; i--) {
            out << big[i];
        }
        out << "e" << big.size() - 1;
    }
	return out;
}