class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> map;

        for (string& s : strs) {
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
