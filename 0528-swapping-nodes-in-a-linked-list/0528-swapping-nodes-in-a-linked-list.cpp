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
    int countTotalNodes(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n = countTotalNodes(head);
        int nk=n-k;
        ListNode* t1=head;
        ListNode* t2=head;
        k=k-1;
        while(k-- && t1){
            t1=t1->next;
        }
        while(nk-- && t2) t2=t2->next;
        if(t1 && t2) swap(t1->val, t2->val);
        return head;
    }
};