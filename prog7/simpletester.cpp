#include <iostream>
#include <limits.h>
#include <stdio.h>
#include "BigInt.h"

int main()
{
    std::string tester1val = "1234567890";
    std::string tester2val = "1234567890";
    
    BigInt tester0;
    BigInt tester1(tester1val);
    BigInt tester2(tester2val);
    
    BigInt testerA(5);
    BigInt testerB(150);
    
    BigInt tester3 = tester1 + tester2;
    BigInt testerC = testerB.half();
    
    if(tester1 == tester2)
    {
	std::cout << "\nShould print 0: ";
        std::cout << tester0 << std::endl << std::endl;
        
	std::cout << "Should print 75: ";
        std::cout << testerC << std::endl;
	std::cout << "Should print 75: ";
        std::cout << testerC++ << std::endl << std::endl;
    }
    
    if(testerA < testerB)
    {
	std::cout << "Should print 77: ";
        std::cout << ++testerC << std::endl << std::endl;
        
	std::cout << "Should print 155: ";
        std::cout << testerA + testerB << std::endl << std::endl;
 
	std::cout << "Should print 2.4691357e9: ";
        std::cout << tester3 << std::endl;
    }
    
    std::cout << "\ngetchar included for debugging (press enter to exit)";
    getchar();
    std::cout << std::endl;
}
