#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<vector<char>> createPic(){
        char c;
        int row, col;
        vector<char> temp;
        vector<vector<char>> pic;
        cin >> row >> col;
        pic.clear();
        for (int j = 0; j < row; j ++){
            temp.clear();
            for (int k = 0; k < col; k ++){
                cin >> c;
                temp.push_back(c);
            }
            pic.push_back(temp);
        }
        return pic;
    }

    vector<vector<char>> revolvePic(vector<vector<char>>& pic, int angle){
        int rowNum = pic.size(), colNum = pic[0].size();
        vector<vector<char>> result;
        vector<char> temp;
        if (angle == 0){ return pic; }
        else if (angle == 90){
            int resultRow = colNum, resultCol = rowNum;
            for (int row = 0; row < resultRow; row ++){
                temp.clear();
                for (int col = 0; col < resultCol; col ++){
                    temp.push_back(pic[rowNum - col - 1][row]);
                }
                result.push_back(temp);
            }
        }
        else if (angle == 180){
            for (int row = 0; row < rowNum; row ++){
                temp.clear();
                for (int col = 0; col < colNum; col ++){
                    temp.push_back(pic[rowNum - row - 1][colNum - col - 1]);
                }
                result.push_back(temp);
            }
        }
        else if (angle == 270){
            int resultRow = colNum, resultCol = rowNum;
            for (int row = 0; row < resultRow; row ++){
                temp.clear();
                for (int col = 0; col < resultCol; col ++){
                    temp.push_back(pic[col][colNum - row - 1]);
                }
                result.push_back(temp);
            }
        }
        return result;
    }

    void printPic(vector<vector<char>>& pic){
        for (int rowNum = 0; rowNum < pic.size(); rowNum ++){
            for (int colNum = 0; colNum < pic[0].size(); colNum ++){
                cout << pic[rowNum][colNum];
            }
            cout << endl;
        }
        return;
    }
};

int main(){
    int count, angle;
    vector<vector<char>> pic, result;
    Solution sol = Solution();
    cin >> count;
    for (int i = 0; i < count; i ++){
        pic = sol.createPic();
        cin >> angle;
        result = sol.revolvePic(pic, angle);
        sol.printPic(result);
    }
    return 0;
}