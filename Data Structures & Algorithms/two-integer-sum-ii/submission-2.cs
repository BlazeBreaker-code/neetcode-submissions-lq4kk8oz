public class Solution 
{
    public int[] TwoSum(int[] nums, int target) 
    {
        int left = 0;
        int right = nums.Length - 1;

        while (left <= right)
        {
            int current = nums[left] + nums[right];

            if (current == target)
            {
                return new int[] {left + 1, right + 1};
            }
            else if (current < target) // we need to move our left pointer
            {
                left++;
            }
            else if (current > target)
            {
                right--;
            }
        }

        return new int[] {};
    }
}
