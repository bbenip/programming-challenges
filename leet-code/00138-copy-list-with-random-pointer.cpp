/*
// Definition for a Node.
class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
      val = _val;
      next = NULL;
      random = NULL;
    }
};
*/

class Solution {
  public:
    Node* copyRandomList(Node* head) {
      unordered_map<Node*, Node*> originalToCopy;
      originalToCopy[nullptr] = nullptr;

      Node* auxiliaryHead = new Node(0);
      Node* previousNodeCopy = auxiliaryHead;
      Node* currentNode = head;

      while (currentNode != nullptr) {
        Node* currentNodeCopy = new Node(currentNode->val);
        previousNodeCopy->next = currentNodeCopy;

        previousNodeCopy = currentNodeCopy;
        currentNode = currentNode->next;
      }

      previousNodeCopy->next = nullptr;

      currentNode = head;
      Node* currentNodeCopy = auxiliaryHead->next;

      while (currentNode != nullptr) {
        originalToCopy[currentNode] = currentNodeCopy;

        currentNode = currentNode->next;
        currentNodeCopy = currentNodeCopy->next;
      }

      currentNode = head;
      currentNodeCopy = auxiliaryHead->next;

      while (currentNodeCopy != nullptr) {
        Node* originalRandomNode = currentNode->random;
        Node* copiedRandomNode = originalToCopy[originalRandomNode];

        currentNodeCopy->random = copiedRandomNode;

        currentNode = currentNode->next;
        currentNodeCopy = currentNodeCopy->next;
      }

      Node* headOfCopy = auxiliaryHead->next;

      auxiliaryHead->next = nullptr;
      delete auxiliaryHead;

      return headOfCopy;
    }
};
