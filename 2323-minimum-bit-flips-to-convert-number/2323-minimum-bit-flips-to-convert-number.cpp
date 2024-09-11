class Solution {
public:
    int minBitFlips(int start, int goal) {
        //check each bits and comapre
        //if not equal then cnt
        int cnt=0;
        for(int i=0; i<32; i++){
            if((start & (1<<i)) != (goal & (1<<i))) cnt++;
        }
        return cnt;
    }
};