public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dict = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
        {
            int coorespondingNum = target - nums[i];
            if (!dict.ContainsKey(coorespondingNum))
            {
                dict[nums[i]] = i;
            }
            else
            {
                return new int[] {dict[coorespondingNum], i};
            }
        }

        return new int[] {};
    }
}
