public class Solution {
    public bool IsAnagram(string s, string t) {
        Dictionary<char, int> dict = new Dictionary<char, int>();

        if (s.Length != t.Length)
        {
            return false;
        }

        for (int i = 0; i < s.Length; i++)
        {
            if (!dict.ContainsKey(s[i]))
            {
                dict[s[i]] = 1;
            }
            else
            {
                dict[s[i]]++;
            }
        }

        for (int j = 0; j < t.Length; j++)
        {
            if (dict.ContainsKey(t[j]))
            {
                dict[t[j]]--;
            }
            else
            {
                return false;
            }
        }

        foreach (int count in dict.Values)
        {
            if (count != 0)
            {
                return false;
            }
        }

        return true;
    }
}
