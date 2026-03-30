class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // just return the order of the courses needed to be taken
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& prereq : prerequisites) {
            int course = prereq[0];
            int pre    = prereq[1];

            graph[pre].push_back(course);
            ++indegree[course];
        }

        std::queue<int> q;
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0) q.push(course); // we can take this course immediately
        }

        vector<int> order;
        while (!q.empty()) {
            int currCourse = q.front(); q.pop(); 
            order.push_back(currCourse);

            for (int nextCourse : graph[currCourse]) {
                if (--indegree[nextCourse] == 0) q.push(nextCourse);
            }
        }

        return (order.size() == numCourses) ? order : vector<int>{};
    }
};
