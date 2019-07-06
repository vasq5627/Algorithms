#include <iostream>
using namespace std;

int sort(int array[], int size) {
  int temp;
  for(int iteration = 0; iteration < size; iteration++) {
    for(int index = 0; index < size - 1; index++) {
      if(array[index] < array[index + 1]) {
        temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;
        }
      }
    }
    return array[size / 2];
}


int main() {
  int t = 0;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int size_of_array;
    cin >> size_of_array;
    int *array = new int[size_of_array];
    for (int i = 0; i < size_of_array; i++) {
      cin >> array[i];
    }
    cout << sort(size_of_array, array) << endl;
    delete[] array;
  }
  
  
