/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool validateBST(TreeNode *root, int *min, int *max)
{
    int lmin, lmax;
    bool left = true;
    if (root->left) {
        left = validateBST(root->left, &lmin, &lmax);
        *min = lmin;
        if (!left || (lmax >= root->val))
           return false;
    } else {
        *min = root->val;
    }
    
    int rmin, rmax;
    bool right = true;
    if (root->right) {
        right = validateBST(root->right, &rmin, &rmax);
        *max = rmax;
        if (!right || (rmin <= root->val))
           return false;
    } else {
        *max = root->val;
    }
    
    return true;
}

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return true;
        
        int min, max;
        return validateBST(root, &min, &max);
    }
};

