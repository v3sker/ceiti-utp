#include <iostream>
#include <cstring>
#include "sort.h"
#include "find.h"

using namespace std;

int main(const int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "%s: no options and object\n", argv[0]);
    return 3;
  }

  if (argc == 2) {
    fprintf(stderr, "%s: no options or object\n", argv[0]);
    return 2;
  }

  if (argc == 3) {
    int length;
    int* array = nullptr;

    if (
      strcmp(argv[1], "-Si") == 0 || strcmp(argv[1], "-Sinsert") == 0
      || strcmp(argv[1], "-Ss") == 0 || strcmp(argv[1], "-Sselect") == 0
      || strcmp(argv[1], "-Sm") == 0 || strcmp(argv[1], "-Sminmax") == 0
      || strcmp(argv[1], "-Sw") == 0 || strcmp(argv[1], "-Sshow") == 0
      || strcmp(argv[1], "-Fl") == 0 || strcmp(argv[1], "-Flinear") == 0
      || strcmp(argv[1], "-Fb") == 0 || strcmp(argv[1], "-Fbinary") == 0
    ) {
      cout << "input array length: ";
      cin >> length;

      array = new int[length];

      for (int i = 0; i < length; i++) {
        cout << "array[" << i << "]: ";
        cin >> array[i];
      }
    }



    /*
     *   SORT FUNCTIONS
     */
    if (strcmp(argv[1], "-Si") == 0 || strcmp(argv[1], "-Sinsert") == 0) {
      SortInsert(array, length);
      delete [] array;
      return 0;
    }

    if (strcmp(argv[1], "-Ss") == 0 || strcmp(argv[1], "-Sselect") == 0) {
      SortSelect(array, length);
      delete [] array;
      return 0;
    }

    if (strcmp(argv[1], "-Sm") == 0 || strcmp(argv[1], "-Sminmax") == 0) {
      SortMinmax(array, length);
      delete [] array;
      return 0;
    }

    if (strcmp(argv[1], "-Sw") == 0 || strcmp(argv[1], "-Sshow") == 0) {
      SortShow(array, length);
      delete [] array;
      return 0;
    }
    /*
     *   END SORT FUNCTIONS
     */



    /*
     *   FIND FUNCTIONS
     */
    int target;
    if (
      strcmp(argv[1], "-Fl") == 0 || strcmp(argv[1], "-Flinear") == 0
      || strcmp(argv[1], "-Fb") == 0 || strcmp(argv[1], "-Fbinary") == 0
    ) {
      cout << "target: ";
      cin >> target;
    }

    if (strcmp(argv[1], "-Fl") == 0 || strcmp(argv[1], "-Flinear") == 0) {
      LinearSearch(array, length, target);
      delete [] array;
      return 0;
    }

    if (strcmp(argv[1], "-Fb") == 0 || strcmp(argv[1], "-Fbinary") == 0) {
      BinarySearch(array, length, target);
      delete [] array;
      return 0;
    }
    /*
     *   END SORT FUNCTIONS
     */



    fprintf(stderr, "unknown option '%s'\n", argv[1]);
    delete [] array;
    return 1;
  }

  if (argc > 3) {
    fprintf(stderr, "%s: too many strings\n", argv[0]);
    return 1;
  }

  return 0;
}