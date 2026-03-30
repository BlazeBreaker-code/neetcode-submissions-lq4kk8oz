public class Solution 
{
    public List<List<string>> GroupAnagrams(string[] strs) 
    {
        // To solve this we want to sort our words.
        // 1a 1e 1t - we'll use this as keys in our hashmap.
        // Now when we check other words we can see if it already exists in our hashmap, if not add it there to a list.
        Dictionary<string, List<string>> dict = new Dictionary<string, List<string>>();

        foreach (string s in strs)
        {
            char[] charArr = new char[26];
            charArr = s.ToCharArray();
            Array.Sort(charArr);
            string sortedS = new string(charArr);

            if (!dict.ContainsKey(sortedS))
            {
                dict[sortedS] = new List<string>();  
            }

            dict[sortedS].Add(s);
        }

        return dict.Values.ToList<List<string>>();
    }
}
