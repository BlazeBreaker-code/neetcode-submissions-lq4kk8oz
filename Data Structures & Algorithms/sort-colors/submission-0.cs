public class Solution 
{
    public void SortColors(int[] nums) 
    {
        // I understand it now, it's a fall through implementation.
        int zero = 0, one = 0;

        for (int two = 0; two < nums.Length; two++)
        {
            int tmp = nums[two];
            nums[two] = 2;

            if (tmp < 2)
            {
                nums[one++] = 1;
            }

            if (tmp < 1)
            {
                nums[zero++] = 0;
            }
        }


        // Should keep changing the pointers until everything is set properly.
    }
}