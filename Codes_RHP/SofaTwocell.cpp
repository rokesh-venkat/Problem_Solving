#include <bits/stdc++.h>
using namespace std;

int n, m;

class Sofa {
	private:
	int fsr, fsc, ssr, ssc; 
	char dir;
	int moves; 
	
	public:
	
	Sofa(int sr1,int sc1,int sr2,int sc2,char d,int m){
		fsr=sr1;
		fsc=sc1;
		ssr = sr2;
		ssc = sc2;
		dir=d;
		moves=m;
	}
	
	int getFsr() const { return fsr;}
	int getFsc() const { return fsc;}
	int getSsr() const {return ssr;}
	int getSsc() const {return ssc;}
	int getDir() const { return dir;}
	int getMoves() {return moves;}
};

bool isFree(const vector<vector<char>>& grid, int r, int c){
	if(r<0 || c<0 || r>=n || c>=m){
		return false;
	}
	
	return grid[r][c]!='H';
}

bool isDesti(Sofa curr, Sofa dest){
	return curr.getFsr() == dest.getFsr() && 
	       curr.getFsc() == dest.getFsc() && 
	       curr.getSsr() == dest.getSsr() &&
	       curr.getSsc() == dest.getSsc()  &&
           curr.getDir() == dest.getDir();
}

int isVert(char dir){
	return (dir=='H')?0:1;
}

int bfs(Sofa start, Sofa desti, const vector<vector<char>>& grid) {
     queue<Sofa> q;
     vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(2,false)));
     int startdir = (start.getDir()=='H')? 0:1;
     visited[start.getFsr()][start.getFsc()][startdir]=true;
     q.push(start);
     
     while(!q.empty()){
     	Sofa curr = q.front();
     	q.pop();
     	
     	int r1 = curr.getFsr();
        int c1 = curr.getFsc();

        int r2 = curr.getSsr();
        int c2 = curr.getSsc();

        char dir = curr.getDir();

        int moves = curr.getMoves();
        
        if(isDesti(curr,desti)){
        	return moves;
        }

     
     
     
     //move - up 
     if(isFree(grid,r1-1,c1) && isFree(grid,r2-1,c2)){
     	Sofa next(r1-1,c1,r2-1,c2,dir,moves+1);
     	
     	int d = isVert(dir);
     	
     	if (!visited[r1 - 1][c1][d]) {
                visited[r1 - 1][c1][d] = true;
                q.push(next);
        }
     }
     
     //move-down
     if(isFree(grid,r1+1,c1)&&isFree(grid,r2+1,c2)){
     	Sofa next(r1+1,c1,r2+1,c2,dir,moves+1);
     	if(!visited[r1+1][c1][isVert(dir)]){
     		visited[r1+1][c1][isVert(dir)]=true;
     		q.push(next);
     	}
     }
     
     //move-left
     
     if(isFree(grid,r1,c1-1)&&isFree(grid,r2,c2-1)){
     	Sofa next(r1,c1-1,r2,c2-1,dir,moves+1);
     	if(!visited[r1][c1-1][isVert(dir)]){
     		visited[r1][c1-1][isVert(dir)]=true;
     		q.push(next);
     	}
     }
     
     //move-right
     
     if(isFree(grid,r1,c1+1)&&isFree(grid,r2,c2+1)){
     	Sofa next(r1,c1+1,r2,c2+1,dir,moves+1);
     	if(!visited[r1][c1+1][isVert(dir)]){
     		visited[r1][c1+1][isVert(dir)]=true;
     		q.push(next);
     	}
     }
     
     if(dir=='H'){//vertical rotate
     	int r=r1;//for horizontal rows all equals
     	int lc= min(c1,c2);
     	//above 
     	if(isFree(grid,r-1,lc) && isFree(grid,r-1,lc+1)){
     		Sofa next(r-1,lc,r,lc,'V',moves+1);
     		if(!visited[r-1][lc][1]){
     			visited[r-1][lc][1]=true;
     			q.push(next);
     		}
     	}
     	//below
     	if(isFree(grid,r+1,lc) && isFree(grid,r+1,lc+1)){
     		Sofa next(r,lc,r+1,lc,'V',moves+1);
     		if(!visited[r][lc][1]){
     			visited[r][lc][1]=true;
     			q.push(next);
     		}
     	}
     	
     }else{//horizontal rotate
       int tr= min(r1,r2);
       int c=c1;
       
       //left
       if(isFree(grid,tr,c-1) && isFree(grid,tr+1,c-1)){
     		Sofa next(tr+1,c-1,tr+1,c,'H',moves+1);
     		if(!visited[tr+1][c-1][0]){
     			visited[tr+1][c-1][0]=true;
     			q.push(next);
     		}
     	}
     	
     	//right
     	if(isFree(grid,tr,c+1) && isFree(grid,tr+1,c+1)){
     		Sofa next(tr+1,c,tr+1,c+1,'H',moves+1);
     		if(!visited[tr+1][c][0]){
     			visited[tr+1][c][0]=true;
     			q.push(next);
     		}
     	}
     	
     }
     }
     return -1;
}

int main() {

    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int r = 0; r < n; r++){
        for (int c = 0; c < m; c++){
            cin >> grid[r][c];
        }
    }
    
    vector<pair<int,int>> startcell,desticell;
            
    for(int r=0;r<n;r++){
    	for(int c=0;c<m;c++){
    		if(grid[r][c]=='s'){
    			startcell.push_back({r,c});
    		}
    		if(grid[r][c]=='S'){
    			desticell.push_back({r,c});
    		}
    	}
    }
    
    
    int sr1 = startcell[0].first;
    int sr2= startcell[1].first;
    int sc1= startcell[0].second;
    int sc2= startcell[1].second;
    
    char stdir;
    
    if(sr1==sr2){
    	stdir='H';
    }else if(sc1==sc2){
    	stdir='V';
    }
    
    Sofa start(sr1,sc1,sr2,sc2,stdir,0);


   int dr1= desticell[0].first;
   int dc1= desticell[0].second;
   int dr2= desticell[1].first;
   int dc2 = desticell[1].second;
   
   char desdir;
   
   if(dr1==dr2){
   	desdir='H';
   }else if(dc1==dc2){
   	desdir='V';
   }

   Sofa desti(dr1,dc1,dr2,dc2,desdir,0);
   
   int ans = bfs(start,desti,grid);
   
   if(ans!=-1){
   	cout<<ans<<endl;
   }else{
   	cout<<"Impossible"<<endl;
   }

    

    return 0;
}