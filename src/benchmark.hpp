#pragma once

#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "IList.hpp"
#include "data_handler.hpp"

// Typ pomocniczy dla wygody - przechowuje wyniki: map<OperationName, map<N,
// Time>>
using BenchmarkResults = std::map<std::string, std::map<int, double>>;

class result_exporter {
public:
  static void export_to_csv(const BenchmarkResults &results,
                            const std::string &dataset_name,
                            const std::string &structure_name);
};

class benchmark {
public:
  // Konstruktor przypina nas do konkretnego datasetu zainicjalizowanego na
  // dysku
  explicit benchmark(const std::string &dataset_name);

  // Funkcja szablonowa, która odpala badanie danej struktury Listy
  // (dziedziczącej po IList) list_factory - funkcja lambda która potrafi
  // zwrócić *NOWĄ* zainstancjonowaną listę struktura - nawa list jaka pojawi
  // się w nazwie pliku (np. "singly_linked_list")
  template <typename ListType>
  void run_structure_tests(const std::string &structure_name,
                           std::function<ListType *()> list_factory) {
    BenchmarkResults results;

    // Przechodzimy po wszystkich punktach pomiarowych (N) z datasetu
    for (int n : dataset_.get_points()) {
      std::cout << "\n--- Testing " << structure_name << " for N=" << n
                << " ---\n";

      const auto &test_files = dataset_.get_test_files();
      size_t num_instances = test_files.size();

      // Tworzymy na bieżąco wektor wskaźników z lambd do ListType, wewnątrz
      // IList Możemy potraktować to jako IList<int>* dzięki polimorfizmowi.
      std::vector<IList<int> *> instances(num_instances);
      for (size_t i = 0; i < num_instances; ++i) {
        instances[i] = list_factory();
        dataset_.load_to_list(test_files[i], n, *instances[i]);
      }

      // 1. push_front
      results["push_front"][n] = measure_operation(
          instances, [](IList<int> *list) { list->push_front(999); });

      // 2. push_back
      results["push_back"][n] = measure_operation(
          instances, [](IList<int> *list) { list->push_back(999); });

      // 3. pop_front
      results["pop_front"][n] = measure_operation(
          instances, [](IList<int> *list) { list->pop_front(); });

      // 4. pop_back
      results["pop_back"][n] = measure_operation(
          instances, [](IList<int> *list) { list->pop_back(); });

      // OLAĆ PAMIĘĆ PO SOBIE (Dla wskaźników usunąć używając wirtualnego
      // destruktora)
      for (auto ptr : instances) {
        delete ptr;
      }
    }

    // Na koniec zrzucamy tabelę z tego testu do CSV wg schematu
    result_exporter::export_to_csv(results, dataset_.get_name(),
                                   structure_name);
  }

private:
  data_set dataset_;

  double measure_operation(const std::vector<IList<int> *> &instances,
                           const std::function<void(IList<int> *)> &operation) {
    long long total_nanoseconds = 0;

    for (auto list_instance : instances) {
      auto start = std::chrono::high_resolution_clock::now();

      operation(list_instance);

      auto end = std::chrono::high_resolution_clock::now();
      total_nanoseconds +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
              .count();
    }

    if (instances.empty())
      return 0.0;
    return static_cast<double>(total_nanoseconds) / instances.size();
  }
};
