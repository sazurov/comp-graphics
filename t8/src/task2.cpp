#include "../include/tasks.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void task2() {
  cout << "\nЗадание 2: Работа с числами в файлах\n" << endl;

  const string file1 = "primer1.txt";
  const string file2 = "primer2.txt";

  // Ввод числа и сохранение в файл
  double number;
  cout << "Введите число для сохранения в " << file1 << ": ";
  cin >> number;

  ofstream outFile1(file1);
  if (!outFile1.is_open()) {
    cout << "Ошибка: не удалось создать файл " << file1 << endl;
    return;
  }
  outFile1 << number;
  outFile1.close();

  cout << "Число " << number << " сохранено в файл " << file1 << endl;

  // Чтение числа из файла
  ifstream inFile1(file1);
  if (!inFile1.is_open()) {
    cout << "Ошибка: не удалось открыть файл " << file1 << endl;
    return;
  }

  double readNumber;
  if (!(inFile1 >> readNumber)) {
    cout << "В файле строка. Необходимо число" << endl;
    inFile1.close();
    return;
  }
  inFile1.close();

  cout << "Прочитано число из файла: " << readNumber << endl;

  // Вычисление 50% и сохранение в другой файл
  double fiftyPercent = readNumber * 0.5;

  ofstream outFile2(file2);
  if (!outFile2.is_open()) {
    cout << "Ошибка: не удалось создать файл " << file2 << endl;
    return;
  }
  outFile2 << fiftyPercent;
  outFile2.close();

  cout << "50% от числа (" << fiftyPercent << ") сохранено в файл " << file2
       << endl;

  // Демонстрация проверки на строку
  cout << "\nТеперь попробуем добавить строку в " << file1 << "..." << endl;
  cout << "Перезапустите программу и выберите задание 2 снова," << endl;
  cout << "но перед этим откройте " << file1 << " и замените число на текст."
       << endl;
}
