#include <iostream>

using namespace std;

void swap(char &a, char &b){
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void bubbleSort(char a[], int n){
    for (int i = 0; i < n - 1; i ++){
        for (int j = 0; j < n - i - 1; j ++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

int main(){
    char a[4] = "abc";
    bubbleSort(a, 4);
    return 0;
}