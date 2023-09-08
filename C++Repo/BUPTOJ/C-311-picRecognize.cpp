#include <bits/stdc++.h>

using namespace std;

struct Position{
    int rowNum, colNum;
    Position leftAbove(Position p){
        p.rowNum --;
        p.colNum --;
        return p;
    }
    Position onAbove(Position p){
        p.rowNum --;
        return p;
    }
    Position rightAbove(Position p){
        p.rowNum --;
        p.colNum ++;
        return p;
    }
    Position onLeft(Position p){
        p.colNum --;
        return p;
    }
    Position onRight(Position p){
        p.colNum ++;
        return p;
    }
    Position leftUnder(Position p){
        p.rowNum ++;
        p.colNum --;
        return p;
    }
    Position onUnder(Position p){
        p.rowNum ++;
        return p;
    }
    Position rightUnder(Position p){
        p.colNum ++;
        p.rowNum ++;
        return p;
    }
};

class Solution{
public:
    void createPic(vector<vector<int>>& pic, int& div){ 
        // create a pic from std::cin, input div as well
        vector<int> temp;
        int rowNum, colNum;
        cin >> rowNum >> colNum >> div;
        for (int row = 0; row < rowNum; row ++){
            temp.clear();
            for (int col = 0; col < colNum; col ++){
                int i;
                cin >> i;
                temp.push_back(i);
            }
            pic.push_back(temp);
        }
    }

    bool isFull(vector<vector<int>>& type, Position& initPos){ // -> bool
        // judge if the vector isVisit is all true or there's some false elements
        for (int row = 0; row < type.size(); row ++){
            for (int col = 0; col < type[0].size(); col ++){
                if (type[row][col] == -1){ 
                    initPos.rowNum = row;
                    initPos.colNum = col;
                    return false; 
                }
            }
        }
        return true;
    }

    int isSameClass(vector<vector<int>>& pic,vector<vector<int>>& isVisit, Position initPos, Position nextPos, int div){
        //judge if overflow
        if (nextPos.rowNum < 0 || nextPos.rowNum >= pic.size() || nextPos.colNum < 0 || nextPos.colNum >= pic[0].size()){ return -1; } //overflow
        //if not overflow, judge if belongs to same class
        if (isVisit[nextPos.rowNum][nextPos.colNum] == -1 && abs(pic[initPos.rowNum][initPos.colNum] - pic[nextPos.rowNum][nextPos.colNum]) <= div){ 
            isVisit[nextPos.rowNum][nextPos.colNum] = 1;
            return 1; 
        } //unvisited and belongs to same class
        else {
            return 0; 
        } //visited or not belongs to same class
    }

    void BFS(vector<vector<int>>& pic,vector<vector<int>>& isVisit, int div, Position initPos){
        queue<Position> q;
        q.push(initPos);
        isVisit[initPos.rowNum][initPos.colNum] = 1;
        while (q.empty() == false){
            Position pos = q.front();
            vector<Position> nearPoint = {pos.leftAbove(pos), pos.onAbove(pos), pos.rightAbove(pos), pos.onLeft(pos), pos.onRight(pos), pos.leftUnder(pos), pos.onUnder(pos), pos.rightUnder(pos)};
            for (vector<Position>::iterator it = nearPoint.begin(); it != nearPoint.end(); it ++){
                if (isSameClass(pic, isVisit, pos, *it, div) == 1){
                    q.push(*it);
                }
            }
            q.pop();
        }
    }

    int recognizePic(vector<vector<int>>& pic, int div){
        int cnt = 0;
        Position initPos;
        initPos.rowNum = 0;
        initPos.colNum = 0;
        vector<vector<int>> isVisit;
        vector<int> temp;
        for (int row = 0; row < pic.size(); row ++){
            for (int col = 0; col < pic[0].size(); col ++){
                temp.push_back(-1);
            }
            isVisit.push_back(temp);
            temp.clear();
        }
        while (!isFull(isVisit, initPos)){
            BFS(pic, isVisit, div, initPos);
            cnt ++;
        }
        return cnt;
    }
};

int main(){
    vector<vector<int>> pic;
    Solution sol = Solution();
    int count, div;
    cin >> count;
    for (int i = 0; i < count; i ++){
        pic.clear();
        sol.createPic(pic, div);
        cout << sol.recognizePic(pic, div) << endl;
    }
    return 0;
}

/*测试用例
输入：
2
3 3 0
1 1 1
0 1 0
0 1 0
3 4 1
10 11 12 13
9 8 7 6
2 3 4 5

输出：
3
1
*/