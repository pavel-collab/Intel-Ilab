#include <iostream>
#include <cassert>
#include "../include/cache.hpp"

unsigned numTests = 9;

int main() {
    FILE* ftest;
    const char* nameTests[numTests] = {"001.dat", "002.dat", "003.dat", "004.dat", "005.dat",
                                       "006.dat", "007.dat", "008.dat", "009.dat"};


    for (int i = 0; i < numTests; i++) {
        ftest = freopen (nameTests[i], "r", stdin);
        
        unsigned cacheSize = 0;
        unsigned numPages  = 0;
        int id = 0;

        std::cin >> cacheSize >> numPages;
        assert(std::cin.good());

        Cache2Q<int> Cache{cacheSize};

        int result = 0;
        while (numPages-- > 0) {
            std::cin >> id;
            int page = slow_get_page<int, int>(id); 
            
            if (Cache.CacheIn(page)) {
                result++;
            }
        }

        std::cout <<"Result is : " << result << std::endl;
        std::cout << "\t\tTest [" << i + 1 <<"]" << std::endl;

        int trueResult = 0;
        std::cin >> trueResult;

        if (trueResult == result) {
            std::cout << "\t\tTest [" << i + 1 << "]: PASSED\n\n";
        }
        else {
            std::cout << "\t\tTest [" << i + 1 << "]: WRONG ANSWER\n" << "Result is " << trueResult <<" but expected one is " << result << "\n\n";
        }

        fclose(ftest);
    }

    return 0;
}