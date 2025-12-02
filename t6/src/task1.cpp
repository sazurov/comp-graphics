#include "../include/tasks.h"
#include <iostream>

using namespace std;

void swapPairs(int *arr, int size) {
  for (int i = 0; i < size - 1; i += 2) {
    int temp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = temp;
  }
}

void task1() {
  cout << "\nЗадание 1: Обмен четных и нечетных элементов\n" << endl;

  const int SIZE = 6;
  int *arr = new int[SIZE];

  cout << "Заполните массив:" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << "Введите " << (i + 1) << "-й элемент: ";
    cin >> arr[i];
  }

  cout << "\nИсходный массив: ";
  for (int i = 0; i < SIZE; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  swapPairs(arr, SIZE);

  cout << "Измененный массив: ";
  for (int i = 0; i < SIZE; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  delete[] arr;
}
