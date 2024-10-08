/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* prevNode = NULL;
            for (int i = 0; i < size; i++) {
                Node* currNode = q.front();
                q.pop();
                if(prevNode!=NULL) prevNode->next=currNode;
                prevNode=currNode;
                if (currNode && currNode->left)
                    q.push(currNode->left);
                if (currNode && currNode->right)
                    q.push(currNode->right);
            }
        }
        return root;
    }
};