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
    int calculateLLSize(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* split(ListNode* head, vector<ListNode*> &ans, int size){
        ListNode* temp=head;
        int cnt=0;
        while(temp && cnt!=size-1){
            cnt++;
            temp=temp->next;
        }
        ListNode* nextNode = NULL;
        if(temp){
            nextNode=temp->next;
            temp->next=NULL;
        }
        ans.push_back(head);
        return nextNode;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int size = calculateLLSize(head);
        int eachSize = size / k;
        int extra = size % k;
        vector<int> sizeOfEachNode(k, eachSize);
        for (int i = 0; i < k; i++) {
            if (extra > 0) {
                sizeOfEachNode[i]++;
                extra--;
            }
        }
        for (int i = 0; i < k; i++) {
            head = split(head, ans, sizeOfEachNode[i]);
        }
        return ans;
    }
};