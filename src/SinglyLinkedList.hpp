#pragma once
#include "IList.hpp"

// Struktura pojedynczego węzła listy
template <typename T> struct SinglyNode {
  T data;
  SinglyNode *next;

  // Konstruktor pomocniczy dla wygody
  SinglyNode(T val) : data(val), next(nullptr) {}
};

// Klasa listy jednokierunkowej dziedzicząca po IList
template <typename T> class SinglyLinkedList : public IList<T> {
private:
  SinglyNode<T> *head; // Wskaźnik na początek
  SinglyNode<T> *tail; // Wskaźnik na koniec
  int size;

public:
  SinglyLinkedList();
  ~SinglyLinkedList() override;

  // Operacje dodawania [cite: 498, 499, 500, 501]
  void push_front(T value) override;
  void push_back(T value) override;
  void insert(T value, int index) override;

  // Operacje usuwania [cite: 498, 499, 500, 501]
  void pop_front() override;
  void pop_back() override;
  void remove(int index) override;

  // Wyszukiwanie [cite: 502]
  bool find(T value) override;

  // Metody pomocnicze
  void display() override;
  void clear() override;
  int getSize() override;
};