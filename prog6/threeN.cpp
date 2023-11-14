#include <iostream>
#include <limits.h>

using namespace std;

int compute(int num, int &max, int &evenCount, int &oddCount, int &steps) {
	// check for integer overflow
	if(num >! INT_MAX) {
		// if num is even
		if (num % 2 == 0) {
			evenCount++;
			steps++;
			int next = num / 2;
			if (next > max) {
				max = next;
			}

			if (next == 1) {
				steps++;
				cout << "->(" << next << ")";
				return 0;
			}

			cout << "->(" << next << ")";
			return compute(next, max, evenCount, oddCount, steps);

		// if num is odd
  		} else {

			oddCount++;
			steps++;
			int next = 3 * num + 1;
			if (next > max) {
				max = next;
			}

			if (next == 1) {
				steps++;
				cout << "->(" << next << ")";
				return 0;
			}

			cout << "->(" << next << ")";
			return compute(next, max, evenCount, oddCount, steps);
  		}
	} else {
		throw 3.14;
	}
}

int main(int argc, char* argv[]) {
	cout << "Max int: " << INT_MAX << endl; 
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
			} catch (...) {
				cout << "ERROR caught:" << endl;
			}
		cout << endl;

		cout << "start: " << start << endl;
		cout << "steps: " << steps << endl;
		cout << "max: " << max << endl;
		cout << "odds: " << oddCount << endl;
		cout << "evens: " << evenCount << endl;
 	} else {
    	for (int i = 1; i < argc; i++) {
      		int evenCount = 0;
      		int oddCount = 0;
      		int steps = 0;
     		int start = stoi(argv[i]);

     		int max = start;
     		cout << "->(" << start << ")";

			try {
	    		compute(start, max, evenCount, oddCount, steps);
			} catch (...) {
				cout << "->(###overflow###)" << endl;
			}
      		cout << endl;

     		cout << "start: " << start << endl;
      		cout << "steps: " << steps << endl;
      		cout << "max: " << max << endl;
      		cout << "odds: " << oddCount << endl;
      		cout << "evens: " << evenCount << endl;
		}
	}
  return 0;
}