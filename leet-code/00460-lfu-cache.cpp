template <class T>
class DoublyLinkedList {
  private:
    struct Node {
      T value;

      Node* previous;
      Node* next;

      Node(T value, Node* previous = nullptr, Node* next = nullptr)
        : value { value }, previous { previous }, next { next } {}
    };

    Node* front = nullptr;
    Node* back = nullptr;

    unordered_map<T*, Node*> valueToNode;

    int size = 0;

  public:
    DoublyLinkedList() {}

    ~DoublyLinkedList() {
      Node* node = front;

      while (node != nullptr) {
        Node* next = node->next;
        delete node;

        node = next;
      }
    }

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size == 0;
    }

    T* getFront() {
      if (size == 0) {
        throw runtime_error("illegal call to getFront on empty list");
      }

      return &(front->value);
    }

    T* getBack() {
      if (size == 0) {
        throw runtime_error("illegal call to getBack on empty list");
      }

      return &(back->value);
    }

    T* getPrevious(T* value) {
      if (!valueToNode.contains(value)) {
        throw invalid_argument("value not in the list");
      }

      Node* node = valueToNode[value];
      return &(node->previous->value);
    }

    T* getNext(T* value) {
      if (!valueToNode.contains(value)) {
        throw invalid_argument("value not in the list");
      }

      Node* node = valueToNode[value];

      if (node->next == nullptr) {
        return nullptr;
      }

      return &(node->next->value);
    }

    void pushFront(T value) {
      Node* node = new Node(value);

      if (size == 0) {
        front = node;
        back = node;
      } else {
        node->next = front;
        front->previous = node;
      }

      valueToNode[&(node->value)] = node;
      size += 1;

      front = node;
    }

    void pushBack(T value) {
      Node* node = new Node(value);

      if (size == 0) {
        front = node;
        back = node;
      } else {
        node->previous = back;
        back->next = node;
      }

      valueToNode[&(node->value)] = node;
      size += 1;

      back = node;
    }

    T* insertBefore(T* valueToInsertBefore, T newValue) {
      if (!valueToNode.contains(valueToInsertBefore)) {
        throw invalid_argument("valueToInsertBefore not in the list");
      }

      Node* nodeToInsertBefore = valueToNode[valueToInsertBefore];
      Node* previousNode = nodeToInsertBefore->previous;

      Node* newNode = new Node(newValue, previousNode, nodeToInsertBefore);

      if (previousNode != nullptr) {
        previousNode->next = newNode;
      }

      nodeToInsertBefore->previous = newNode;

      if (nodeToInsertBefore == front) {
        front = newNode;
      }

      valueToNode[&(newNode->value)] = newNode;
      size += 1;

      return &(newNode->value);
    }

    T* insertAfter(T* valueToInsertAfter, T newValue) {
      if (!valueToNode.contains(valueToInsertAfter)) {
        throw invalid_argument("valueToInsertAfter not in the list");
      }

      Node* nodeToInsertAfter = valueToNode[valueToInsertAfter];
      Node* nextNode = nodeToInsertAfter->next;

      Node* newNode = new Node(newValue, nodeToInsertAfter, nextNode);

      if (nextNode != nullptr) {
        nextNode->previous = newNode;
      }

      nodeToInsertAfter->next = newNode;

      if (nodeToInsertAfter == back) {
        back = newNode;
      }

      valueToNode[&(newNode->value)] = newNode;
      size += 1;

      return &(newNode->value);
    }

    void popFront() {
      if (size == 0) {
        throw runtime_error("illegal call to popBack with empty list");
      }

      remove(&(front->value));
    }

    void popBack() {
      if (size == 0) {
        throw runtime_error("illegal call to popBack with empty list");
      }

      remove(&(back->value));
    }

    void remove(T* value) {
      if (!valueToNode.contains(value)) {
        throw invalid_argument("value not in list");
      }

      Node* node = valueToNode[value];

      if (node == front) {
        front = node->next;
      }

      if (node == back) {
        back = node->previous;
      }

      Node* previousNode = node->previous;
      Node* nextNode = node->next;

      if (previousNode != nullptr) {
        previousNode->next = nextNode;
      }

      if (nextNode != nullptr) {
        nextNode->previous = previousNode;
      }

      valueToNode.erase(value);
      size -= 1;

      delete node;
    }
};

class LFUCache {
  private:
    // Forward declaration to reference in ElementNode
    struct FrequencyNode;

    struct ElementNode {
      int key;
      int value;
      FrequencyNode* frequencyNode;

      ElementNode(int key, int value, FrequencyNode* frequencyNode) :
        key { key },
        value { value },
        frequencyNode { frequencyNode } {}
    };

    struct FrequencyNode {
      int frequency;
      DoublyLinkedList<ElementNode> elementNodes;

      FrequencyNode(int frequency) : frequency { frequency } {}
    };

    const int capacity;
    int size = 0;

    unordered_map<int, ElementNode*> existingElements;
    DoublyLinkedList<FrequencyNode> frequencyNodes;

    void removeNode() {
      FrequencyNode* minFrequencyNode = frequencyNodes.getFront();
      ElementNode* leastRecentElement = minFrequencyNode->elementNodes.getFront();
      const int key = leastRecentElement->key;

      minFrequencyNode->elementNodes.popFront();
      existingElements.erase(key);

      if (minFrequencyNode->elementNodes.getSize() == 0) {
        frequencyNodes.popFront();
      }

      size -= 1;
    }

    void insertElement(const int key, const int value) {
      if (size == capacity) {
        removeNode();
      }

      const bool isFrequency1Node = (
        !frequencyNodes.isEmpty()
        && frequencyNodes.getFront()->frequency == 1
      );

      if (!isFrequency1Node) {
        frequencyNodes.pushFront({ 1 });
      }

      FrequencyNode* frequency1Node = frequencyNodes.getFront();
      ElementNode newElementNode(key, value, frequency1Node);
      frequency1Node->elementNodes.pushBack(newElementNode);

      existingElements[key] = frequency1Node->elementNodes.getBack();

      size += 1;
    }

    void updateExistingElement(const int key, const int value) {
      if (!existingElements.contains(key)) {
        throw invalid_argument("key not found");
      }

      ElementNode* existingElement = existingElements[key];
      FrequencyNode* currentFrequencyNode = existingElement->frequencyNode;

      FrequencyNode* nextFrequencyNode = frequencyNodes.getNext(
        currentFrequencyNode
      );

      const int currentFrequency = currentFrequencyNode->frequency;
      const int newFrequency = currentFrequency + 1;

      if (
        nextFrequencyNode == nullptr
        || nextFrequencyNode->frequency > newFrequency
      ) {
        FrequencyNode newFrequencyNode(newFrequency);

        nextFrequencyNode = frequencyNodes.insertAfter(
          currentFrequencyNode,
          newFrequencyNode
        );
      }

      currentFrequencyNode->elementNodes.remove(existingElement);

      if (currentFrequencyNode->elementNodes.getSize() == 0) {
        frequencyNodes.remove(currentFrequencyNode);
      }

      ElementNode newElementNode(key, value, nextFrequencyNode);
      nextFrequencyNode->elementNodes.pushBack(newElementNode);
      existingElements[key] = nextFrequencyNode->elementNodes.getBack();
    }

  public:
    LFUCache(const int capacity) : capacity { capacity } {}

    int get(const int key) {
      if (!existingElements.contains(key)) {
        return -1;
      }

      const int value = existingElements[key]->value;
      updateExistingElement(key, value);

      return value;
    }

    void put(const int key, const int value) {
      if (!existingElements.contains(key)) {
        insertElement(key, value);
      } else {
        updateExistingElement(key, value);
      }
    }
};
