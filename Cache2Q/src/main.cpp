#include <iostream>
#include <unordered_map> // Hash Table
#include <list>          // List
#include <cassert>       // assert
#include <cmath>

#include "cache.hpp"

int main() {
    size_t cache_size = 0;
    size_t N = 0;

    // счетчик хитов
    size_t counter = 0;
    int id = 0;

    // вводим размер кэша и количество запросов
    std::cin >> cache_size >> N;

    Cache2Q<int> Cache(cache_size);

    // обрабатываем запросы в цикле
    while (N-- > 0) {
        std::cin >> id;

        int page = slow_get_page<int, int>(id); 
        
        if (Cache.CacheIn(page)) {
            counter++;
        }
    }

    // выводим в консоль количество хитов
    std::cout << "hit amount = " << counter << std::endl;
    
    return 0;
}