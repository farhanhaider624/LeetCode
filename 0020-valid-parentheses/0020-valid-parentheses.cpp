class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else if((s[i]==')' || s[i]=='}' || s[i]==']') && st.empty()) return false;
            else if(!st.empty()){
                if(s[i]==')' && st.top()=='(') st.pop();
                else if(s[i]=='}' && st.top()=='{') st.pop();
                else if(s[i]==']' && st.top()=='[') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};