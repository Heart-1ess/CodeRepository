#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void LDR (TreeNode* root, vector<int> &result){
        if (root == nullptr){
            return;
        }
        LDR(root->left, result);
        result.push_back(root->val);
        LDR(root->right, result);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        LDR(root, result);
        return result;
    }
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

int main(){
    vector<int> array = {1, -1, 2, 3};
    vector<int> result;
    vector<int>::iterator it;
    TreeNode* root = createTree(array);
    Solution sol = Solution();
    result = sol.inorderTraversal(root);
    for (it = result.begin(); it != result.end(); it ++){
        cout << (*it) << " ";
    }
    return 0;
}