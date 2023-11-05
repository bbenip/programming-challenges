/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode(int x) : val(x), next(NULL) {}
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

  public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      int sizeOfListA = getListSize(headA);
      int sizeOfListB = getListSize(headB);

      while (headA != nullptr && headB != nullptr) {
        if (headA == headB) {
          return headA;
        }

        if (sizeOfListA > sizeOfListB) {
          headA = headA->next;
          sizeOfListA -= 1;
        } else {
          headB = headB->next;
          sizeOfListB -= 1;
        }
      }

      return nullptr;
    }
};
