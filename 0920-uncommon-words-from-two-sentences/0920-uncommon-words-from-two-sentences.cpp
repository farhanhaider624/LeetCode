class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1 += ' ' + s2 + ' ';
        map<string,int>m;
        vector<string>v;
        string str = "";
        for(char ch: s1){
            if(ch == ' '){
                if(!str.empty()) {
                    m[str]++;
                    str = "";
                }
            }
            else{
                str +=ch;
            }
        }
        for(auto i:m){
            if(i.second==1){
                v.push_back(i.first);
            }
        }
        return v;
    }
};