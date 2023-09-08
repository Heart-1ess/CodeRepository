#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 1001

vector<string> buf;

int main(){
    string input;
    while (getline(cin, input)){
        buf.clear();
        if (cin.eof()){ break; }
        string temp;
        for (char p : input){
            if (p == ' ') {
                buf.push_back(temp);
                temp.clear();
            }
            else {
                temp += p;
            }
        }
        buf.push_back(temp);
        for (vector<string>::iterator it = buf.end() - 1; it != buf.begin(); it --){
            cout << *it << " ";
        }
        cout << buf[0] << endl;
    }
    return 0;
}

/*
input:
It is a apple

*/