#include <iostream>
#include <cassert>
#include "../include/cache.hpp"

unsigned numTests = 8;

int main() {

    const char* nameTests[numTests] = {"utest1.txt", "utest2.txt", "utest3.txt", "utest4.txt", "utest5.txt",
                                       "utest6.txt", "utest7.txt", "utest8.txt"};

    std::string str[numTests];

    FILE* ftest;
    for (int i = 0; i < numTests; i++) {
        ftest = freopen (nameTests[i], "r", stdin);
        assert(ftest != nullptr);

        // if (ftest == NULL) {
        //     perror ("File open error:");
        //     return -1;
        // }

        size_t cacheSize = 0;
        size_t numPages  = 0;
        int id = 0;

        std::cin >> cacheSize >> numPages;
        assert(std::cin.good());

        Cache2Q<int> Cache{cacheSize};
        int result = 0;

        // int result = CacheHit(Cache, numPages);

        while (numPages-- > 0) {
            // std::cout << "Input page id: \n";
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

            std::cout << "\t\t\t\tTest [" << i + 1<< "]: PASSED\n\n";
        }
        else {

            std::cout << "\t\tTest [" << i + 1 << "]: WRONG ANSWER\n" << "Result is " << trueResult <<" but expected one is " << result << "\n\n";
        }

        fclose (ftest);
    }

    return 0;
}