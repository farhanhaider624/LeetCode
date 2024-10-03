class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int cnt1=0, cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;
        for(int i=0; i<v.size(); i++){
            if(cnt1==0 && el2!=v[i]){
                cnt1=1;
                el1=v[i];
            }
            else if(cnt2==0 && el1!=v[i]){
                cnt2=1;
                el2=v[i];
            }
            else if(el1==v[i]) cnt1++;
            else if(el2==v[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        int count=(int)(v.size()/3)+1;
        cnt1=0, cnt2=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]==el1) cnt1++;
            if(v[i]==el2) cnt2++;
        }
        if(cnt1>=count) ans.push_back(el1);
        if(cnt2>=count) ans.push_back(el2);
        
        return ans;
    }
};