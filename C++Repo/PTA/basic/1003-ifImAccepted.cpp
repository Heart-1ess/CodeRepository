#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

bool solve(string str){
    string a, b, c;
    int Ppos = -1, Tpos = -1;
    for (int i = 0; i < str.length(); i ++){
        if (str[i] != 'P' && str[i] != 'A' && str[i] != 'T'){
            return false;
        }
        if (str[i] == 'P'){
            if (Ppos != -1) return false;
            a = str.substr(0, i);
            Ppos = i;
        }
        if (str[i] == 'T'){
            if (Tpos != -1) return false;
            b = str.substr(Ppos + 1, i - Ppos - 1);
            c = str.substr(i + 1, 100);
            Tpos = i;
        }
    }
    if (b.length() == 0 || Ppos == -1 || Tpos == -1) return false;
    if (b.length() == 1 && a.length() != c.length()) return false;
    if (c.length() == b.length() * a.length()) return true;
    else return false;
}

int main(){
    string str;
    scanf("%d", &n);
    while (n --){
        cin >> str;
        if (solve(str)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}