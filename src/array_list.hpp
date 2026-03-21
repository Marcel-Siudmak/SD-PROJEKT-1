#pragma once
#include "IList.hpp"

template <class T> 
class array_list : public IList<T> {
    private:
        T* _arr;
        int _size;
        int _capacity;
        void resize(int new_capacity){};
    public:
        array_list(){};
        array_list(int cap){};
        array_list(const array_list& other){};
        array_list(const array_list& other, int cap){};
        ~array_list();

        array_list& operator=(const array_list& other){};
        
        void push_front(T value) override = 0;
        void push_back(T value) override = 0;
        void insert(T value, int index) override = 0;

        void pop_front() override = 0;
        void pop_back() override = 0;
        void remove(int index) override = 0;

        bool find(T value) override = 0;

        void display() override = 0;
        void clear() override = 0;
        int get_size() override = 0;
};
