#include <iostream>
#include <cassert>
#include "../include/cache.hpp"

int main() {

    FILE* ftest;

    ftest = freopen ("mytest.txt", "r", stdin);
    assert(ftest != nullptr);

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

    std::cout << "\t\tTest [" << 1 <<"]" << std::endl;

    int trueResult = 0;

    std::cin >> trueResult;

    if (trueResult == result) {

        std::cout << "\t\t\t\tTest [" <<  1<< "]: PASSED\n\n";
    }
    else {

        std::cout << "\t\tTest [" << 1 << "]: WRONG ANSWER\n" << "Result is " << trueResult <<" but expected one is " << result << "\n\n";
    }

    fclose (ftest);

    return 0;
}