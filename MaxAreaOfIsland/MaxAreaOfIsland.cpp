// MaxAreaOfIsland.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxAreaOfIsland {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = -1;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                if (grid[y][x] == 1) {
                    int area = connectedCheck(grid, y, x);
                    if (area > maxArea) maxArea = area;
                }
            }
        }

        return maxArea;
    }

    int connectedCheck(vector<vector<int>>& grid, int y, int x) {
        //cout << "y: " << y << ", x: " << x << endl;
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size()) return 0;

        //printf("y: %d, x: %d\n", y, x);
        if (grid[y][x] == 1) {
            grid[y][x] = 2;
            return (1 + connectedCheck(grid, y + 1, x) + connectedCheck(grid, y - 1, x) + connectedCheck(grid, y, x + 1) + connectedCheck(grid, y, x - 1));
        } else {
            return 0;
        }

    }


};


int main() {
    vector<vector<int>> grid = { {0,0,1,0,0,0,0,1,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                   {0,1,1,0,1,0,0,0,0,1,0,0,0},
                                   {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                   {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                   {0,0,0,0,0,0,0,0,1,0,1,0,0},
                                   {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                   {0,0,0,0,0,0,0,1,1,0,0,0,0} };
    //printf("%d, %d", grid.size(), grid[0].size());      // x = 13, y = 8

    MaxAreaOfIsland mai;
    cout << "maxArea is " << mai.maxAreaOfIsland(grid) << endl;
    //cout << grid[0][2];

}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
