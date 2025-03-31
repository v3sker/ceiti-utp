#include <iostream>
#include <chrono>
#include "find.h"

using namespace std;
using namespace std::chrono;

void LinearSearch(const int* arr, const int& arrLength, const int& target) {
  int steps = 0;
  int proc_cycles = 0;

  SearchResult result = {
    arr,
    arrLength,
    target
  };

  const auto start_time = high_resolution_clock::now();

  for (int i = 0; i < arrLength; i++) {
    steps++;
    proc_cycles += 4;

    if (arr[i] == target) {
      const auto end_time = high_resolution_clock::now();
      const double real_time = std::chrono::duration<double, std::micro>(end_time - start_time).count();

      result.index = i;
      result.steps = steps;
      result.proc_cycles = proc_cycles;
      result.real_time = real_time;

      ShowSearchResults(result, "LINEAR");
      return;
    }
  }

  auto end_time = high_resolution_clock::now();
  double real_time = duration<double, std::micro>(end_time - start_time).count();

  result.index = -1;
  result.steps = steps;
  result.proc_cycles = proc_cycles;
  result.real_time = real_time;

  ShowSearchResults(result, "LINEAR");
}



void BinarySearch(const int* arr, const int& arrLength, const int& target) {
  int steps = 0;
  int proc_cycles = 0;

  SearchResult result = {
    arr,
    arrLength,
    target
  };

  const auto start_time = high_resolution_clock::now();

  int left = 0, right = arrLength - 1;

  while (left <= right) {
    steps++;
    proc_cycles += 5;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      const auto end_time = high_resolution_clock::now();
      const double real_time = duration<double, micro>(end_time - start_time).count();

      result.index = mid;
      result.steps = steps;
      result.proc_cycles = proc_cycles;
      result.real_time = real_time;

      ShowSearchResults(result, "BINARY");
      return;
    }

    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  auto end_time = high_resolution_clock::now();
  double real_time = duration<double, micro>(end_time - start_time).count();

  result.index = -1;
  result.steps = steps;
  result.proc_cycles = proc_cycles;
  result.real_time = real_time;

  ShowSearchResults(result, "BINARY");
}



void ShowSearchResults(const SearchResult& result, const string& searchName) {
  const int n = result.arrLength;
  const int* vec = result.arr;
  const int key = result.target;

  cout << searchName << " SEARCH\n";
  cout << "number of items: " << n << endl;

  for (int i = 0; i < n; i++) {
    cout << "[" << i + 1 << "]: " << vec[i] << endl;
  }

  cout << "searching number: " << key << endl << endl;
  cout << "search result:\n";
  cout << "algo steps: " << result.steps << endl;
  cout << "proc cycles: " << result.proc_cycles << endl;
  cout << "real time: " << result.real_time << "s\n";
  cout << "array order: ";

  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  if (result.index != -1) {
    cout << "Array match: " << key << " on [" << result.index + 1 << "]\n";
  } else {
    cout << "No match found.\n";
  }
}