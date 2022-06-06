#include <iostream>
#include <queue>

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left && temp->right) {
                q.push(temp->left);
                q.push(temp->right);
                TreeNode* t = temp->left;
                temp->left = temp->right;
                temp->right = t;
            }else if (temp->left) {
                q.push(temp->left);
                temp->right = temp->left;
                temp->left = nullptr;
            }else if (temp->right){
                q.push(temp->right);
                temp->left = temp->right;
                temp->right = nullptr;
            }
        }
        return root;
    }
};

int main() {
    return 0;
}