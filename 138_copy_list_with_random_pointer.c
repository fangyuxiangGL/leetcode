/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *ptr1 = NULL;
    struct RandomListNode *newHead = NULL;
    struct RandomListNode *ptr2 = NULL;
    struct RandomListNode *tmp = NULL;
    struct RandomListNode *ptr3 = NULL;
    
    if (!head)
        return NULL;
    ptr1 = head;
    while (ptr1) {
        tmp = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        tmp->label = ptr1->label;
        tmp->next = tmp->random = NULL;
        if (!ptr2)    
            ptr2 = tmp;
        else
            ptr2->next = tmp;
        ptr2 = tmp;
        if (!newHead)
            newHead = ptr2;
        ptr1 = ptr1->next;
    }
    
    ptr1 = head;
    ptr2 = newHead;
    while (ptr1 && ptr2) {
        tmp = ptr1->random;
        if (tmp) {
            ptr3 = newHead;
            while (ptr3) {
                if (ptr3->label == tmp->label)
                    break;
                ptr3 = ptr3->next;
            }
            ptr2->random = ptr3;
        }
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return newHead;
}
