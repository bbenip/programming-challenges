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
        ListNode* temp = currentNode->next;
        currentNode->next = previousNode;

        previousNode = currentNode;
        currentNode = temp;
      }

      return previousNode;
    }

  public:
    bool isPalindrome(ListNode* head) {
      const int size = getListSize(head);

      ListNode* node = head;

      for (int i = 1; i < size / 2; ++i) {
        node = node->next;
      }

      ListNode* secondHalfHead = node->next;
      node->next = nullptr;

      ListNode* reversedListHead = reverseList(secondHalfHead);

      while (head != nullptr && reversedListHead != nullptr) {
        if (head->val != reversedListHead->val) {
          return false;
        }

        head = head->next;
        reversedListHead = reversedListHead->next;
      }

      return true;
    }
};
