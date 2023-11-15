// Connor McKenna
// (CECS 325-01)
// Program 6 - 32 + 1
// Due Date (11/15/2023)
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <limits.h>

using std::cout;
using std::cin;
using std::endl;
using std::stoi;

int compute(int num, int &max, int &evenCount, int &oddCount, int &steps) {
	// check for integer overflow
	int next = 0;
	if(num >! INT_MAX) {

		// if num is even
		if (num % 2 == 0) {
			evenCount++;
			steps++;

			next = num / 2;
			if (next > max) {
				max = next;
			}

			if (next < 0 ) {
				throw num;
				
			} else if (next == 1) {
				steps++;
				cout << "->(" << next << ")";
				return 0;
			} else {
				cout << "->(" << next << ")";
				return compute(next, max, evenCount, oddCount, steps);
			}
		// if num is odd
  		} else {

			oddCount++;
			steps++;
			next = 3 * num + 1;
			if (next > max) {
				max = next;
			}

			if (next < 0 ) {
				throw num;

			} else if (next == 1) {
				steps++;
				cout << "->(" << next << ")";
				return 0;
			} else {
				cout << "->(" << next << ")";
				return compute(next, max, evenCount, oddCount, steps);
			}
  		}
	} else {
		throw num;
	}
}

int main(int argc, char* argv[]) {

	if (argc == 1) {
		int evenCount = 0;
		int oddCount = 0;
		int steps = 0;
		int start = 0;

		cout << "Enter a 3n+1 candidate: ";
		cin >> start;
		int max = start;

		cout << "->(" << start << ")";
		try {
	    		compute(start, max, evenCount, oddCount, steps);
			} catch (int overflow) {
				cout << "->(###overflow###)" << endl << endl;
				cout << "overflow detected for: " << overflow << endl;
				cout << "3n + 1: " << 3 * (overflow + 1) << endl; 
				cout << "something broke, dude :(" << endl;
			}

		cout << endl;
		cout << "start: " << start << endl;
		cout << "steps: " << steps - 1 << endl;
		cout << "max: " << max << endl;
		cout << "odds: " << oddCount << endl;
		cout << "evens: " << evenCount << endl << endl;

 	} else {

    	for (int i = 1; i < argc; i++) {
      		int evenCount = 0;
      		int oddCount = 0;
      		int steps = 0;
     		int start = stoi(argv[i]);
     		int max = start;

			cout << "Solving 3n + 1 - starting value: " << start << endl;
     		cout << "->(" << start << ")";

			try {
	    		compute(start, max, evenCount, oddCount, steps);
			} catch (int overflow) {
				cout << "->(###overflow###)" << endl << endl;
				cout << "overflow detected for: " << overflow << endl;
				cout << "3n + 1: " << 3 * (overflow + 1) << endl; 
				cout << "something broke, dude :(" << endl << endl;
				continue;
			}

      		cout << endl;
     		cout << "start: " << start << endl;
      		cout << "steps: " << steps - 1 << endl;
      		cout << "max: " << max << endl;
      		cout << "odds: " << oddCount << endl;
      		cout << "evens: " << evenCount << endl << endl;
		}
	}
  	return 0;
}
