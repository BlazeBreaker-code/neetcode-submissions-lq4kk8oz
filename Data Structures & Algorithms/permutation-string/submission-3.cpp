class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // check if s2 contains a permutation of s1
        if (s1.size() > s2.size()) return false;

        vector<int> first(26, 0);
        vector<int> second(26, 0); 

        for (int i = 0; i < s1.size(); ++i) {
            ++first[s1[i] - 'a'];
            ++second[s2[i] - 'a'];
        }

        if (first == second) return true;

        int left = 0; 
        for (int right = s1.size(); right < s2.size(); ++right) {
            --second[s2[left++] - 'a'];
            ++second[s2[right] - 'a'];
            if (first == second) return true;
        }

        return false;
    }
};
