class MyLinkedList {
  private:
    struct Node {
      Node* previous;
      Node* next;

      int val;

      Node(int val, Node* previous = nullptr, Node* next = nullptr)
        : val { val }, previous { previous }, next { next } {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    int size = 0;

  public:
    MyLinkedList() {}

    ~MyLinkedList() {
      Node* node = head;

      while (node != nullptr) {
        Node* next = node->next;
        delete node;
        node = next;
      }
    }

    int get(int index) {
      if (index < 0 || index >= size) {
        return -1;
      }

      Node* node = head;

      for (int i = 0; i < index; ++i) {
        node = node->next;
      }

      return node->val;
    }

    void addAtHead(int val) {
      Node* node = new Node(val, nullptr, head);
      head = node;

      if (size == 0) {
        tail = node;
      } else {
        head->next->previous = head;
      }

      size += 1;
    }

    void addAtTail(int val) {
      Node* node = new Node(val, tail, nullptr);
      tail = node;

      if (size == 0) {
        head = node;
      } else {
        tail->previous->next = tail;
      }

      size += 1;
    }

    void addAtIndex(int index, int val) {
      if (index < 0 || index > size) {
        return;
      }

      if (index == 0) {
        addAtHead(val);
        return;
      }

      if (index == size) {
        addAtTail(val);
        return;
      }

      Node* node = head;

      for (int i = 1; i < index; ++i) {
        node = node->next;
      }

      Node* newNode = new Node(val, node, node->next);

      node->next->previous = newNode;
      node->next = newNode;

      size += 1;
    }

    void deleteAtIndex(int index) {
      if (index < 0 || index >= size) {
        return;
      }

      if (size == 1) {
        delete head;

        head = nullptr;
        tail = nullptr;

        size = 0;
        return;
      }

      if (index == 0) {
        Node* newHead = head->next;
        delete head;

        head = newHead;
        head->previous = nullptr;

        size -= 1;
        return;
      }

      Node* node = head;

      for (int i = 1; i < index; ++i) {
        node = node->next;
      }

      Node* nodeToDelete = node->next;
      node->next = node->next->next;
      delete nodeToDelete;

      if (index == size - 1) {
        tail = node;
      } else {
        node->next->previous = node;
      }

      size -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
