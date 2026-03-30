class Solution {
public:
    bool isPalindrome(string s) {
        // We need to check left and right pointers till we get a character
        // then compare the lowercase letter on each side
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !std::isalnum(s[left])) ++left;
            while (left < right && !std::isalnum(s[right])) --right;
            if (std::tolower(s[left++]) != std::tolower(s[right--])) return false;
        }

        return true;
    }
};
