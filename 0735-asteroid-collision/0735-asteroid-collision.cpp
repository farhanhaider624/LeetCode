class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> s;
        for(int i=0; i<n; i++){
            int w = asteroids[i];
            bool flag=true;
            while(!s.empty() && w<0 && s.back()>0){
                int sum=w+s.back();
                if(sum>0){
                    flag=false;
                    break;
                }
                else if(sum<0){
                    s.pop_back();
                }
                else if(sum==0){
                    s.pop_back();
                    flag=false;
                    break;
                }
            }
            if(flag) s.push_back(w);
        }
        return s;
    }
};