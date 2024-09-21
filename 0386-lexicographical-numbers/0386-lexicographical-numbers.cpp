class Solution {
public:
    void func(int num, int n, vector<int> &ans){
        if(num>n) return;
        ans.push_back(num);
        for(int i=0; i<=9; i++){
            int newNum=num*10+i;
            func(newNum, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=9; i++){
            func(i, n, ans);
        }
        return ans;
    }
};