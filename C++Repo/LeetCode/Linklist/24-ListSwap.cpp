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
    ListNode* swapPairs(ListNode* head) {
        ListNode* result = new ListNode(-1, head);
        ListNode *p = result;
        while (p -> next != nullptr && p -> next -> next != nullptr){
            ListNode *temp = p -> next -> next;
            p -> next -> next = temp -> next;
            temp -> next = p -> next;
            p -> next = temp;
            p = p -> next -> next;
        }
        ListNode *prev = result;
        result = result -> next;
        prev -> next = nullptr;
        delete(prev);
        return result;
    }
};

int main(){
    vector<int> array = {1, 2, 3, 4};
    Solution sol = Solution();
    ListNode *head = createLinklist(array);
    ListNode *result = sol.swapPairs(head);
    for (ListNode *p = result; p != nullptr; p = p -> next){
        cout << p -> val << " ";
    }
}