class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // we want to look at the car closest to the destination first
        vector<pair<double, double>> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.push_back({ (double)position[i], (double)speed[i]});
        }

        std::sort(cars.begin(), cars.end(), [](const pair<double, double>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        std::stack<double> st;
        for (auto& [pos, spd] : cars) { // So what do we want to do with a stack cars that meet up with another become together into a fleet
            double dist = target - pos;
            double time = dist / spd; 

            if (st.empty() || time > st.top()) st.push(time); // since if the cars before will arrive later they won't become a fleet
        }

        return st.size();
    }
};
