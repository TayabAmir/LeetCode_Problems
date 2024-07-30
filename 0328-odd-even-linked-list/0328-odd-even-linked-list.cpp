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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode *ptr1 = head,*dummy = new ListNode(-1),*res = dummy;
        while(ptr1){
            res->next = new ListNode(ptr1->val);
            res = res->next;
            (ptr1->next) ? ptr1 = ptr1->next->next : ptr1 = ptr1->next;
        }
        ptr1 = head->next;
        while(ptr1){
            res->next = new ListNode(ptr1->val);
            res = res->next;
            (ptr1->next) ? ptr1 = ptr1->next->next : ptr1 = ptr1->next;
        }
        return dummy->next;
    }
};