public class Solution 
{
    public bool IsPalindrome(string s) 
    {
        int left = 0;
        int right = s.Length - 1;

        while (left <= right)
        {
            while (left <= right && !char.IsLetterOrDigit(s[left]))
            {
                left++;
            }

            while (left <= right && !char.IsLetterOrDigit(s[right]))
            {
                right--;
            }

            if (left <= right && char.ToLower(s[right]) != char.ToLower(s[left]))
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
}
