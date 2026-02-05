class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inque(numCourses,0);

        for(auto &p : prerequisites){
           int course=p[0];
           int prereq=p[1];
            graph[prereq].push_back(course);
            inque[course]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inque[i]==0) q.push(i);
        }

        int target=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            target++;

            for(auto it:graph[node]){
                inque[it]--;
                if(inque[it]==0){
                    q.push(it);
                }
            }
        }
        return target==numCourses;
    }
};