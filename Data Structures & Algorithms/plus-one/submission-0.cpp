class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(carry) digits[i] += 1;
            carry = false;
            if(digits[i] >= 10){
                digits[i] %= 10;
                carry = true;
            }
        }
        if(carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
