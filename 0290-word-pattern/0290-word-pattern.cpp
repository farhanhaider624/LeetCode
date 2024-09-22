class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);

        string token;
        int cntWords=0;
        while(getline(ss, token, ' ')){
            words.push_back(token);
            cntWords++;
        }
        if(pattern.size()!=cntWords) return false;
        unordered_map<string, char> mp;
        set<char> used;
        for(int i=0; i<pattern.size(); i++){
            string word = words[i];
            char l=pattern[i];
            if(mp.find(word)==mp.end() && used.find(l)==used.end()){
                mp[word]=l;
                used.insert(l);
            } else if(mp[word]!=l){
                return false;
            }
        }
        return true;
    }
};