#pragma once
#include <iostream>

template <class NUM> class matrix {
private:
  unsigned _columns;
  unsigned _lines;
  NUM **content;

  void create_arr() {
    content = new NUM *[_lines];
    for (int i = 0; i < _lines; i++) {
      content[i] = new NUM[_columns];
    }
  }

  void delete_arr() {
    for (int i = 0; i < _lines; i++) {
      delete[] content[i];
    }
    delete[] content;
  }

public:
  matrix(const unsigned colums, const unsigned lines, NUM **matrix_arr)
      : _columns{colums}, _lines{lines} {
    create_arr();
    for (int i = 0; i < _lines; i++) {
      for (int j = 0; j < _columns; j++) {
        content[i][j] = matrix_arr[i][j];
      }
    }
  }

  ~matrix() { delete_arr(); }

  void print() {
    for (int i = 0; i < _lines; i++) {
      std::cout << "|";
      for (int j = 0; j < _columns; j++) {
        std::cout << "\t" << content[i][j] << " ";
      }
      std::cout << "|"
                << "\n";
    }
  }
};