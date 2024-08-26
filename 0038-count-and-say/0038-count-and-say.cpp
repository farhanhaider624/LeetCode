class Solution {
public:
    string RLE(string &s){
        string ans="";
        int i=0;
        while(i<s.size()){
            char curr_char=s[i];
            int cnt=0;
            while(i<s.size() && s[i]==curr_char){
                i++;
                cnt++;
            }
            string temp=to_string(cnt);
            for(auto ch:temp){
                ans+=ch;
            }
            ans+=curr_char;
        }
        return ans;
    }
    string func(int n){
        if(n==1) return "1";
        string s=func(n-1);
        return RLE(s);
    }
    string countAndSay(int n) {
        return func(n);
    }
};