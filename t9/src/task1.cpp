#include "../include/tasks.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void task1() {
  cout << "\nРабота с ФИО в файлах\n" << endl;

  const string file1 = "file1.txt";
  const string file2 = "file2.txt";

  string fio;

  cout << "Введите ФИО: ";
  cin.ignore();
  getline(cin, fio);

  ofstream outFile1(file1, ios::trunc);
  if (!outFile1.is_open()) {
    cout << "Ошибка: не удалось открыть файл " << file1 << endl;
    return;
  }
  outFile1 << fio << endl;
  outFile1.close();

  cout << "ФИО добавлено в " << file1 << " (файл перезаписан)" << endl;

  ifstream inFile1(file1);
  if (!inFile1.is_open()) {
    cout << "Ошибка: не удалось открыть файл " << file1 << endl;
    return;
  }

  string readFio;
  getline(inFile1, readFio);
  inFile1.close();

  cout << "Прочитано из " << file1 << ": " << readFio << endl;

  // Дописываем в файл 2 (ios::app - режим добавления)
  ofstream outFile2(file2, ios::app);
  if (!outFile2.is_open()) {
    cout << "Ошибка: не удалось открыть файл " << file2 << endl;
    return;
  }
  outFile2 << readFio << endl;
  outFile2.close();

  cout << "ФИО добавлено в " << file2 << " (дописано в конец)" << endl;

  cout << "\n--- Содержимое " << file1 << " ---" << endl;
  ifstream displayFile1(file1);
  if (displayFile1.is_open()) {
    string line;
    while (getline(displayFile1, line)) {
      cout << line << endl;
    }
    displayFile1.close();
  }

  cout << "\n--- Содержимое " << file2 << " ---" << endl;
  ifstream displayFile2(file2);
  if (displayFile2.is_open()) {
    string line;
    while (getline(displayFile2, line)) {
      cout << line << endl;
    }
    displayFile2.close();
  }
}
