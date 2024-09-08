class Solution {
public:
    bool isPossible(vector<int>& start, int d, long long minDiff) { 
        long long prev = start[0];
        for (int i = 1; i < start.size(); ++i) { 
            if (prev + minDiff > start[i] + d) { 
                return false;
            }
            prev = max(prev + minDiff, (long long)start[i]);
        } 
        return true;
    } 
    
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long left = 0, right = (long long)d + start.back() - start.front();
        long long result = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (isPossible(start, d, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return (int)result;
    }
};