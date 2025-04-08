#include <iostream>
#include <chrono>
#include <cmath>
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

  const auto end_time = high_resolution_clock::now();
  const double real_time = duration<double, std::micro>(end_time - start_time).count();

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

    const int mid = left + (right - left) / 2;

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

  const auto end_time = high_resolution_clock::now();
  const double real_time = duration<double, micro>(end_time - start_time).count();

  result.index = -1;
  result.steps = steps;
  result.proc_cycles = proc_cycles;
  result.real_time = real_time;

  ShowSearchResults(result, "BINARY");
}



void JumpSearch(const int* arr, const int& arrLength, const int& target) {
  int steps = 0;
  int proc_cycles = 0;

  SearchResult result = {
    arr,
    arrLength,
    target
  };

  const auto start_time = high_resolution_clock::now();

  const int step = static_cast<int>(::sqrt(arrLength));
  int prev = 0;

  while (prev < arrLength && arr[prev] < target) {
    steps++;
    proc_cycles += 3;

    prev += step;
  }

  if (prev >= arrLength) {
    const auto end_time = high_resolution_clock::now();
    const double real_time = duration<double, micro>(end_time - start_time).count();

    result.index = -1;
    result.steps = steps;
    result.proc_cycles = proc_cycles;
    result.real_time = real_time;

    ShowSearchResults(result, "JUMP");
    return;
  }

  for (int i = prev - step; i < arrLength && i <= prev; i++) {
    steps++;
    proc_cycles += 2;

    if (arr[i] == target) {
      const auto end_time = high_resolution_clock::now();
      const double real_time = duration<double, micro>(end_time - start_time).count();

      result.index = i;
      result.steps = steps;
      result.proc_cycles = proc_cycles;
      result.real_time = real_time;

      ShowSearchResults(result, "JUMP");
      return;
    }
  }

  const auto end_time = high_resolution_clock::now();
  const double real_time = duration<double, micro>(end_time - start_time).count();

  result.index = -1;
  result.steps = steps;
  result.proc_cycles = proc_cycles;
  result.real_time = real_time;

  ShowSearchResults(result, "JUMP");
}



void FibonacciSearch(const int* arr, const int& arrLength, const int& target) {
    int steps = 0;
    int proc_cycles = 0;

    SearchResult result = {
        arr,
        arrLength,
        target
    };

    const auto start_time = high_resolution_clock::now();

    int m2 = 0;
    int m1 = 1;
    int m = m1 + m2;

    while (m < arrLength) {
        m2 = m1;
        m1 = m;
        m = m1 + m2;
        steps++;
        proc_cycles += 3;
    }

    int offset = -1;

    while (m > 1) {
        steps++;
        proc_cycles += 4;

        int i = (offset + m2 < arrLength - 1) ? (offset + m2) : (arrLength - 1);

        if (arr[i] < target) {
            m = m1;
            m1 = m2;
            m2 = m - m1;
            offset = i;
        }
        else if (arr[i] > target) {
            m = m2;
            m1 = m1 - m2;
            m2 = m - m1;
        }
        else {
            const auto end_time = high_resolution_clock::now();
            const double real_time = duration<double, micro>(end_time - start_time).count();

            result.index = i;
            result.steps = steps;
            result.proc_cycles = proc_cycles;
            result.real_time = real_time;

            ShowSearchResults(result, "FIBONACCI");
            return;
        }
    }

    if (m1 && arr[offset + 1] == target) {
        const auto end_time = high_resolution_clock::now();
        const double real_time = duration<double, micro>(end_time - start_time).count();

        result.index = offset + 1;
        result.steps = steps;
        result.proc_cycles = proc_cycles;
        result.real_time = real_time;

        ShowSearchResults(result, "FIBONACCI");
        return;
    }

    const auto end_time = high_resolution_clock::now();
    const double real_time = duration<double, micro>(end_time - start_time).count();

    result.index = -1;
    result.steps = steps;
    result.proc_cycles = proc_cycles;
    result.real_time = real_time;

    ShowSearchResults(result, "FIBONACCI");
}



void InterpSearch(const int* arr, const int& arrLength, const int& target) {
    int steps = 0;
    int proc_cycles = 0;

    SearchResult result = {
        arr,
        arrLength,
        target
    };

    const auto start_time = high_resolution_clock::now();

    int low = 0, high = arrLength - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        steps++;
        proc_cycles += 5;

        if (low == high) {
            if (arr[low] == target) {
                const auto end_time = high_resolution_clock::now();
                const double real_time = duration<double, micro>(end_time - start_time).count();

                result.index = low;
                result.steps = steps;
                result.proc_cycles = proc_cycles;
                result.real_time = real_time;

                ShowSearchResults(result, "INTERPOLATION");
                return;
            }
            break;
        }

        const int pos = low + static_cast<double>(high - low) / (arr[high] - arr[low]) * (target - arr[low]);

        if (pos < low || pos > high) break;

        proc_cycles += 3;

        if (arr[pos] == target) {
            const auto end_time = high_resolution_clock::now();
            const double real_time = duration<double, micro>(end_time - start_time).count();

            result.index = pos;
            result.steps = steps;
            result.proc_cycles = proc_cycles;
            result.real_time = real_time;

            ShowSearchResults(result, "INTERPOLATION");
            return;
        }

        if (arr[pos] > target) {
            high = pos - 1;
        } else {
            low = pos + 1;
        }
    }

    const auto end_time = high_resolution_clock::now();
    const double real_time = duration<double, micro>(end_time - start_time).count();

    result.index = -1;
    result.steps = steps;
    result.proc_cycles = proc_cycles;
    result.real_time = real_time;

    ShowSearchResults(result, "INTERPOLATION");
}



void ExponentialSearch(const int* arr, const int& arrLength, const int& target) {
    int steps = 0;
    int proc_cycles = 0;

    SearchResult result = {arr, arrLength, target};

    const auto start_time = high_resolution_clock::now();

    if (arrLength == 0) {
        result.index = -1;
        ShowSearchResults(result, "EXPONENTIAL");
        return;
    }

    if (arr[0] == target) {
        result.index = 0;
        ShowSearchResults(result, "EXPONENTIAL");
        return;
    }

    int i = 1;
    while (i < arrLength && arr[i] <= target) {
        steps++;
        proc_cycles += 3;
        i *= 2;
    }

    BinarySearch(arr + i / 2, min(i, arrLength) - i / 2, target);

    const auto end_time = high_resolution_clock::now();
    result.real_time = duration<double, std::micro>(end_time - start_time).count();
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