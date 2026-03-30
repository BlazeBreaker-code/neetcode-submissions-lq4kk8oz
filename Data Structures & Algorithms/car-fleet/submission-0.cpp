class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);

        for (int i = 0; i < n; ++i) {
            cars[i] = { position[i], double(target - position[i]) / speed[i] };
        } 

        std::sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double currFleetTime = 0;

        for (auto& car : cars) {
            double time = car.second;
            if (time > currFleetTime) {
                ++fleets;
                currFleetTime = time;
            }
        }

        return fleets;
    }
};
