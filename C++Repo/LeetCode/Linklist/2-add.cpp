#include <bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode;
        ListNode* p = result;
        int CF = 0;
        p -> val = (l1 -> val + l2 -> val) % 10;
        CF = (l1 -> val + l2 -> val) / 10;
        l1 = l1 -> next;
        l2 = l2 -> next;
        while (l1 != nullptr || l2 != nullptr || CF != 0){
            if (l1 == nullptr && l2 == nullptr){
                ListNode *sum = new ListNode(CF);
                p -> next = sum;
                p = p -> next;
                CF = 0;
            }       
            else if (l1 == nullptr){
                ListNode *sum = new ListNode((l2 -> val + CF) % 10);
                CF = (l2 -> val + CF) / 10;
                l2 = l2 -> next;
                p -> next = sum;
                p = p -> next;
            }
            else if (l2 == nullptr){
                ListNode *sum = new ListNode((l1 -> val + CF) % 10);
                CF = (l1 -> val + CF) / 10;
                l1 = l1 -> next;
                p -> next = sum;
                p = p -> next;
            }
            else if (l1 != nullptr && l2 != nullptr){
                ListNode *sum = new ListNode((l1 -> val + l2 -> val + CF) % 10);
                CF = (l1 -> val + l2 -> val + CF) / 10;
                p -> next = sum;
                l1 = l1 -> next;
                l2 = l2 -> next;
                p = p -> next;
            }
        }
        return result;
    }
};

ListNode* createLinklist(vector<int> array){
    ListNode* node = new ListNode;
    ListNode *q = node;
    for (vector<int>::iterator it = array.begin(); it != array.end(); it ++){
        ListNode *temp = new ListNode((*it));
        q -> next = temp;
        q = q -> next;
    }
    ListNode *p = node;
    node = node -> next;
    free(p);
    return node;
}

int main(){
    vector<int> array1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> array2 = {9, 9, 9, 9};
    ListNode* list1 = createLinklist(array1);
    ListNode* list2 = createLinklist(array2);
    Solution sol = Solution();
    ListNode* result = sol.addTwoNumbers(list1, list2);
    for (ListNode *p = result; p != nullptr; p = p -> next){
        cout << p -> val << " ";
    }
    return 0;
}