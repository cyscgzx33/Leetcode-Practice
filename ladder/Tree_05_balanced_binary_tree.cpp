// return -1 if the subtree is not a balanced tree
int helper(TreeNode* root) {
    if (!root) return 0;
    int left_height = helper(root->left);
    int right_height = helper(root->right);

    if (left_height == -1 || right_height == -1) return -1;
    if ( abs(left_height - right_height) > 1) return -1;
    return std::max(left_height, right_height) + 1;    
}

bool isBalanced(TreeNode* root) {
    if ( helper(root) != -1 ) return true;
    else return false; 
}
