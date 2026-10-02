/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(!root) return false;

        queue<pair<TreeNode*,int>> q;

            q.push(make_pair(root,root->val));
            while(!q.empty()){
                auto[curr,val] = q.front();
                q.pop();

                if(!curr->left && !curr->right){
                       if(targetSum == val){
                        return true;
                       }
                }

                if(curr->left){
                    q.push({curr->left,val+curr->left->val});
                }

                if(curr->right){
                    q.push({curr->right,val+curr->right->val});
                }
            }
        
        return false;
    }
};