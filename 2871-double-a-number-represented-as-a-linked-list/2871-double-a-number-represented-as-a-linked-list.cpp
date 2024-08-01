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
    int carry = 0;
    void doubleItHelper(ListNode *head){
        if(!head) return;
        doubleItHelper(head->next);
        int n = head->val * 2 + carry;
        head->val = n % 10,carry = n / 10; 
    }
    ListNode* doubleIt(ListNode* head) {
        doubleItHelper(head);
        if(carry){
            ListNode *new_head = new ListNode(carry);
            new_head->next = head;
            head = new_head;
        }
        return head;
    }
};