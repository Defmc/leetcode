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
  size_t listSize(ListNode *head) {
    size_t size;
    ListNode *next = head;
    for (size = 0; next; next = next->next)
      size++;
    return size;
  }

  size_t getBounds(ListNode **beforeStarter, ListNode **tail, size_t k) {
    if (!(*beforeStarter)->next) {
      *tail = *beforeStarter;
      return 0;
    }
    ListNode *myBeforeStarter = *beforeStarter;
    *beforeStarter = (*beforeStarter)->next;
    const size_t currK = 1 + getBounds(beforeStarter, tail, k);
    if (currK == k) {
      *beforeStarter = myBeforeStarter;
    }
    return currK;
  }

public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
      return head;
    ListNode *beforeStarter = head, *tail = head;
    size_t size = listSize(head);
    if (k % size == 0)
      return head;
    getBounds(&beforeStarter, &tail, k % size);
    ListNode *start = beforeStarter->next;
    beforeStarter->next = nullptr;
    tail->next = head;
    return start;
  }
};
