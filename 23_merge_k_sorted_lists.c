/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeList(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *prev_p1 = NULL, *p1 = NULL, *p2 = NULL;
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    p1 = l1;
    prev_p1 = NULL;
    while (l2) {
        p2 = l2;

        while (p1 && (p1->val <= p2->val)) {
            prev_p1 = p1;
            p1 = p1->next;
        }
  
        if (prev_p1) { 
            prev_p1 ->next = p2;
        } else { 
            l1 = p2;
        }
        prev_p1 = p2;
        if (p1) {
            l2 = l2->next;
            p2->next = p1;
            p1 = p2;
        } else {
            l2 = NULL;
        }
    }
    return l1;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *res = NULL;
    if (!lists || !listsSize)
        return NULL;
    for (int index = 0; index < listsSize; index++) {
        res = mergeList(res, lists[index]);
    }
    return res;
}
