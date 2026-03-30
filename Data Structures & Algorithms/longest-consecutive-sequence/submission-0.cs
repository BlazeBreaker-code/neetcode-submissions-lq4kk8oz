public class Solution 
{
    public int LongestConsecutive(int[] nums) 
    {
        int longest = 0;
        HashSet<int> hash = new HashSet<int>(nums);

        foreach (int num in hash)
        {
            if (!hash.Contains(num - 1)) // means that this is the first element for the sub array.
            {
                int length = 1;
                while (hash.Contains(num + length))
                {
                    length++;
                }

                longest = Math.Max(length, longest);
            }
        }

        return longest;
    }
}
