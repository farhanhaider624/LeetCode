class Solution {
public:
    vector<string> string_stream(string &str){
        vector<string> tokens;
        stringstream ss(str);
        string token="";
        while(getline(ss, token, '.')){
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string> str1=string_stream(version1);
        vector<string> str2=string_stream(version2);

        int i=0;
        int m=str1.size();
        int n=str2.size();

        while(i<m || i<n){
            int num1, num2;
            if(i>=m) num1=0;
            else num1=stoi(str1[i]);
            if(i>=n) num2=0;
            else num2=stoi(str2[i]);

            cout<<num1<<" "<<num2<<endl;
            if(num1<num2) return -1;
            else if(num1>num2) return 1;
            i++;
        }
        return 0;
    }
};