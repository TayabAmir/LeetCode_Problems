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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next && n == 1) return NULL;
        ListNode *prev = NULL,*ptr1 = head, *ptr2 = head;
        for(int i = 0; i < n; i++)
            ptr2 = ptr2->next;
        while(ptr2){
            prev = ptr1, ptr1 = ptr1->next, ptr2 = ptr2->next;
        }
        if(prev)
            prev->next = ptr1->next;
        else
            head = ptr1->next;
        delete ptr1;
        return head;
    }
};