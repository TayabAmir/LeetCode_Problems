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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL)
            temp = temp->next,len++;
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);
        if(k > len) return head;
        ListNode *prev = NULL, *curr = head;
        int c = 0;
        while(curr && c < k){
            ListNode* next = curr->next;
            curr->next = prev, prev = curr, curr = next, c++;
        }
        if(curr != NULL){
            ListNode* new_head = reverseKGroup(curr,k);
            head->next = new_head;
        }
        return prev;
    }
};