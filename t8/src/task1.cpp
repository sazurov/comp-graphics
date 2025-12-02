#include "../include/tasks.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void task1() {
  cout << "\nЗадание 1: Сортировка слов из файла\n" << endl;

  const string inputFile = "input.txt";
  const string outputFile = "output.txt";

  ifstream testFile(inputFile);
  if (!testFile.good()) {
    cout << "Файл " << inputFile << " не найден. Создаём тестовый файл..."
         << endl;
    ofstream createFile(inputFile);

    vector<string> testWords = {"яблоко", "банан",  "апельсин", "груша",
                                "киви",   "манго",  "виноград", "слива",
                                "персик", "абрикос"};

    for (const string &w : testWords) {
      createFile << w << "\n";
    }

    createFile.close();
    cout << "Тестовый файл создан с " << testWords.size() << " словами."
         << endl;
  }
  testFile.close();

  // Читаем слова из файла
  ifstream inFile(inputFile);
  if (!inFile.is_open()) {
    cout << "Ошибка: не удалось открыть файл " << inputFile << endl;
    return;
  }

  vector<string> words;
  string word;

  while (getline(inFile, word)) {
    if (!word.empty() && word.length() <= 80) {
      words.push_back(word);
    }

    if (words.size() >= 40) {
      break;
    }
  }
  inFile.close();

  cout << "Прочитано слов: " << words.size() << endl;

  sort(words.begin(), words.end());

  // Записываем отсортированные слова в выходной файл
  ofstream outFile(outputFile);
  if (!outFile.is_open()) {
    cout << "Ошибка: не удалось создать файл " << outputFile << endl;
    return;
  }

  for (const string &w : words) {
    outFile << w << endl;
  }
  outFile.close();

  cout << "Слова отсортированы и записаны в файл " << outputFile << endl;

  cout << "\nОтсортированные слова:" << endl;
  for (const string &w : words) {
    cout << w << endl;
  }
}
