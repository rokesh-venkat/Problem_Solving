class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int M = grid[0].size();
        int N = grid.size();
       int peri =0;

        for(int r=0;r<N;r++){
            for(int c=0;c<M;c++){
                if(grid[r][c]==1){
                    peri+=4;
                    if(r>0 && grid[r-1][c]==1){
                        peri-=2;
                    }if(c>0 && grid[r][c-1]==1){
                        peri-=2;
                    }
                }
            }
        } 
       

        return peri;
    }
};