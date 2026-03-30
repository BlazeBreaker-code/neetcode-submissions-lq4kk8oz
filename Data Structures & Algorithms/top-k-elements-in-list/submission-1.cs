public class Solution 
{
    public int[] TopKFrequent(int[] nums, int k) 
    {
        Dictionary<int, int> dict = new Dictionary<int, int>();   
        foreach (int num in nums)
        {
            if (dict.ContainsKey(num))
            {
                dict[num]++;
            }
            else
            {
                dict[num] = 1;
            }
        }

        List<int>[] freq = new List<int>[nums.Length + 1];
        for (int i = 0; i < freq.Length; i++)  // Initialize lists in each bucket
        {
            freq[i] = new List<int>();
        }
        
        foreach (var entry in dict)
        {
            freq[entry.Value].Add(entry.Key);
        }

        int[] res = new int[k];
        int index = 0;

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
