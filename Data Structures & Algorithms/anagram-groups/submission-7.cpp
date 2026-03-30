class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we want to create a map where we can use the sorted string as the key
        std::unordered_map<string, std::vector<string>> map;

        for (const string& s : strs) {
            string sortedS = s;
            std::sort(sortedS.begin(), sortedS.end());
            map[sortedS].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(map.size());

        for (auto& [_, list] : map) {
            ans.push_back(list);
        }

        return ans;
    }
};
