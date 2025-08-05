#include<bits/stdc++.h>
using namespace std;

void print_board(vector<vector<int>>& board) 
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isGoal(vector<vector<int>>& puzzle, vector<vector<int>>& goal)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(puzzle[i][j] != goal[i][j]) 
                return false;
        }
    }
    return true;
}

void findEmptyBox(vector<vector<int>>& puzzle, int& x, int& y)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(puzzle[i][j] == 0)
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}

bool dfs(vector<vector<int>>& puzzle, vector<vector<int>>& goal, set<vector<vector<int>>>& visited, int depth_limit)
{
    if(isGoal(puzzle, goal)) {
        cout<<"Goal reached!\n";
        print_board(puzzle);
        return true;
    }

    if(depth_limit == 0) return false;

    visited.insert(puzzle);

    int x, y;
    findEmptyBox(puzzle, x, y);

    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    for(auto dir : dirs)
    {
        int nx = x + dir.first;
        int ny = y + dir.second;
        if(nx>=0 && ny>=0 && nx<3 && ny<3)
        {
            vector<vector<int>> new_puzzle = puzzle;
            swap(new_puzzle[nx][ny], new_puzzle[x][y]);
            
            if(!visited.count(new_puzzle))
            {
                if(dfs(new_puzzle, goal, visited, depth_limit - 1))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> puzzle = {{1, 2, 3}, {4, 5, 6}, {0, 7, 8}};
    vector<vector<int>> goal   = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    
    cout << "Start state:" << endl;
    print_board(puzzle);
    
    set<vector<vector<int>>> visited;
    int depth_limit = 20;   // increase depth if needed
    
    if(dfs(puzzle, goal, visited, depth_limit)) cout<<"Solution found using DFS!"<<endl;
    else cout<<"No solution found within depth limit"<<endl;

    return 0;
}
