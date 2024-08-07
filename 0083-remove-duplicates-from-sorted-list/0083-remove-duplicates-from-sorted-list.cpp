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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        ListNode* temp=head;
        while(temp){
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode* ansNode = new ListNode(-1);
        temp=ansNode;
        for(auto &it: mp){
            ListNode* newNode = new ListNode(it.first);
            temp->next = newNode;
            temp = newNode;
        }
        return ansNode->next;
    }
};