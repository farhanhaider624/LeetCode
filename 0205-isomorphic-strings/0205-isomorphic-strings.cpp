class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(mp1.find(t[i])!=mp1.end() && (mp1[t[i]]!=s[i])) return false;
            if(mp2.find(s[i])!=mp2.end() && (mp2[s[i]]!=t[i])) return false;
            else{
                mp1[t[i]]=s[i];
                mp2[s[i]]=t[i];
            }
        }
        return true;
    }
};