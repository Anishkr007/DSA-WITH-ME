class Solution {
public:
    void reverse(vector<vector<int>>& grid,int i,int j,int col){
        while(i<j){
            swap(grid[i/col][i%col],grid[j/col][j%col]);
            i++;
            j--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int row=grid.size();
        int col=grid[0].size();

        

        int n=row*col;

         k=k%n;
        if(k==0) return grid;


        

        reverse(grid,0,n-1,col);
        reverse(grid,0,k-1,col);
        reverse(grid,k,n-1,col);

        return grid;


    }
};