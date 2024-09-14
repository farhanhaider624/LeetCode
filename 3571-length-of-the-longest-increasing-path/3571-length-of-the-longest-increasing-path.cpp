#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        vector<int> ys(n);



        for (int i = 0; i < n; ++i) {
            ys[i] = coordinates[i][1];
        }
        
        vector<int> sorted_ys = ys;
        sort(sorted_ys.begin(), sorted_ys.end());



        sorted_ys.erase(unique(sorted_ys.begin(), sorted_ys.end()), sorted_ys.end());
        
        unordered_map<int, int> y_to_compressed;
        for (int i = 0; i < sorted_ys.size(); ++i) {



            y_to_compressed[sorted_ys[i]] = i + 1;
        }
        
        int m = sorted_ys.size();
        vector<tuple<int, int, int>> points(n);
        for (int i = 0; i < n; ++i) {



            points[i] = {coordinates[i][0], coordinates[i][1], i};
        }
        
        vector<int> dp_left(n, 1), dp_right(n, 1);
        
        
        
        
        
        auto updateBIT = [](vector<int>& bit, int idx, int val) {
            while (idx < bit.size()) {
                bit[idx] = max(bit[idx], val);
                idx += idx & -idx;
            }
        };
        
        auto queryBIT = [](vector<int>& bit, int idx) {
            int result = 0;



            while (idx > 0) {
                result = max(result, bit[idx]);
                idx -= idx & -idx;
            }
            return result;
        };
        
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return get<0>(a) < get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b));
        });
        
        vector<int> bit(m + 2, 0);
        for (int i = 0; i < n;) {
            int j = i;




            int x = get<0>(points[i]);
            vector<pair<int, int>> curr_points;
            while (j < n && get<0>(points[j]) == x) {
                int y = y_to_compressed[get<1>(points[j])];
                int idx = get<2>(points[j]);
                curr_points.emplace_back(y, idx);
                ++j;
            }
            for (const auto& p : curr_points) {
                int y = p.first;
                int idx = p.second;





                int val = queryBIT(bit, y - 1) + 1;
                dp_left[idx] = max(dp_left[idx], val);
            }
            for (const auto& p : curr_points) {
                int y = p.first;
                int idx = p.second;
                updateBIT(bit, y, dp_left[idx]);
            }
            i = j;
        }
        
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return get<0>(a) > get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) > get<1>(b));
        });
        
        fill(bit.begin(), bit.end(), 0);



        for (int i = 0; i < n;) {
            int j = i;



            int x = get<0>(points[i]);
            vector<pair<int, int>> curr_points;
            while (j < n && get<0>(points[j]) == x) {



                int y = y_to_compressed[get<1>(points[j])];
                int idx = get<2>(points[j]);
                curr_points.emplace_back(y, idx);
                ++j;
            }
            for (const auto& p : curr_points) {
                int y = m - p.first + 1;



                
                int idx = p.second;
                int val = queryBIT(bit, y - 1) + 1;
                dp_right[idx] = max(dp_right[idx], val);
            }
            for (const auto& p : curr_points) {
                int y = m - p.first + 1;
                int idx = p.second;
                updateBIT(bit, y, dp_right[idx]);
            }
            i = j;
        }
        
        return dp_left[k] + dp_right[k] - 1;
    }
};
