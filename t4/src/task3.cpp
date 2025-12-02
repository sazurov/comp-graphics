#include "../include/tasks.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void task3() {
  cout << "\n=== Задание 3: Сортировка и поиск в массиве ===" << endl;

  int n;
  cout << "Введите размер массива: ";
  cin >> n;

  vector<int> arr(n);

  cout << "Введите элементы массива:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Элемент " << (i + 1) << ": ";
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  cout << "\nОтсортированный массив: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  int search;
  cout << "\nВведите число для поиска: ";
  cin >> search;

  bool found = false;
  for (int i = 0; i < n; i++) {
    if (arr[i] == search) {
      cout << "Число найдено на позиции: " << i << " (индекс)" << endl;
      cout << "Или на позиции: " << (i + 1) << " (номер элемента)" << endl;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "Число не найдено" << endl;
  }
}
