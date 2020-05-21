/*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:
The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Hint #1  
Try to utilize the property of a BST.

Hint #2  
Try in-order traversal. (Credits to @chan13)

Hint #3  
What if you could modify the BST node's structure?

Hint #4  
The optimal runtime complexity is O(height of BST).
*/


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
    int pos=0;
    TreeNode* var=nullptr;
    TreeNode* inorderkth(TreeNode* root)
    {
        if(root== nullptr)  return root;            
        if(root->left!=nullptr){
            var= inorderkth( root->left); 
            if(var!=nullptr) return var;
        } 
        --pos;
         if(pos==0) return root;
        
        if(root->right!= nullptr){
            var= inorderkth( root->right);
            if(var!=nullptr) return var;
        }       
        return var;
    }
    int kthSmallest(TreeNode* root, int k) {
        pos=k;
        if(root== nullptr)
            return -1;
        if(root!=nullptr) 
            root=inorderkth(root);
        return root->val;
        
    }
};