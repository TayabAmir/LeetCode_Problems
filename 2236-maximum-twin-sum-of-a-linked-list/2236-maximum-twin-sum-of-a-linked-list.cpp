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
    ListNode* reverseList(ListNode* head){
        ListNode *prev = NULL, *current = head, *next;
        while(current){
            next = current->next;
            current-> next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        slow = reverseList(slow);
        int maxN = -1;
        while(slow)
            maxN = max(maxN,head->val+slow->val),head=head->next,slow=slow->next;
        return maxN;
    }
};