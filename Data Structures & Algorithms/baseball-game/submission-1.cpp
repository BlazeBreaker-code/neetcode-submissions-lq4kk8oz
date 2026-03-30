class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for (int i = 0; i < operations.size(); ++i) {
            string op = operations[i];
            int n = record.size();
            if (op == "+") {
                record.push_back(record[n - 1] + record[n - 2]);
            } else if (op == "C") {
                record.pop_back();
            } else if (op == "D") {
                record.push_back(record[n - 1] * 2);
            } else {
                record.push_back(stoi(op));
            }
        }

        int total = 0;
        for (int score : record) total += score;
        return total;
    }
};