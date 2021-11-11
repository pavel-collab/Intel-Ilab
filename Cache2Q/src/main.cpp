#include <iostream>
#include <unordered_map> // Hash Table
#include <list>          // List
#include <cassert>       // assert
#include <cmath>

#include "cache.hpp"

int main() {
    size_t cache_size = 0;
    size_t N = 0;

    size_t counter = 0;
    int id = 0;

    std::cin >> cache_size;
    assert(cache_size != 0);
    std::cin >> N;

    Cache2Q<int> Cache(cache_size);

    while (N-- > 0) {
        std::cin >> id;
        int page = slow_get_page<int, int>(id); 
        
        if (Cache.CacheIn(page)) {
            counter++;
        }
    }

    std::cout << "hit amount = " << counter << std::endl;
    
    return 0;
}