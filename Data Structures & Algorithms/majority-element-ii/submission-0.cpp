class Solution {
// I think we can use the voting algorithm
// since they have to be n/3 more that means there can only be 
// 2 candidates at most
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = -1, freq1 = 0;
        int candidate2 = -1, freq2 = 0;
            
        for (int num : nums) {
                if (freq1 == 0) candidate1 = num;
                else if (freq2 == 0 && num != candidate1) candidate2 = num;

                if (num == candidate1) ++freq1;
                else if (num == candidate2) ++freq2;
                else {
                    --freq1; --freq2;
                }
        }

        vector<int> ans;
        ans.reserve(2);
        freq1 = 0; freq2 = 0;
        for (int num : nums) {
            if (num == candidate1) ++freq1;
            if (num == candidate2) ++freq2;
        }

        const int n = nums.size();
        if (freq1 > n / 3) ans.push_back(candidate1);
        if (freq2 > n / 3) ans.push_back(candidate2);

        return ans;
    }
};