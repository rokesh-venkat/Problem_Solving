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

    int SUM(vector<int> path){
        int sum =0;
        for(int s : path){
            sum+=s;
        }
        return sum;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};

        vector<vector<int>> pathnodes;
        queue<pair<TreeNode*,vector<int>>> q;
        
        q.push({root,{root->val}});

        while(!q.empty()){
            auto[curr,currpath] = q.front();
            q.pop();

            int curr_sum = SUM(currpath);

            if(!curr->left && !curr->right){
                if(curr_sum == targetSum){
                    pathnodes.push_back(currpath);
                }
            }

            if(curr->left){
                vector<int> newpath = currpath;
                newpath.push_back(curr->left->val);
                q.push({curr->left,{newpath}});
            }

            if(curr->right){
                vector<int> newpath = currpath;
                newpath.push_back(curr->right->val);
                q.push({curr->right,{newpath}});
            }
        }

        return pathnodes;
    }
};