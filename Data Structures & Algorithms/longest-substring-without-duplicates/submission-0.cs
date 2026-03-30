public class Solution 
{
    public int LengthOfLongestSubstring(string s) 
    {
        // How would I solve this.
        // We need to track our windowSize and then track which is the max.
        Dictionary<char, int> dict = new Dictionary<char, int>();
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.Length; right++)
        {
            char currentChar = s[right];

            if (dict.ContainsKey(currentChar))
            {
                left = Math.Max(dict[currentChar] + 1, left);
            }

            dict[currentChar] = right;
            maxLength = Math.Max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
