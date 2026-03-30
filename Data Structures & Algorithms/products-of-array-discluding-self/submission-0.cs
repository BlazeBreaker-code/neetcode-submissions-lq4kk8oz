public class Solution 
{
    public int[] ProductExceptSelf(int[] nums) 
    {
        int n = nums.Length;
        int[] res = new int[n];
        Array.Fill(res, 1); // Fill the array with 1s since that is what we will use to multiply.

        // What we want to do
        // [1, 2, 4, 6]
        // [1, 2, 8, 64] prefix
        // [48, 48, 24, 6]  post
        // [48, 24, 12, 8]
        for (int i = 1; i < n; i++) // Start at 1st value and we will populate our prefix.
        {
            res[i] = res[i - 1] * nums[i - 1]; // [1, 1 * 1]
        }                                      // [1, 1, 1 * 2]
                                               // [1, 1, 2, 2 * 4]
                                               // [1, 1, 2, 8]
                                               // [48, 24, 6, 1] - what we need to multiply with.
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) // Now for the postfix lets iterate backwards
        {
            res[i] *= postfix;
            postfix *= nums[i]; // 6 * 4
        }

        return res;
    }                                          
}
