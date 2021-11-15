#include <iostream>
#include <unordered_map> // Hash Table
#include <list>          // List
#include <cassert>       // assert
#include <cmath>

#include "perfect_cache.hpp"

//TODO: написать Cmake для идеального кэша и для всего проекта в частности
//TODO: протестировать идеальный кэш (написать для него тестирующую программу или тесты)
//TODO: убрать комментарии на русском и лишние комментарии

int main() {
    size_t cache_size = 0;
    size_t N = 0;

    size_t counter = 0;
    int id = 0;

    std::cout << "Input cache capacity: ";
    std::cin >> cache_size;
    assert(cache_size != 0);

    std::cout << "Input inquiry amount: ";
    std::cin >> N;

    // список запросов
    int* inquiry_list = (int*) calloc(N, sizeof(int));

    PerfectCache<int> Cache(cache_size);

    // получаем список запросов
    for (int idx = 0; idx < N; idx++) {
        std::cin >> id;
        inquiry_list[idx] = slow_get_page<int, int>(id);
    }

    for (int idx = 0; idx < N; idx++) {
        // PrintList(Cache.List);
        if (Cache.CacheIn(inquiry_list[idx], inquiry_list, N, idx) == RESULT_HIT) {
            counter++;
        }        
    }

    std::cout << "hit amount = " << counter << std::endl;

    free(inquiry_list);
    
    return 0;
}