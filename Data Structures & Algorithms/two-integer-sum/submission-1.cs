public class Solution 
{
    public int[] TwoSum(int[] nums, int target) 
    {
        Dictionary<int, int> dict = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
        {
            int compliment = target - nums[i];

            if (dict.ContainsKey(compliment))
            {
                return new int[] {dict[compliment], i};
            }

            dict[nums[i]] = i;
        }

        return new int[] {};
    }
}
