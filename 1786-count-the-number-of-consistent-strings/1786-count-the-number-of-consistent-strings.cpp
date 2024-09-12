class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        for(auto it:allowed) mp[it]++;
        int size=mp.size();
        int cnt=0;
        for(int i=0; i<words.size(); i++){
            bool temp=true;
            for(auto it:words[i]){
                mp[it]++;
                if(mp.size()>size){
                    mp[it]--;
                    mp.erase(it);
                    temp=false;
                    break;
                }
            }
            if(temp) cnt++; 
        }
        return cnt;
    }
};