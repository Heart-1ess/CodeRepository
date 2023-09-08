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

class Solution{
public:
    int maxDepth(TreeNode* root){
        if (root == nullptr){ return 0; }
        else { return max(maxDepth(root -> left), maxDepth(root -> right)) + 1; }
    }
};

TreeNode* createTree(vector<int> array){
    vector<int>::iterator it = array.begin();
    if (it == array.end()){ return nullptr; }
    TreeNode* root = new TreeNode(*it);
    it ++;
    if (it == array.end()) { return root; }
    queue<TreeNode*> q;
    q.push(root);
    while (q.empty() == false){
        TreeNode* node = q.front();
        q.pop();
        if (*it != -1){
            node -> left = new TreeNode(*it);
            q.push(node -> left);
        }
        it ++;
        if (it == array.end()) { return root; }
        if (*it != -1){
            node -> right = new TreeNode(*it);
            q.push(node -> right);
        }
        it ++;
        if (it == array.end()) { return root; }
    }
    return root;
}

int main(){
    vector<int> array = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* tree = createTree(array);
    Solution sol = Solution();
    cout << sol.maxDepth(tree) << endl;
    return 0;
}