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
    delete(p);
    return node;
}

class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = new ListNode(-101, head);
        ListNode *result = head;
        int count = 0;
        while (p -> next != nullptr){
            p = p -> next;
            count ++;
        }
        if (count == 0){ return result; }
        int num = k % count;
        ListNode *front = new ListNode(-101, head);
        for (int i = 0; i < count - num; i ++){
            front = front -> next;
        }
        p -> next = result;
        result = front -> next;
        front -> next = nullptr;
        return result;
    }
};

int main(){
    vector<int> array = {};
    int k = 1;
    Solution sol = Solution();
    ListNode *head = createLinklist(array);
    ListNode *result = sol.rotateRight(head, k);
    for (ListNode *p = result; p != nullptr; p = p -> next){
        cout << p -> val << " ";
    }
}