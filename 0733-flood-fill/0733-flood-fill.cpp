class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&newMat,int oldcolor,int color){
        int n=newMat.size();

        int m=newMat[0].size();

        newMat[r][c]=color;

        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,-1,1};

        for(int i=0;i<4;i++){
           int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc >=0 && nr<n && nc < m && newMat[nr][nc]==oldcolor){

                dfs(nr,nc,newMat,oldcolor,color);
            }


        }


    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> newMat=image;

        int oldcolor=newMat[sr][sc];


        if(oldcolor==color) return newMat;

        dfs(sr,sc,newMat,oldcolor,color);

        return newMat;
    }
};