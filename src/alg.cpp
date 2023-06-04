// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::ifstream file(filename);
  BST<std::string> tree;
  std::string word;

  if (file) {
    while (!file.eof()) {
      work.erase();
      while (1) {
        char sum = file.get();
        if (sum > 96 && sum < 123) {
          word += symbol;
        } else if (sum > 64 && sum < 91) {
            sum += 32;
            work += sum;
        } else {
          break;
        }
      }
      if (!work.empty()) {
        tree.addNode(word);
      } else {
        continue;
      }
    }
    file.close();
  } else {
    std::cout << "File was not read correctly." << std::endl;
  }
  return tree;
}
