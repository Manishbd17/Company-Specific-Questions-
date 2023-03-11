//Matrix -- BFS

class Solution {
public:

    pair<int,int> coordinates(int num,int n){
        int r=n-(num-1)/n-1;
        int c=(num-1)%n;
        if(r%2==n%2)
            return {r,n-c-1};
        return {r,c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int steps=0;
        queue<int> q;
        q.push(1);
        int n=board.size(); 
        vector<vector<bool>> visited(n,vector<bool> (n));
        visited[n-1][0]=true; 
        while(!q.empty()){
            int z=q.size();
            while(z--){
                int x=q.front();
                if(x==n*n)
                    return steps; 
                q.pop();
                for(int j=1;j<=6;j++){
                    if(x+j>n*n)
                        break; 
                    pair<int,int> p=coordinates(x+j,n);
                    int a1=p.first,a2=p.second;
                    if(visited[a1][a2])
                        continue;
                    visited[a1][a2]=true;
                    if(board[a1][a2]!=-1)
                        q.push(board[a1][a2]);
                    else 
                        q.push(x+j);
                }
            }
            steps++;
        }
        return -1; 
    }
};