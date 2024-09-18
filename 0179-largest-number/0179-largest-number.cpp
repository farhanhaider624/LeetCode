class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result="";

        sort(nums.begin(), nums.end(), [](const auto& a, const auto& b){
            string num1=to_string(a);
            string num2= to_string (b);
            return num1+num2 >num2+ num1;
        } );

        for(auto& n:nums) result += to_string(n);
        if (result[0] == '0') return "0";
        return result;
    }
};