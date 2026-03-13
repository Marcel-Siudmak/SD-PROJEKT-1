#include "doubly_linked_list.hpp"
#include <iostream>

int main() {
  doubly_linked_list<int> list;
  int choice;
  while (true) {
    system("clear");

    std::cout << "\n";
    list.display();
    std::cout << "\n";
    std::cout << "1. Push back\n";
    std::cout << "2. Push front\n";
    std::cout << "3. Insert\n";
    std::cout << "4. Pop back\n";
    std::cout << "5. Pop front\n";
    std::cout << "6. Remove\n";
    std::cout << "7. Find\n";
    std::cout << "8. Display\n";
    std::cout << "9. Get size\n";
    std::cout << "10. Clear\n";
    std::cout << "11. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
      int value;
      std::cout << "Enter value: ";
      std::cin >> value;
      list.push_back(value);
      break;
    case 2:
      std::cout << "Enter value: ";
      std::cin >> value;
      list.push_front(value);
      break;
    case 3:
      std::cout << "Enter value: ";
      std::cin >> value;
      std::cout << "Enter index: ";
      int index;
      std::cin >> index;
      list.insert(value, index);
      break;
    case 4:
      list.pop_back();
      break;
    case 5:
      list.pop_front();
      break;
    case 6:
      std::cout << "Enter index: ";
      std::cin >> index;
      list.remove(index);
      break;
    case 7:
      std::cout << "Enter value: ";
      std::cin >> value;
      std::cout << list.find(value) << std::endl;
      break;
    case 8:
      list.display();
      break;
    case 9:
      std::cout << list.get_size() << std::endl;
      break;
    case 10:
      list.clear();
      break;
    case 11:
      return 0;
    default:
      std::cout << "Invalid choice\n";
      break;
    }
  }
}