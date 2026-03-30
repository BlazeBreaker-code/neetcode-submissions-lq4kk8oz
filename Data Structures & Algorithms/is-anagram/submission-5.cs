public class Solution 
{
    public bool IsAnagram(string s, string t) 
    {
        if (s.Length != t.Length)
        {
            return false;
        }

        Char[] charArr = new Char[26];

        for (int i = 0; i < s.Length; i++)
        {
            charArr[s[i] - 'a']++;
            charArr[t[i] - 'a']--;
        }

        foreach (var count in charArr)
        {
            if (count != 0)
            {
                return false;
            }
        }

        return true;
    }
}
