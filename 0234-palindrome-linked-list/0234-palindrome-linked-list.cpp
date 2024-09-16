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
    int i = 0;
    int getLength(ListNode* head){
        ListNode* temp = head;
        int length = 0;
        while(temp)
            length++, temp = temp->next;
        return length;
    }
    bool isPalindrome(ListNode* head) {
        int n = getLength(head), count = 0;
        ListNode* temp1 = head, *temp2 = head;
        isPalindrome(temp1, temp2, n, count);
        return count == n/2;
    }
    void isPalindrome(ListNode* &head, ListNode* head2, int n, int &count){
        if(!head2) return;
        isPalindrome(head, head2->next, n, count);
        if(i == n/2) return;
        if(head->val == head2->val) count++;
        head = head->next, i++;
    }
};