#ifndef FIND_H
#define FIND_H



struct SearchResult {
  const int* arr;
  int arrLength;
  int target;
  int index;
  int steps;
  int proc_cycles;
  double real_time;
};

void LinearSearch(const int* arr, const int& arrLength, const int& target);
void BinarySearch(const int* arr, const int& arrLength, const int& target);
void ShowSearchResults(const SearchResult &result, const std::string &searchName);



#endif // FIND_H
