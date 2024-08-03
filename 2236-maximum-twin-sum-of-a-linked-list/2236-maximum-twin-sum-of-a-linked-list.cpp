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
        ListNode* curr=head;
        while(curr){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* tempHead = reverseLL(slow->next);
        slow->next=NULL;
        int maxSum=0;
        while(head && tempHead){
            int sum = head->val + tempHead->val;
            maxSum=max(maxSum, sum);
            head=head->next;
            tempHead=tempHead->next;
        }
        return maxSum;
    }
};