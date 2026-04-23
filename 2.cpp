struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *addTwoNumbersCarry(ListNode *l1, ListNode *l2, bool carry) {
    if (!l1 && !l2 && !carry) {
      return nullptr;
    }
    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;

    return new ListNode(sum % 10,
                        addTwoNumbersCarry(l1 ? l1->next : nullptr,
                                           l2 ? l2->next : nullptr, sum / 10));
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return addTwoNumbersCarry(l1, l2, false);
  }
};
