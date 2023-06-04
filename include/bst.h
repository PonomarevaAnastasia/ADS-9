// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>

template <typename T>
class BST {
 private:
  struct Node {
    T work;
    int count;
    Node* left, * right;
  };
  Node* root = nullptr;
  Node* addNodeTree(Node*, const T&);
  int searchNodeTree(Node*, const T&);
  int getDepthTree(Node*);
 public:
  void addNode(const T&);
  int search(const T&);
  int depth();
};


template<class T>
typename BST<T>::Node* BST<T>::addNodeTree(Node* root, const T& work_) {
  if (root == nullptr) {
    root = new Node;
    root->v = work_;
    root->count = 1;
    root->left = root->right = nullptr;
  } else if (root->work > work_) {
      root->left = addNodeTree(root->left, work_);
  } else if (root->work < work_) {
      root->right = addNodeTree(root->right, work_);
  } else {
      root->count++;
  }
  return root;
}

template<class T>
void BST<T>::addNode(const T& work_) {
  root = addNodeTree(root, work_);
}

template<class T>
int BST<T>::searchNodeTree(Node* root, const T& work_) {
  if (root == nullptr) {
    return 0;
  } else if (root->work > work_) {
      return searchNodeTree(root->left, work_);
  } else if (root->work < work_) {
      return searchNodeTree(root->right, work_);
  } else {
    return root->count;
  }
  return 0;
}

template<class T>
int BST<T>::search(const T& work_) {
  return searchNodeTree(root, work_);
}

template<class T>
int BST<T>::getDepthTree(Node* root) {
  if (root == nullptr)
    return 0;
  int leftDepth = getDepthTree(root->left);
  int rightDepth = getDepthTree(root->right);
  if (leftDepth > rightDepth)
    return leftDepth + 1;
  else
    return rightDepth + 1;
}

template<class T>
int BST<T>::depth() {
  return getDepthTree(root) - 1;
}
#endif  // INCLUDE_BST_H_
