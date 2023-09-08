#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

TreeNode* createTree(vector<int> array){
    vector<int>::iterator it = array.begin();
    if (it == array.end()){ return nullptr; }
    TreeNode* root = new TreeNode((*it));
    it ++;
    if (it == array.end()){ return root; }
    //队列
    queue<TreeNode*> q;
    q.push(root);
    while (q.empty() == false){
        TreeNode* node = q.front();
        q.pop();
        if ((*it) != -1){
            node -> left = new TreeNode((*it));
            q.push(node -> left);
        }
        it ++;
        if (it == array.end()){ return root; }
        if ((*it) != -1){
            node -> right = new TreeNode((*it));
            q.push(node -> right);
        }
        it ++;
        if (it == array.end()){ return root; }
    }
    return root;
}

class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if (p == nullptr && q == nullptr){
            return true;
        }
        else if (p == nullptr || q == nullptr){
            return false;
        }
        else if (p -> val != q -> val){
            return false;
        }
        else {
            return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
        }
    }
};

int main(){
    vector<int> array1 = {1, 2, 3};
    vector<int> array2 = {1, 2, 3};
    TreeNode* tree1 = createTree(array1);
    TreeNode* tree2 = createTree(array2);
    Solution sol = Solution();
    cout << sol.isSameTree(tree1, tree2) << endl;
    return 0;
}