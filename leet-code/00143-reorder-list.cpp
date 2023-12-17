/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
  private:
    int getListSize(ListNode* head) {
      int size = 0;

      while (head != nullptr) {
        size += 1;
        head = head->next;
      }

      return size;
    }

    ListNode* reverseList(ListNode* head) {
      ListNode* previousNode = nullptr;
      ListNode* currentNode = head;

      while (currentNode != nullptr) {
        ListNode* nextNode = currentNode->next;

        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
      }

      return previousNode;
    }

  public:
    void reorderList(ListNode* head) {
      const int size = getListSize(head);

      if (size <= 1) {
        return;
      }

      const int midpoint = size - (size / 2);

      ListNode* node = head;

      for (int i = 1; i < midpoint; ++i) {
        node = node->next;
      }

      ListNode* secondHalfHead = node->next;
      node->next = nullptr;

      ListNode* nextNode = reverseList(secondHalfHead);

      while (head != nullptr) {
        ListNode* nextNextNode = head->next;

        head->next = nextNode;
        nextNode = nextNextNode;

        head = head->next;
      }
    }
};
