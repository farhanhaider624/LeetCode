class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        set<string> st;
        bool flag = false;
        for(int i=0; i<n; i++){
            vector<int> newState(8);
            for(int j=1; j<7; j++){
                newState[j] = (cells[j-1]==cells[j+1]?1:0);
            }
            string s(newState.begin(), newState.end());
            if(st.find(s)!=st.end()){
                flag=true;
                break;
            } else{
                st.insert(s);
            }
            cells=newState;
        }
        n=n%st.size();
        for(int i=0; i<n; i++){
            vector<int> newState(8);
            for(int j=1; j<7; j++){
                newState[j] = (cells[j-1]==cells[j+1]?1:0);
            }
            cells=newState;
        }
        return cells;
    }
};