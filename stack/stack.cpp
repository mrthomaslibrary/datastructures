#include "stack.hpp"

template <typename T> Node<T>::Node(T newData) { data = newData; }

template <typename T> Node<T>::~Node() {}

template <typename T> T Node<T>::getData() { return data; }

template <typename T> Stack<T>::Stack() { headNode = nullptr; }

template <typename T> Stack<T>::~Stack() {}

template <typename T> void Stack<T>::push(T newData) {
  Node<T> *newNode = new Node(newData);
  if (!headNode) {
    headNode = newNode;
  } else {
    newNode->nextNode = headNode;
    headNode = newNode;
  }
}

template <typename T> void Stack<T>::pop() {
  Node<T> *currentNode = headNode;
  headNode = headNode->nextNode;
  currentNode->~Node();
}

template <typename T> T Stack<T>::read() { return headNode->getData(); }
