class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char, int> mp;
        int i=0, j=0;
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            int windowSize=j-i+1;
            int maxRepeating=0;
            for(auto a:mp){
                maxRepeating=max(maxRepeating,a.second);
            }
            while(j-i+1-maxRepeating>k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};