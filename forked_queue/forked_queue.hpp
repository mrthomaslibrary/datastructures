template <typename T> class ForkedNode {
private:
  T *data;

public:
  ForkedNode(T newData);
  T *getData();
  ForkedNode *nextNode;
  ~ForkedNode();
};

template <typename T> class ForkedQueue {
private:
  ForkedNode<T> *headNode;

public:
  ForkedQueue();
  T *getFrontData();
  T *getBackData();
  void insert(T newData);
  void deleteFront();
  void deleteBack();
};
