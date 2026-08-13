class Solution {
    private int find(int ledd[], int node) {
        if (ledd[node] != node) {
            ledd[node] = find(ledd, ledd[node]);
        }
        return ledd[node];
    }

    private void join(int[] ld, int rtld, int lfld) {
        ld[find(ld, rtld)] = find(ld, lfld);
    }

    private int getIndex(int r, int c, int col) {
        return r * col + c + 1;
    }

    public int latestDayToCross(int R, int C, int[][] cells) {
        int totalcells = R * C;
        int[] parent = new int[totalcells + 2];
        
        for (int idx = 0; idx <= totalcells + 1; idx++) {
            parent[idx] = idx;
        }

        int topnode = 0;
        int bottomnode = totalcells + 1;
        int[][] grid = new int[R][C];
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                grid[row][col] = 1; 
            }
        }

        int csize = cells.length;
        int[] dRow={-1,1,0,0};
        int[] dCol={0,0,-1,1};

        for(int day=csize-1;day>=0;day--){
            int r=cells[day][0]-1;
            int c=cells[day][1]-1;
            grid[r][c]=0;
            int currNode=getIndex(r,c,C);
            for(int idx=0;idx<4;idx++){
                int ar=r+dRow[idx];
                int ac= c+ dCol[idx];
                if(ac>=0 && ac<C && ar>=0 && ar<R && grid[ar][ac]==0){
                    join(parent,currNode,getIndex(ar,ac,C));
                }
            }   
            if(r==0){
                join(parent,currNode,topnode);
            }
            if(r==R-1){
                join(parent,currNode,bottomnode);
            }
            
             if(find(parent,topnode)==find(parent,bottomnode)){
                 return day;
            }
        }
        return 0;
    }

}