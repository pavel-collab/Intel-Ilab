#include <iostream>
#include <unordered_map> // Hash Table
#include <list>          // List
#include <cassert>       // assert
#include <cmath>

enum {
    RESULT_NO_HIT = 0,
    RESULT_HIT_IN,
    RESULT_HIT_OUT,
    RESULT_HIT_HOT,
    RESULT_ERR
};

enum QT {
    IN = 0,
    OUT,
    HOT
};

// симулятор функции, которая получает число
template <typename Id, typename Page>
Page slow_get_page(Id id) {
    return (Page) id;
}

template <typename Page> 
struct ListNode {
    Page page_;
    QT   queue_t_;

    int ChangeQueueType(QT q_type);
};

// структура очереди
// основные поля структуры:
// capacity  -- размер очереди
// size      -- количество элементов в очереди
// std::list -- двусвязный список стандартной библиотеки
template <typename Page> 
struct Queue {
    private:
        size_t capacity_;
    public:
        size_t size_ = 0;
        std::list<ListNode<Page>> List;

        // -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

        // конструктор
        Queue(size_t q_capacity) :
            capacity_(q_capacity) {}

        // геттер размера очереди
        size_t GetCapacity() {return capacity_;}
        // функция проверяет заполненость очереди
        bool IsQueueFull() {
            return size_ == GetCapacity();
        }
};

template <typename Page> 
struct Cache2Q {
    private:
        size_t cache_size_; // полный размер кэша (сумма размеров очередей)
        using List_Iter = typename std::list<ListNode<Page>>::iterator;
        using Map_Iter = typename std::unordered_map<Page, List_Iter>::iterator;
    public:
        
        // делим очееди в отношении In:Out:Hot = 2:2:6
        Queue<Page> In_;
        Queue<Page> Out_;
        Queue<Page> Hot_;

        // хэш-таблица
        // в хэш-таблице лежат пары: ключ(страница) - итератор списка
        std::unordered_map<Page, List_Iter> Map_;

        // -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

        // конструктор
        Cache2Q(size_t cache_size) :
            cache_size_(cache_size), 
            In_(((size_t) (trunc(cache_size * 0.2) >= 1) ? trunc(cache_size * 0.2) : 1)),
            Out_(((size_t) (trunc(cache_size * 0.2) >= 1) ? trunc(cache_size * 0.2) : 1)),
            Hot_((size_t) (cache_size - In_.GetCapacity() - Out_.GetCapacity() >= 1) ? cache_size - In_.GetCapacity() - Out_.GetCapacity() : 1), 
            Map_() {};
        
        ~Cache2Q() {}

        // -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
        // низкоуровневые функции
        // функция удаляет страницу из кэша
        int DeletePage(Queue<Page> *queue, Map_Iter mpit);
        int MovePage(Queue<Page> *q_from, Queue<Page> *q_dst, List_Iter lstit);
        // -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
        

        // проверяем, есть ли совпадение в хэштаблице
        Map_Iter CacheHit(Page page) {
            return Map_.find(page);
        }

        int CacheIn(Page page);
};

template <typename Page>
int ListNode<Page>::ChangeQueueType(QT q_type) {
    queue_t_ = q_type;
    return 0;
}

template <typename Page>
int Cache2Q <Page>::DeletePage(Queue<Page> *queue, Map_Iter mpit) {
    queue->List.pop_back();
    queue->size_--;
    Map_.erase(mpit);
    return 0;
}

template <typename Page>
int Cache2Q <Page>::MovePage(Queue<Page> *q_from, Queue<Page> *q_dst, List_Iter lstit) {
    q_from->size_--;
    q_dst->size_++;
    q_dst->List.splice(q_dst->List.begin(), q_from->List, lstit);
    return 0;
}

template <typename Page> 
int Cache2Q <Page>::CacheIn(Page page) {
    Map_Iter base = CacheHit(page);

    if (base == Map_.end()) {
        if (In_.IsQueueFull()) {
            if (Out_.IsQueueFull()) {
                DeletePage(&Out_, Map_.find(Out_.List.back().page_));
            }
            In_.List.back().ChangeQueueType(OUT);

            List_Iter lstit = In_.List.begin();
            std::advance(lstit, In_.List.size() - 1);
            MovePage(&In_, &Out_, lstit);
        }

        // insert new page to the cache
        // создаем новый ListNode
        // помещаем в него значение page и значение очереди In
        // кладем на голову очереди In
        // заносим в HT
        ListNode<Page> lst_node = {page, IN};
        In_.List.push_front(lst_node);
        In_.size_++;

        Map_.insert({page, In_.List.begin()});
        return RESULT_NO_HIT;
    }

    switch (base->second->queue_t_) {
        case IN: {
            return RESULT_HIT_IN; 
            break;
        }
        case OUT: {
            if (Hot_.IsQueueFull()) {
                DeletePage(&Hot_, Map_.find(Hot_.List.back().page_));
            }
            List_Iter lstit = base->second;
            lstit->ChangeQueueType(HOT);
            MovePage(&Out_, &Hot_, lstit);

            return RESULT_HIT_OUT;
            break;
        }
        case HOT: {
            if (base->second == Hot_.List.begin()) return RESULT_HIT_HOT;
            else {
                MovePage(&Hot_, &Hot_, Map_.find(page)->second);
                return RESULT_HIT_HOT;
            }
            break;
        }
        default: {
            return RESULT_ERR;
            break;
        }
    }
}

template <typename Page>
int PrintList(std::list<ListNode<Page>> List) {
    for (auto i = List.begin(); i != List.end(); i++) {
        std::cout << i->page_ << " "; 
    }
    std::cout << std::endl;
    return 0;
}