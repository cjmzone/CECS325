#include <iostream>
#include <limits.h>
#include <vector>

using std::vector;
using namespace std;

int compute(int num, int &max, int &evenCount, int &oddCount, int &steps){

	// if num is even
	if(num % 2 != 1) {

		evenCount++;
		steps++;
		int next = num / 2;

		if (next > max ) {
			max = next;
		}

		if(next == 1) {
			steps++;
			cout << "->(" << next << ")";
			return 0;
		}

		cout << "->(" << next << ")";
		return compute(next, max, evenCount, oddCount, steps);

	} else { // num is odd 
	
		oddCount++;
		steps++;
		int next = 3*(num) + 1;

		if (next > max ) {
			max = next;
		}

		if(next == 1) {
			steps++;
			cout << "->(" << next << ")";
			return 0;
		}

		cout << "->(" << next << ")";
		return compute(next, max, evenCount, oddCount, steps);
	}
}

int main(int argc, char* argv[]) {
	
	if (argc == 1 ) {
		int evenCount = 0;
		int oddCount = 0;
		int steps = 0;
		int start = 0;
		cout << "Enter a 3n+1 candidate: "; 
		cin >> start;
		int max = start;
		cout << "->(" << start << ")";
		compute(start, max, evenCount, oddCount, steps);
		cout << endl;
		cout << "max: " << max << endl; 
		cout << "evens: " << evenCount << endl; 
		cout << "odds: " << oddCount << endl; 
		cout << "steps: " << steps << endl; 
	} else {
		for (int i = 1; i < argc; i++) {
			int evenCount = 0;
			int oddCount = 0;
			int steps = 0;
			int start = stoi(argv[i]);
			int max = start;
			cout << "->(" << start << ")";
			compute(start, max, evenCount, oddCount, steps);
			cout << endl;
			cout << "max: " << max << endl; 
			cout << "evens: " << evenCount << endl; 
			cout << "odds: " << oddCount << endl; 
			cout << "steps: " << steps << endl; 
		}
	}
	return 0;
}
