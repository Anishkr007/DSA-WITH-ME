class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> inque(n,0);
        vector<vector<int>> graph(n);

        for(auto &p : prerequisites){
            int course=p[0];
            int prereq=p[1];

            graph[prereq].push_back(course);
            inque[course]++;
        }

        //queue

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inque[i]==0){
                q.push(i);
            }
        }
        //vector
        vector<int> ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : graph[node]){
                inque[it]--;
                if(inque[it]==0){
                    q.push(it);
                }

            }
        }
        if(ans.size()!=n){
            return {};
        }
        return ans;

    }
};