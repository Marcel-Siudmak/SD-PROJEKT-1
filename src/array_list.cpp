#include "array_list.hpp"
#include <iostream>

array_list::~array_list(){
    delete[] _arr;
}

array_list::array_list() : _arr(nullptr), _size(0), _capacity(0) {}; //pytanie czy chcemy na pusto dawac 0 size czy zakladamy ze bedzie ktos przynajmniej 1 element zaraz wsadzal
array_list::array_list(int cap) : _capacity(cap), _arr(new int[_capacity]), _size(0) {};
array_list::array_list(const array_list& other){
            _capacity = other._capacity;
            _size = other._size;
            _arr = new int[_capacity];
            for(int i = 0; i < _size; i++){
                _arr[i] = other._arr[i];
            }
        };
array_list::array_list(const array_list& other, int cap):_capacity(cap), _arr(new int[_capacity]), _size(other._size > cap? cap : other._size){
            for(int i = 0; i < _size; i++){
                _arr[i] = other._arr[i];
            }
        };

array_list& array_list::operator=(const array_list& other){
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

void array_list::display(){

    for(int i = 0; i < _size; i++){
        std::cout << '[' << _arr[i] << '] ';
        (i+1) % 10 == 0 ? std::cout << std::endl : std::cout << "";
    }
    std::cout << std::endl;
}

void array_list::clear(){
    delete[] _arr;
    _arr = nullptr;
    _size = 0;
    _capacity = 0;
}
