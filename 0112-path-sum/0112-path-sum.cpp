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
    bool solve(TreeNode *root , int targetSum , int sum){

        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            sum += root->val;
            if(sum==targetSum) return true;
            return false;
        }

        bool left = solve(root->left , targetSum , sum+root->val);
        bool right = solve(root->right , targetSum , sum+root->val);

        if(left||right) return true;
        return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root==NULL) return false;

       return  solve(root , targetSum , 0);
        
    }
};