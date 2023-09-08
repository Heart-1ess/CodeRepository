#include <bits/stdc++.h>

using namespace std;

//definition of linklist
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

ListNode* createListFromArray(vector<int> array){
    ListNode* list = new ListNode(-1);
    ListNode* q = list;
    for (vector<int>::iterator it = array.begin(); it != array.end(); it ++){
        ListNode* p = new ListNode((*it));
        q -> next = p;
        q = q -> next;
    }
    ListNode* prev = list;
    list = list -> next;
    prev -> next = nullptr;
    delete(prev);
    return list;
}

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        int count[200] = {0};
        ListNode *prev = head;
        ListNode *result = new ListNode(-1);
        ListNode *resval = result;
        while (prev != nullptr){
            count[prev ->  val + 100] ++;
            prev = prev -> next;
        }
        prev = head;
        while (prev != nullptr){
            if (count[prev -> val + 100] == 1){
                ListNode* temp = new ListNode(prev -> val);
                resval -> next = temp;
                resval = resval -> next;
            }
            prev = prev -> next;
        }
        ListNode *p = result;
        result = result -> next;
        p -> next = nullptr;
        delete(p);
        return result;
    }
};

int main(){
    vector<int> array = {-100,-100,-99};
    ListNode *list = createListFromArray(array);
    Solution sol = Solution();
    ListNode* result = sol.deleteDuplicates(list);
    for (ListNode *p = result; p != nullptr; p = p -> next){
        cout << p -> val << " ";
    }
    return 0;
}