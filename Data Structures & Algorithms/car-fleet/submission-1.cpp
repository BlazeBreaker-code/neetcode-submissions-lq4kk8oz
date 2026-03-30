class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // A cars are driving on one lane -> we are given the position and speed of them 
        // if a car catches up to another car they will be in a group and travel at the same speed 
        // as the car in front

        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }

        std::sort(cars.rbegin(), cars.rend()); // reverse order sort
        std::stack<double> st;

        for (auto& [pos, spd] : cars) {
            // distance / speed = time 
            double time = (double)(target - pos) / (double)spd;
            if (st.empty() || time > st.top()) st.push(time);
        }


        return st.size();
    }
};
