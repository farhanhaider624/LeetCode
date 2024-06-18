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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=NULL;
        ListNode* fast=head->next;
        while(fast!=NULL){
            head->next=prev;
            prev=head;
            head=fast;
            fast=fast->next;
        }
        head->next=prev;
        return head;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverseLL(head);
        ListNode* ptr=head;
        stack<int> st;
        vector<int> ans;
        while(ptr!=NULL){
            // cout<<ptr->val;
            while(!st.empty() && st.top()<=ptr->val) st.pop();
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top());
            st.push(ptr->val);
            ptr=ptr->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};