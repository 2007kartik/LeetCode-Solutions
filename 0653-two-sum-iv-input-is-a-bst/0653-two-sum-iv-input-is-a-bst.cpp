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
    vector<int> arr;
    void inorder(TreeNode *root , int k){
        if(root==NULL) return ;

        inorder(root->left ,  k);
        arr.push_back(root->val);
        inorder(root->right , k);

    }
    bool findTarget(TreeNode* root, int k) {

        inorder(root , k);

        bool check = false;
        for(int i = 0;i<arr.size();i++){
            int val = arr[i];

            for(int j = i+1;j<arr.size();j++){
                if(val + arr[j]==k){
                    check = true;
                    break;
                }
            }
        }
        
        return check;
    }
};