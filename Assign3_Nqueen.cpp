#include<bits/stdc++.h>
using namespace std;
// striver
class Solution {
public:
    bool safe(int row,int col,vector<string> board,int n)
    {
        int dupRow = row;
        int dupCol = col;
        
        // upper diagonal
        while(dupRow>=0 && dupCol>=0)
        {
            if(board[dupRow][dupCol] == 'Q')
                return false;
            dupRow--;
            dupCol--;
        }
        
        // left row
        dupRow = row;
        dupCol = col;
        while(dupCol>=0)    
        {
            if(board[dupRow][dupCol] == 'Q')
                return false;
            dupCol--;
        }
        dupRow = row;
        dupCol = col;
        
        // lower diagonal
        while(dupRow<n && dupCol>=0)
        {
            if(board[dupRow][dupCol] == 'Q')
                return false;
            
            dupRow++;
            dupCol--;
        }
        
        return true;        
    }
    
    void solve(int col,vector<string> &board, vector<vector<string>> &ans,int n)
    {
        if(col == n){
            ans.push_back(board);
            return ;
        }
        
        for(int row=0;row<n;row++)
        {
            if(safe(row,col,board,n))
            {
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }   
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++)
            board[i] = s;

        solve(0, board, ans, n);
        
        return ans;
    }
};

int main() {
    int n = 0;
    cout << "Enter no. of n : ";
    cin >> n;

    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    cout<<"Total possible arrangements are : "<<ans.size()<<endl;
    cout<<endl;

    for (int i = 0; i < ans.size(); i++)
    {
        int k=0;
        cout<<"==============="<<endl;
        cout << "Arrangement " << i + 1 << "\n";
        cout<<"==============="<<endl;
        for (int j = 0; j < ans[0].size(); j++)
        {
            string str = ans[i][j];
            for(char c : str)
                cout<<c<<"  ";
            cout<<endl;
        }    
        cout << endl;
    }
    return 0;
}