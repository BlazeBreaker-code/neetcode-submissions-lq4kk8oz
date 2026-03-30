public class Solution 
{
    public List<List<int>> ThreeSum(int[] nums) 
    {
        Array.Sort(nums);
        List<List<int>> res = new List<List<int>>();

        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] > 0)
            {
                break; // All our numbers are positive now.
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue; // Skip because we already tried this value
            }

            int left = i + 1; 
            int right = nums.Length - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0)
                {
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    res.Add(new List<int>() { nums[i], nums[left], nums[right] });
                    right--;
                    left++;

                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
            }
        }

        return res;
    }
}
