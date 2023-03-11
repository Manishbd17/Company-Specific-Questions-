// Backtracking - O(nm)

class Solution {
private: 
    bool dfs(vector<vector<char>> &board,int x,int y,int cnt,string word){
        if(cnt==word.length())
            return true; 
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size())   
            return false;
        if(board[x][y]!=word[cnt]) 
            return false; 
        char temp=board[x][y];
        board[x][y]=' ';
        bool found= dfs(board,x-1,y,cnt+1,word) || dfs(board,x,y-1,cnt+1,word) ||
        dfs(board,x,y+1,cnt+1,word) || dfs(board,x+1,y,cnt+1,word);
        board[x][y]=temp; 
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && dfs(board,i,j,0,word))
                    return true;
            }
        }
        return false; 
    }
};