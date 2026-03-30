/*
    Thought process time:
        Lets create a dictionary - string, List of strings
        Lets use an array - Arr[c - 'a'] to map out the string
        Then check if we have that key already in our dict - if not then create a new key.
        Then add our string to that key - since it's mapped it should be the anagram
        Then return our dictionary - values - to string
*/

public class Solution 
{
    public List<List<string>> GroupAnagrams(string[] strs) 
    {
        Dictionary<string, List<string>> anagramDict = new Dictionary<string, List<string>>(); 

        foreach (string s in strs)
        {
            int[] map = new int[26]; // Alphabet

            foreach (char c in s)
            {
                map[c - 'a']++;
            }

            string key = string.Join(",", map);

            if(!anagramDict.ContainsKey(key))
            {
                anagramDict[key] = new List<string>();
            }

            anagramDict[key].Add(s);
        }

        return anagramDict.Values.ToList();
    }
}
