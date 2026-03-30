public class Solution 
{
    public int Trap(int[] height) 
    {
        if (height == null || height.Length == 0)
        {
            return 0;
        }

        int left = 0, right = height.Length - 1;
        int leftMax = height[left], rightMax = height[right];

        int res = 0;

        while (left < right)
        {
            if (leftMax < rightMax)
            {
                left++;
                leftMax = Math.Max(leftMax, height[left]);
                res += leftMax - height[left];
            }
            else
            {
                right--;
                rightMax = Math.Max(rightMax, height[right]);
                res += rightMax - height[right];
            }
        }

        return res;
    }
}
