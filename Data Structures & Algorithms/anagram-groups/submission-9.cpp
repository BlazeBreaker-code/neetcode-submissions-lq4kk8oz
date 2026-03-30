class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> groups;
        for (string& s : strs) {
            string sortedS = s;
            std::sort(sortedS.begin(), sortedS.end());
            groups[sortedS].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& [_, group] : groups ) {
            ans.push_back(group);
        }

        return ans;
    }
};

// Time Complexity  : O(nlogn)
// Space Complexity : O(n)
