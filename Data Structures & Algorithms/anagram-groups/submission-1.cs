public class Solution 
{
    public List<List<string>> GroupAnagrams(string[] strs) 
    {
        Dictionary<string, List<string>> dict = new Dictionary<string, List<string>>();

        foreach (string s in strs)
        {
            int[] arr = new int[26]; // An array for our characters to sort them.

            foreach (char c in s)
            {
                arr[c - 'a']++;
            }

            string key = string.Join(",",  arr); // Join all the elements in the array.

            if (!dict.ContainsKey(key)) // If this is our first time seeing it
            {
                dict[key] = new List<string>();
            }

            dict[key].Add(s);
        }

        return dict.Values.ToList();
    }
}
