public class Solution 
{
    public int[] TwoSum(int[] numbers, int target) 
    {
        if (numbers.Length == 0)
        {
            return new int[] {};
        }

        Dictionary<int, int> dict = new Dictionary<int, int>();

        for (int i = 0; i < numbers.Length; i++)
        {
            int complement = target - numbers[i];
            if (dict.ContainsKey(complement))
            {
                return new int[] { dict[complement] + 1, i + 1 };
            }

            dict[numbers[i]] = i;
        }

        return new int[] {};
    }
}
