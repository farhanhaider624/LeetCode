class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> q;
        for(auto it: queries){
            map<char, int> mp;
            for(char ch:it){
                mp[ch]++;
            }
            auto itr = mp.begin();
            q.push_back(itr->second);
        }
        vector<int> w;
        for(auto it: words){
            map<char, int> mp;
            for(char ch:it){
                mp[ch]++;
            }
            auto itr = mp.begin();
            w.push_back(itr->second);
        }
        // for(auto it:q) cout<<it<<endl;
        // for(auto it:w) cout<<it<<endl;
        vector<int> ans;
        for(int i=0; i<q.size(); i++){
            int cnt=0;
            for(int j=0; j<w.size(); j++){
                if(q[i]<w[j]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};