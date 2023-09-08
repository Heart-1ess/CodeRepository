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
    if (it == array.end()) { return nullptr; }
    TreeNode* root = new TreeNode(*it);
    it ++;
    if (it == array.end()){ return root; }
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
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<int> temp;
        vector<vector<int>> result;
        queue<TreeNode*> buf, q;
        q.push(root);
        if (root == nullptr){ return result; }
        do{
            queue<TreeNode*> emptyq;
            swap(emptyq, buf);
            while (q.empty() == false){
                TreeNode* node = q.front();
                temp.push_back(node -> val);
                q.pop();
                if (node -> left != nullptr){
                    buf.push(node -> left);
                }
                if (node -> right != nullptr){
                    buf.push(node -> right);
                }
            }
            result.push_back(temp);
            temp.clear();
            q = buf;
        } while (buf.empty() == false);
        return result;
    }
};

int main(){
    vector<int> array = {};
    TreeNode* tree = createTree(array);
    Solution sol = Solution();
    vector<vector<int>> result = sol.levelOrder(tree);
    for (vector<vector<int>>::iterator it_row = result.begin(); it_row != result.end(); it_row ++){
        for (vector<int>::iterator it = (*it_row).begin(); it != (*it_row).end(); it ++){
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}