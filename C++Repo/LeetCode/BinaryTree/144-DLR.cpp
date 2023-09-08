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
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(*it);
    q.push(root);
    it ++;
    if (it == array.end()){ return root; }
    while (q.empty() == false){
        TreeNode* node = q.front();
        q.pop();
        if (*it != -1){
            node -> left = new TreeNode(*it);
            q.push(node -> left);
        }
        it ++;
        if (it == array.end()){ return root; }
        if (*it != -1){
            node -> right = new TreeNode(*it);
            q.push(node -> right);
        }
        it ++;
        if (it == array.end()){ return root; }
    }
    return root;
}

class Solution{
public:
    void DLR(TreeNode* root, vector<int> &result){
        if (root == nullptr){ return; }
        result.push_back(root -> val);
        DLR(root -> left, result);
        DLR(root -> right, result);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        DLR(root, result);
        return result;
    }
};

int main(){

    return 0;
}