#pragma once
#include "IList.hpp"

class ArrayList : public IList<int> {
    private:
        int* _arr;
        int _size;
        int _capacity;
    public:
        ArrayList(){};
        ArrayList(int cap){};
        ArrayList(const ArrayList& other){};
        ArrayList(const ArrayList& other, int cap){};
        ~ArrayList();

        ArrayList& operator=(const ArrayList& other){};
        
        void push_front(int value) override = 0;
        void push_back(int value) override = 0;
        void insert(int value, int index) override = 0;

        void pop_front() override = 0;
        void pop_back() override = 0;
        void remove(int index) override = 0;

        bool find(int value) override = 0;

        void display() override = 0;
        void clear() override = 0;
        int getSize() override = 0;
};
