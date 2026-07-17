class Solution {
public:
    void dfs(int row,int col, int oldcolor,int color,vector<vector<int>>& image){
        int n=image.size();
        int m=image[0].size();

        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};

        image[row][col]=color;

        for(int i=0;i<4;i++){
            int nr=row+delrow[i];
            int nc=col+delcol[i];

            if(nr>=0 && nc>= 0 && nr<n && nc<m && image[nr][nc]==oldcolor){
                dfs(nr,nc,oldcolor,color,image);
            }
        }


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        if(image[sr][sc]==color){
            return image;
        }

        int oldcolor=image[sr][sc];

        dfs(sr,sc,oldcolor,color,image);

        return image;
    }
};