class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // return if you can finish all the courses with it's set prerequisites
        // if there is a cycle we can't finish
        // first lets create a graph of all the courses
        std::vector<vector<int>> graph(numCourses);
        for (auto& prereq : prerequisites) {
            int course = prereq[0];
            int pre    = prereq[1];
            graph[pre].push_back(course);
        }

        vector<int> state(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        for (int course = 0; course < numCourses; ++course) {
            if (hasCycle(graph, state, course)) return false;
        }

        return true;
    }

private:
    bool hasCycle(vector<vector<int>>& graph, vector<int>& state, int course) {
        if (state[course] == 1) return true; // currently visiting = cycle found
        if (state[course] == 2) return false; // visited already = safe

        state[course] = 1; // set as currently visiting 

        for (int nextCourse : graph[course]) { // visit all their prereqs
            if (hasCycle(graph, state, nextCourse)) return true;
        }

        state[course] = 2; // set as visited
        return false;
    }
};
