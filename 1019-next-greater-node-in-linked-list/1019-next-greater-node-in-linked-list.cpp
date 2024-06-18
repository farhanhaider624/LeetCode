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
        vector<int> temp;
        ListNode* ptr=head;
        while(ptr!=NULL){
            temp.push_back(ptr->val);
            ptr=ptr->next;
        }
        stack<int> st;
        vector<int> ans;
        for(int i=temp.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=temp[i]) st.pop();
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top());
            st.push(temp[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};