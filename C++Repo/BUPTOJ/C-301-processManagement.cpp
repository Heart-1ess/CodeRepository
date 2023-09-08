#include <bits/stdc++.h>

using namespace std;

struct Command{
    string op;
    int num1, num2;
    Command() : op(""), num1(-1), num2(-1){}
    Command(string op, int num1) : op(op), num1(num1), num2(-1){}
    Command(string op, int num1, int num2) : op(op), num1(num1), num2(num2){}
};

struct Process{
    bool status;
    vector<int> sons;
    Process() : status(false), sons(){}
    Process(bool status) : status(status), sons(){}
    Process(bool status, vector<int> sons) : status(status), sons(sons){}
};

class Solution{
public:
    void killProcess(vector<Process>& process, int pid){
        if (process[pid].status == false || pid == 0){ return; }
        while (process[pid].sons.begin() != process[pid].sons.end()){
            vector<int>::iterator it = process[pid].sons.end() - 1;
            killProcess(process, *it);
            process[pid].sons.pop_back();
        }
        process[pid].status = false;
    }

    void commandHandler(vector<Process>& process, Command com){
        if (com.op == "FORK"){
            process[com.num2].status = true;
            process[com.num1].sons.push_back(com.num2);
        }
        else if (com.op == "KILL"){
            killProcess(process, com.num1);
        }
        else if (com.op == "QUERY"){
            if (process[com.num1].status == true){
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
    }

    void processManagement(){
        //initiate
        vector<Process> process;
        process.push_back(Process(true)); // pid = 0;
        for (int i = 0; i < 100; i ++){
            process.push_back(Process());
        }
        //input times
        int times;
        string command;
        cin >> times;
        for (int j = 0; j < times; j ++){
            vector<string> buf;
            Command com = Command();
            cin >> com.op >> com.num1;
            if (cin.get() != '\n'){ cin >> com.num2; }
            commandHandler(process, com);
        }
    }
};

int main(){
    int count = 0;
    cin >> count;
    Solution sol = Solution();
    for (int i = 0; i < count; i ++){
        sol.processManagement();
    }
    return 0;
}

/*
input:

2
5
FORK 0 1
QUERY 1
KILL 1
QUERY 1
QUERY 2
1
QUERY 0

1
16
FORK 0 1
FORK 0 2
FORK 1 3
FORK 1 4
FORK 3 5
FORK 3 6
FORK 4 7
FORK 4 8
FORK 5 9
FORK 5 10
QUERY 10
KILL 3
QUERY 5
QUERY 6
QUERY 9
QUERY 10

*/