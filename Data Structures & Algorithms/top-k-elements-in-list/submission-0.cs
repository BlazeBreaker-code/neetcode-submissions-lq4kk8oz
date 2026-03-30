public class Solution 
{
    public int[] TopKFrequent(int[] nums, int k) 
    {
        // First step count frequencies.

        Dictionary<int, int> dict = new Dictionary<int, int>();

        foreach (int num in nums)
        {
            if (!dict.ContainsKey(num))
            {
                dict[num] = 0;
            }

            dict[num]++;
        }

        // Next is to set up our buckets.
        
        List<int>[] freq = new List<int>[nums.Length + 1];

        for (int i = 0; i < freq.Length; i++)
        {
            freq[i] = new List<int>();
        }

        foreach (var entry in dict)
        {
            freq[entry.Value].Add(entry.Key);
        }

        int[] res = new int[k]; // Length of how much we want to scoop out.
        int index = 0;
        // Start with the highest frequency and check the k values.
        for (int i = freq.Length - 1; i > 0 && index < k; i--)
        {
           foreach (int n in freq[i])
           {
                res[index++] = n;
                if (index == k) 
                {
                    return res;
                }
           }
        }

        return res;

    }
}
