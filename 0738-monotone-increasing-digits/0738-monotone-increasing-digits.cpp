class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int ind=0;
        while(ind+1<s.size()){
            if(s[ind]<=s[ind+1]) ind++;
            else break;
        }
        if(ind+1==s.size()) return n;
        while(ind>=1){
            if(s[ind]==s[ind-1]) --ind;
            else break;
        }
        s[ind]=char(s[ind]-1);
        for(int i=ind+1; i<s.size(); ++i) s[i]='9';
        return stoi(s);
    }
};