class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // we found the cycle -> now we want the element that is causing that cycle
        int slow2 = 0;
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow2;
    }
};
