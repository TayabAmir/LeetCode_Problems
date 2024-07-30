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
        int c = 0;
        while(temp) temp=temp->next,c++;
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n = getLength(head);
        k = k % n;
        if(k == 0) return head;
        ListNode* mover = head;
        for(int i = 0; i < n - k - 1; i++){
            mover = mover->next;
        }
        ListNode *new_head = mover->next;
        mover->next = NULL;
        mover = new_head;
        while(mover->next){
            mover = mover->next;
        }
        mover->next = head;
        return new_head;
    }
};