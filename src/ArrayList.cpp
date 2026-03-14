#include "ArrayList.hpp"
#include <iostream>

ArrayList::~ArrayList(){
    delete[] _arr;
}

ArrayList::ArrayList() : _arr(nullptr), _size(0), _capacity(0) {}; //pytanie czy chcemy na pusto dawac 0 size czy zakladamy ze bedzie ktos przynajmniej 1 element zaraz wsadzal
ArrayList::ArrayList(int cap) : _capacity(cap), _arr(new int[_capacity]), _size(0) {};
ArrayList::ArrayList(const ArrayList& other){
            _capacity = other._capacity;
            _size = other._size;
            _arr = new int[_capacity];
            for(int i = 0; i < _size; i++){
                _arr[i] = other._arr[i];
            }
        };
ArrayList::ArrayList(const ArrayList& other, int cap):_capacity(cap), _arr(new int[_capacity]), _size(other._size > cap? cap : other._size){
            for(int i = 0; i < _size; i++){
                _arr[i] = other._arr[i];
            }
        };

ArrayList& ArrayList::operator=(const ArrayList& other){
            if(this == &other) return *this;
            delete[] _arr;
            _capacity = other._capacity;
            _size = other._size;
            _arr = new int[_capacity];
            for(int i = 0; i < _size; i++){
                _arr[i] = other._arr[i];
            }
            return *this;
        };

void ArrayList::display(){

    for(int i = 0; i < _size; i++){
        std::cout << '[' << _arr[i] << '] ';
        (i+1) % 10 == 0 ? std::cout << std::endl : std::cout << "";
    }
    std::cout << std::endl;
}

void ArrayList::clear(){
    delete[] _arr;
    _arr = nullptr;
    _size = 0;
    _capacity = 0;
}
