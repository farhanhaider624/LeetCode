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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* ansNode = new ListNode(-1);
        ListNode* temp2=ansNode;
        int sum=0;
        while(temp){
            if(temp->val==0){
                ListNode* newNode = new ListNode(sum);
                temp2->next = newNode;
                temp2=newNode;
                sum=0;
            }
            else sum+=temp->val;
            temp=temp->next;
        }
        return ansNode->next;
    }
};