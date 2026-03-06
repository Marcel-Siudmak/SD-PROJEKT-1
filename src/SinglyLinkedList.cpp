#include "SinglyLinkedList.hpp"
#include <iostream>

template <typename T> SinglyLinkedList<T>::SinglyLinkedList() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template <typename T> SinglyLinkedList<T>::~SinglyLinkedList() {
  clear(); // Zwalniamy pamięć przy zniszczeniu obiektu
}

template <typename T> void SinglyLinkedList<T>::push_front(T value) {
  SinglyNode<T> *newNode = new SinglyNode<T>(value);
  if (size == 0) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
  size++;
}

template <typename T> void SinglyLinkedList<T>::push_back(T value) {
  SinglyNode<T> *newNode = new SinglyNode<T>(value);
  if (size == 0) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
  size++;
}

template <typename T> void SinglyLinkedList<T>::insert(T value, int index) {
  if (index < 0 || index > size)
    return; // Zabezpieczenie

  if (index == 0) {
    push_front(value);
  } else if (index == size) {
    push_back(value);
  } else {
    SinglyNode<T> *newNode = new SinglyNode<T>(value);
    SinglyNode<T> *temp = head;
    // Przechodzimy do elementu przed miejscem wstawienia
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
  }
}

template <typename T> void SinglyLinkedList<T>::pop_front() {
  if (size == 0)
    return;

  SinglyNode<T> *temp = head;
  head = head->next;
  delete temp; // Ręczne zwalnianie pamięci

  size--;
  if (size == 0) {
    tail = nullptr; // Jeśli usunęliśmy ostatni element, tail też musi być puste
  }
}

template <typename T> void SinglyLinkedList<T>::pop_back() {
  if (size == 0)
    return;

  if (size == 1) {
    delete head;
    head = tail = nullptr;
  } else {
    SinglyNode<T> *temp = head;
    // Szukamy przedostatniego elementu
    while (temp->next != tail) {
      temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
  }
  size--;
}

template <typename T> void SinglyLinkedList<T>::remove(int index) {
  if (index < 0 || index >= size)
    return;

  if (index == 0) {
    pop_front();
  } else if (index == size - 1) {
    pop_back();
  } else {
    SinglyNode<T> *temp = head;
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    SinglyNode<T> *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    size--;
  }
}

template <typename T> bool SinglyLinkedList<T>::find(T value) {
  SinglyNode<T> *temp = head;
  while (temp != nullptr) {
    if (temp->data == value) {
      return true; // Znaleziono element [cite: 502]
    }
    temp = temp->next;
  }
  return false; // Nie znaleziono
}

template <typename T> void SinglyLinkedList<T>::display() {
  SinglyNode<T> *temp = head;
  while (temp != nullptr) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL\n";
}

template <typename T> void SinglyLinkedList<T>::clear() {
  while (size > 0) {
    pop_front(); // Zwalnia pamięć węzeł po węźle
  }
}

template <typename T> int SinglyLinkedList<T>::getSize() { return size; }

// =========================================================================
// JAWNA INSTANCJACJA SZABLONU (EXPLICIT INSTANTIATION)
// Gwarantuje, że kompilator wygeneruje kod dla listy przechowującej int.
// Bez tego miałbyś błędy linkera przy dzieleniu na .hpp i .cpp!
// =========================================================================
template class SinglyLinkedList<int>;