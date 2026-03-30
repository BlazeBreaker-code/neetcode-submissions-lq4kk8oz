public class Solution 
{
    public bool IsAnagram(string s, string t) 
    {
        // Let's eliminate any length issues
        if (s.Length != t.Length)
        {
            return false;
        }

        int[] count = new int[26];

        for (int i = 0; i < s.Length; i++)
        {
            count[s[i] - 'a']++; // Get the index of this value and then increment.
            count[t[i] - 'a']--; 
        }

        foreach (var val in count)
        {
            if (val != 0) // we had a character unmatched
            {
                return false; // not an anagram
            }
        }

        return true;

    }
}
