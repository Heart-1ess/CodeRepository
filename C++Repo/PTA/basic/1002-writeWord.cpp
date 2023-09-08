#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 101

void transfer(int a, vector<string> &res){
    switch(a){
        case 0 : res.push_back("ling");break;
        case 1 : res.push_back("yi");break;
        case 2 : res.push_back("er");break;
        case 3 : res.push_back("san");break;
        case 4 : res.push_back("si");break;
        case 5 : res.push_back("wu");break;
        case 6 : res.push_back("liu");break;
        case 7 : res.push_back("qi");break;
        case 8 : res.push_back("ba");break;
        case 9 : res.push_back("jiu");break;
    }
}

int main(){
    string n;
    int result = 0;
    vector<string> res;
    cin >> n;
    for (int i = 0; i < n.length(); i ++){
        result += n.c_str()[i] - 48;
    }
    while(result){
        transfer(result % 10, res);
        result /= 10;
    }
    for (vector<string>::iterator it = res.end() - 1; it != res.begin(); it --){
        cout << *it << " ";
    }
    cout << *(res.begin()) << endl;
    return 0;
}