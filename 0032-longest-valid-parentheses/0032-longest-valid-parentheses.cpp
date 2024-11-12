class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
    stack<int> idx;
    idx.push(-1);
    int mx = 0;

    for(int i=0;i<n;i++){
        if(s[i]=='(') idx.push(i);
        else{
            // closing bracket
            idx.pop();

            if(idx.empty()) idx.push(i);
            else mx = max(mx, i - idx.top());
        }
    }
    return mx;
    }
};