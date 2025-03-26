template <typename T> class Node {
private:
  T data;

public:
  Node<T> *nextNode;
  Node(T newData);
  ~Node();
  T getData();
};

template <typename T> class Stack {
private:
  Node<T> *headNode;

public:
  Stack();
  ~Stack();
  void push(T newData);
  void pop();
  T read();
};
