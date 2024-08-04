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
        ListNode* ahead=head->next;
        while(curr){
            ListNode* ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=reverseLL(l1);
        ListNode* head2=reverseLL(l2);
        ListNode* ans = new ListNode(-1);
        ListNode* temp=ans;
        int carry=0;
        while(head1 || head2 || carry){
            int sum=carry;
            if(head1){
                sum+=head1->val;
                head1=head1->next;
            }
            if(head2){
                sum+=head2->val;
                head2=head2->next;
            }
            carry = sum/10;
            int nodeVal=sum%10;
            ListNode* newNode=new ListNode(nodeVal);
            temp->next=newNode;
            temp=newNode;
        }
        temp=ans->next;
        delete ans;
        return reverseLL(temp);
    }
};