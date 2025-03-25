#include "forked_queue.hpp"

// ForkedNode Function

template <typename T> ForkedNode<T>::ForkedNode(T newData) {
  data = &newData;
  nextNode = nullptr;
}

template <typename T> T *ForkedNode<T>::getData() { return data; }

template <typename T> ForkedQueue<T>::ForkedQueue() { headNode = nullptr; }

template <typename T> void ForkedQueue<T>::insert(T newData) {
  ForkedNode<T> *newNode = new ForkedNode<T>(newData);
  if (headNode) {
    headNode = newNode;
  } else {
    int n = 1;
    ForkedNode<T> *currentNode = headNode;
    while (currentNode->nextNode) {
      currentNode = currentNode->nextNode;
      n++;
    }
    currentNode = headNode;
    for (int i = 0; i < n / 2; i++) {
      currentNode = currentNode->nextNode;
    }
    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;
  }
}

template <typename T> ForkedNode<T>::~ForkedNode() {}

template <typename T> T *ForkedQueue<T>::getBackData() {
  ForkedNode<T> *currentNode = headNode;
  while (currentNode->nextNode) {
    currentNode = currentNode->nextNode;
  }
  return currentNode->getData();
}

template <typename T> T *ForkedQueue<T>::getFrontData() {
  return headNode->getData();
}

template <typename T> void ForkedQueue<T>::deleteBack() {
  ForkedNode<T> *currentNode = headNode;
  while (currentNode->nextNode) {
    currentNode = currentNode->nextNode;
  }
  currentNode->~ForkedNode();
}

template <typename T> void ForkedQueue<T>::deleteFront() {
  ForkedNode<T> *currentNode = headNode;
  headNode = currentNode->nextNode;
  currentNode->~ForkedNode();
}
