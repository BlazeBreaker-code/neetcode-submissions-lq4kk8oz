public class Solution 
{
    public int[] TopKFrequent(int[] nums, int k) 
    {
        // We can use bucket sort to solve this.
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

        List<int>[] freq = new List<int>[nums.Length + 1]; // +1 just in case all our elements are the same.

        for (int i = 0; i < freq.Length; i++)
        {
            freq[i] = new List<int>(); // initialize our list.
        }

        foreach (var entry in dict) // iterate through our dict
        {
            freq[entry.Value].Add(entry.Key); // add to our list. [3 freq] = 2
                                              // This allows for multiple keys of the same freq.
        }

        int[] res = new int[k];
        int index = 0;
        // What do we want now.
        // We have our buckets by freq.
        // We want to go to the end of our freq list and keep entering till we reach k.

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
