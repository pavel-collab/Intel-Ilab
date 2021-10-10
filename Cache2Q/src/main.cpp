#include <iostream>
#include <unordered_map> // Hash Table
#include <list>          // List
#include <cassert>       // assert
#include <cmath>

#include "../include/cache.hpp"

int main() {

    std::cout << "Start the programm\n";

    size_t cache_size = 0;
    size_t N = 0;

    size_t counter = 0;
    int id = 0;

    std::cout << "Input cache size: " << std::endl;
    std::cin >> cache_size;
    std::cout << "Input N: " << std::endl;
    std::cin >> N;

    Cache2Q<int> Cache(cache_size);

    std::cout << "In capacity: " << Cache.In_.GetCapacity() << std::endl;
    std::cout << "Out capacity: " << Cache.Out_.GetCapacity() << std::endl;
    std::cout << "Hot capacity: " << Cache.Hot_.GetCapacity() << std::endl;


    while (N-- > 0) {
        std::cout << "Input page id: \n";
        std::cin >> id;
        int page = slow_get_page<int, int>(id); 
        
        if (Cache.CacheIn(page)) {
            counter++;
        }

        std::cout << "=============================" << std::endl;
        std::cout << "In size: " << Cache.In_.size_ << std::endl;
        std::cout << "In: ";
        PrintList<int>(Cache.In_.List);
        std::cout << "In size: " << Cache.Out_.size_ << std::endl;
        std::cout << "Out: ";
        PrintList<int>(Cache.Out_.List);
        std::cout << "In size: " << Cache.Hot_.size_ << std::endl;
        std::cout << "Hot: ";
        PrintList<int>(Cache.Hot_.List);
        std::cout << "=============================" << std::endl;
    }

    std::cout << "hit amount = " << counter << std::endl;
    std::cout << "End of pragramm." << std::endl;
    
    return 0;
}