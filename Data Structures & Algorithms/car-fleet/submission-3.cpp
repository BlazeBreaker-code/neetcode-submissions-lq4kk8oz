class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<pair<double, double>> cars;

        for (int i = 0; i < n; ++i) {
            cars.push_back({(double)position[i], (double)speed[i]});
        }
        
        std::sort(cars.rbegin(), cars.rend());
        std::stack<double> st;
        for (auto& [pos, spd] : cars) {
            double time = (target - pos) / spd;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};
