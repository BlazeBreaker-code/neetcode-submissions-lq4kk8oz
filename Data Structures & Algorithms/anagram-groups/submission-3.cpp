class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // for this question we want to order the strings and
        // then we want to use that as a mapping
        std::unordered_map<string, vector<string>> map;

        for (const string& s : strs) {
            string sortedS = s;
            std::sort(sortedS.begin(), sortedS.end());
            map[sortedS].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(map.size());
        for (auto [key, list] : map) {
            res.push_back(list);
        }

        return res;
    }
};
