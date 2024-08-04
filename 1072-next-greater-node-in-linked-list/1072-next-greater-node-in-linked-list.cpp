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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *temp = head;
        vector<int> list;
        while(temp){
            list.push_back(temp->val);
            temp = temp->next;
        }
        int size = list.size();
        vector<int> res(size);
        res[size-1] = 0;
        stack<int> st;
        st.push(list[size-1]);

        for(int i = size - 2; i >= 0; i--){
            while(!st.empty() && st.top() <= list[i]) st.pop();
            if(st.empty()) res[i] = 0;
            else res[i] = st.top();
            st.push(list[i]);
        }
        return res;
    }
};