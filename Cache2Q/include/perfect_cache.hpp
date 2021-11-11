#include <iostream>
#include <unordered_map> // Hash Table
#include <list>          // List
#include <cassert>       // assert

enum {
    RESULT_NO_HIT = 0,
    RESULT_HIT,
    RESULT_ERR
};

// симулятор функции, которая получает число
template <typename Id, typename Page>
Page slow_get_page(Id id) {
    return (Page) id;
}

template <typename Page>
struct PerfectCache {
    private:
        size_t cache_capacity_;
        using List_Iter = typename std::list<Page>::iterator;
        using Map_Iter = typename std::unordered_map<Page, List_Iter>::iterator;
    public:
        // список страниц в кэше
        std::list<Page> List;
        // хэш-таблица
        // в хэш-таблице лежат пары: ключ(страница) - итератор списка
        std::unordered_map<Page, List_Iter> Map_;

        size_t lists_size_;

        // конструктор
        PerfectCache(size_t cache_capasity) :
            cache_capacity_(cache_capacity_),
            lists_size_(0),  
            Map_() {};
        
        ~PerfectCache() {}

        size_t GetCapacity() {
            return cache_capacity_;
        }

        bool IsCacheFull() {
            return lists_size_==GetCapacity();
        }

        // проверяем, есть ли совпадение в хэштаблице
        Map_Iter CacheHit(Page page) {
            return Map_.find(page);
        }

        // на вход подется вставляемая страница, массив запросов, количество элементов в массиве
        int CacheIn(Page page, Page* inquiry_list, int future_iqr_amnt);
};

template <typename Page> 
int PerfectCache <Page>::CacheIn(Page page, Page* inquiry_list, int future_iqr_amnt) {
    Map_Iter base = CacheHit(page);

    // проверяем, есть ли вставляемая страница в кэше
    if (base != Map_.end()) {
        // если есть -- говорим, что случился хит
        return RESULT_HIT;
    }


    
    // если кэш полон, то начинаем танцы с бубном
    if (IsCacheFull()) {
        
        List_Iter the_worst = List.begin();
        int poisoned_idx = 0;

        // выбираем какую страницу исключить из кэша по алгоритму OPT
        // обрабатываем каждый элемент кэша, если он встречается позже остальных -- запоминаем его
        List_Iter lst_it = List.begin();
        while (lst_it++ != List.end()) {
            for (int idx = poisoned_idx; idx < future_iqr_amnt; idx++) {
                if ((*lst_it == inquiry_list[idx]) && (idx >= poisoned_idx)) {
                    poisoned_idx = idx;
                    the_worst = lst_it;
                    break;
                }
            }
        }

        // удаляем "худший элемент"

        // // если the_worst остался равным нулю, значит выбрасываем их кэша любой элемент (в нашем случае первый)
        // if (the_worst == nullptr)
        //     the_worst = List.begin();
        
        // удаляем элемент из списка, из хеш-таблицы и уменьшаем количество элементов в кэше
        List.erase(the_worst);
        Map_.erase(Map_.find(*the_worst));
        lists_size_--;
    }

    // кладем новый элемент на голову списка
    List.push_front(page);
    lists_size_++;
    Map_.insert({page, List.begin()});

    return RESULT_NO_HIT;
}

template <typename Page>
int PrintList(std::list<Page> List) {
    for (auto i = List.begin(); i != List.end(); i++) {
        std::cout << i->page_ << " "; 
    }
    std::cout << std::endl;
    return 0;
}