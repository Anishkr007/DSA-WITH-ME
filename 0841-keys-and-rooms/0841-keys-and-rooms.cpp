class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int>vis(rooms.size(),0);

        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int room=q.front();
            q.pop();

            for(auto next: rooms[room]){
                if(!vis[next]){
                    vis[next]=1;
                    q.push(next);
                }
            }
        }

        for(int x : vis){
            if(x==0) return false;
        }

        return true;
    }
};