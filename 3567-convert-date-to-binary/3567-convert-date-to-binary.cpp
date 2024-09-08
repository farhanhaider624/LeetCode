class Solution {
public:
    string toBinary(int num) {
        return bitset<32>(num).to_string().substr(
            bitset<32>(num).to_string().find('1'));
    }
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        string yearBinary = toBinary(year);
        string monthBinary = toBinary(month);
        string dayBinary = toBinary(day);

        string ans = "";
        ans += yearBinary + "-" + monthBinary + "-" + dayBinary;
        return ans;
    }
};