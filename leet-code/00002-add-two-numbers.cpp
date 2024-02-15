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
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* auxiliaryHead = new ListNode();
      ListNode* previousDigit = auxiliaryHead;

      int carry = 0;

      while (l1 != nullptr || l2 != nullptr || carry != 0) {
        const int digit1 = (l1 != nullptr) ? l1->val : 0;
        const int digit2 = (l2 != nullptr) ? l2->val : 0;

        const int totalDigitSum = digit1 + digit2 + carry;
        const int digitSum = totalDigitSum % 10;
        carry = totalDigitSum / 10;

        ListNode* currentDigit = new ListNode(digitSum);

        previousDigit->next = currentDigit;

        previousDigit = currentDigit;

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
      }

      ListNode* sum = auxiliaryHead->next;

      auxiliaryHead->next = nullptr;
      delete auxiliaryHead;

      return sum;
    }
};
