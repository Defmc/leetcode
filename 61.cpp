#include <cstddef>
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  size_t getBounds(ListNode **beforeStarter, ListNode **tail, size_t k,
                   size_t *size, size_t i) {
    if (!(*beforeStarter)->next) {
      *tail = *beforeStarter;
      *size = i + 1;
      return 0;
    }
    ListNode *myBeforeStarter = *beforeStarter;
    *beforeStarter = (*beforeStarter)->next;
    const size_t currK = 1 + getBounds(beforeStarter, tail, k, size, i + 1);
    if (currK == k % *size) {
      *beforeStarter = myBeforeStarter;
    }
    return currK;
  }

public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
      return head;
    ListNode *beforeStarter = head, *tail = head;
    size_t size = 0;
    getBounds(&beforeStarter, &tail, k, &size, 0);
    if (k % size == 0)
      return head;
    ListNode *start = beforeStarter->next;
    beforeStarter->next = nullptr;
    tail->next = head;
    return start;
  }
};
