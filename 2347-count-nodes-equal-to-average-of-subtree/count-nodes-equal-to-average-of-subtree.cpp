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
    pair<int,int> postOrder(TreeNode* root,int& count){
        if(!root){
            return {0,0};
        }

        auto left = postOrder(root->left,count);
        auto right = postOrder(root->right,count);

        int totalsum= left.first+right.first+root->val;
        int totalcount= left.second+right.second+1;

        if(totalsum/totalcount==root->val){
            count++;
        }
        return {totalsum,totalcount};
    }
    int averageOfSubtree(TreeNode* root) {
        int count =0;
        postOrder(root,count);
        return count;
        
    }
};