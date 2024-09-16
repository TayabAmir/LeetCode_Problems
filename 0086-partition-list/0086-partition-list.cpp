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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-1), *res = dummy, *temp = head;
        vector<int> lesser, greater;
        while (temp)
            (temp->val < x) ? lesser.push_back(temp->val) : greater.push_back(temp->val), temp = temp->next;
        for (int ele : lesser)
            res->next = new ListNode(ele), res = res->next;
        for (int ele : greater)
            res->next = new ListNode(ele), res = res->next;
        return dummy->next;
    }
};