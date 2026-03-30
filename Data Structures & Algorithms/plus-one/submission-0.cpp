class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // We want to add one to a array of digits [1, 2, 3] + 1 = 124 -> return {1, 2, 4}
        // The hard part is what if the array is [1, 3, 9] + 1 = 140 -> return {1, 4, 0} 
        // We have to account for carry -> which we can do by going backwards

        int carry = 1, i = digits.size() - 1; 
        vector<int> ans;
        while (i >= 0 && carry) {
            int sum = digits[i] + carry;
            digits[i--] = sum % 10;
            carry = sum / 10;
        }

        if (carry) {
            digits.insert(digits.begin(), 1); // if we still have a carry that means our last val must've been a 9
        }

        return digits;
    }   
};
