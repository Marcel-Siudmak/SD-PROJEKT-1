#include "benchmark.hpp"
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace fs = std::filesystem;

benchmark::benchmark(const std::string &dataset_name)
    : dataset_(dataset_name) {}

void result_exporter::export_to_csv(const BenchmarkResults &results,
                                    const std::string &dataset_name,
                                    const std::string &structure_name) {
#ifndef PROJECT_ROOT_DIR
#define PROJECT_ROOT_DIR "."
#endif

  fs::path results_dir = fs::path(PROJECT_ROOT_DIR) / "results" / dataset_name;
  if (!fs::exists(results_dir)) {
    fs::create_directories(results_dir);
  }
  fs::path csv_path = results_dir / (structure_name + ".csv");
  std::ofstream file(csv_path);

  if (!file) {
    std::cerr << "Failed to create result file: " << csv_path << "\n";
    return;
  }

  std::vector<int> all_n;
  if (!results.empty()) {
    for (const auto &[n, _] : results.begin()->second) {
      all_n.push_back(n);
    }
  }

  file << "Operacja / Rozmiar";
  for (int n : all_n) {
    file << ";" << n;
  }
  file << "\n";

  for (const auto &[operation_name, n_times] : results) {
    file << operation_name;
    for (int n : all_n) {
      auto it = n_times.find(n);
      if (it != n_times.end()) {
        file << ";" << std::fixed << std::setprecision(2) << it->second;
      } else {
        file << ";-";
      }
    }
    file << "\n";
  }

  file.close();
  std::cout << "Results exported to " << csv_path << "\n";
}
