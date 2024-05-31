#include <stddef.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head) {
  struct ListNode *node = head;
  while (node->next != NULL) {
    if (node->val == node->next->val) {
      node->next = node->next->next;
    }
    node = node->next;
  }
  return head;
}
