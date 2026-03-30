public class Solution 
{
    public int MaxArea(int[] heights) 
    {
        int maxWater = 0;
        int left = 0, right = heights.Length - 1;

        while (left < right) // We can never be at the same node
        {
            int area = (Math.Min(heights[left], heights[right])) * (right - left);

            maxWater = Math.Max(area, maxWater);

            if (heights[left] <= heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxWater;
    }
}
