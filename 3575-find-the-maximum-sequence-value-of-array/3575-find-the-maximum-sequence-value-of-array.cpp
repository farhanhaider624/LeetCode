class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();


        int maxNum = 0;
        for (int num : nums) {
            maxNum |= num;
        }
        int maxOrValue = (1 << 7);


        vector<vector<bitset<128>>> dp_left(n + 1, vector<bitset<128>>(k + 1));



        vector<vector<bitset<128>>> dp_right(n + 1, vector<bitset<128>>(k + 1));
        dp_left[0][0][0] = true;
        for (int i = 1; i <= n; ++i) {
            dp_left[i] = dp_left[i - 1];
            dp_left[i][0][0] = true;
            for (int l = 1; l <= min(k, i); ++l) {



                dp_left[i][l] |= dp_left[i - 1][l];
                for (int s = 0; s < 128; ++s) {



                    if (dp_left[i - 1][l - 1][s]) {
                        dp_left[i][l][s | nums[i - 1]] = true;
                    }
                }
            }
        }
        dp_right[n][0][0] = true;
        for (int i = n - 1; i >= 0; --i) {



            dp_right[i] = dp_right[i + 1];
            dp_right[i][0][0] = true;


            for (int l = 1; l <= min(k, n - i); ++l) {
                dp_right[i][l] |= dp_right[i + 1][l];


                
                for (int s = 0; s < 128; ++s) {
                    if (dp_right[i + 1][l - 1][s]) {
                        dp_right[i][l][s | nums[i]] = true;
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i <= n; ++i) {
            vector<int> left_vals, right_vals;
            for (int s = 0; s < 128; ++s) {
                if (dp_left[i][k][s]) left_vals.push_back(s);
                if (dp_right[i][k][s]) right_vals.push_back(s);
            }
            for (int s1 : left_vals) {
                for (int s2 : right_vals) {
                    result = max(result, s1 ^ s2);
                }
            }
        }
        return result;
    }
};