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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p = new ListNode(0, list1);
        ListNode *q = new ListNode(0, list2);
        ListNode *result = p;
        while (p -> next != nullptr || q -> next != nullptr){
            if (p -> next == nullptr){
                p -> next = q -> next;
                break;
            }
            else if (q -> next == nullptr){
                break;
            }
            else{
                if (q -> next -> val > p -> next -> val){
                    p = p -> next;
                }
                else{
                    ListNode *temp = new ListNode(q -> next -> val, nullptr);
                    temp -> next = p -> next;
                    p -> next = temp;
                    q = q -> next;
                    p = p -> next;
                }
            }
        }
        ListNode *r = new ListNode;
        r = result;
        result = result -> next;
        r -> next = nullptr;
        delete(r);
        return result;
    }
};

int main(){
    vector<int> array1 = {1,2,4};
    vector<int> array2 = {1,3,4};
    Solution sol = Solution();
    ListNode *list1 = createLinklist(array1);
    ListNode *list2 = createLinklist(array2);
    ListNode *result = sol.mergeTwoLists(list1, list2);
    for (ListNode *p = result; p != nullptr; p = p -> next){
        cout << p -> val << " ";
    }
}