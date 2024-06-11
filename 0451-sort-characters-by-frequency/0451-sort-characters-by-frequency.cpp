class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        for(auto &it: mp) pq.push({it.second, it.first});
        
        string ans="";
        
        while(!pq.empty()){
            int i=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            while(i--){
                ans+=ch;
            }
        }
        return ans;
    }
};