/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    /**
     * find the height of a target node (a general way)
     * for this specific question, we can also use the parent attribute
     * 0 means not found
     */
    int findHeight(ParentTreeNode* root, ParentTreeNode* target)
    {
        if (root == nullptr)
            return 0;
        if (root == target)
            return 1;
        
        int left = findHeight(root->left, target);
        int right = findHeight(root->right, target);

        if (left != 0)
            return left + 1;
        else if (right != 0)
            return right + 1;
        else return 0;
    }

    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        // write your code here
        int A_hgt = findHeight(root, A);
        int B_hgt = findHeight(root, B);

        if (A_hgt < B_hgt)
        {
            while (A_hgt < B_hgt)
            {
                B = B->parent;
                B_hgt--;
            }
        }
        else if (A_hgt > B_hgt)
        {
            while (A_hgt > B_hgt)
            {
                A_hgt--;
                A = A->parent;
            }
        }

        while (A != B)
        {
            A = A->parent;
            B = B->parent;
        }

        return A;
    }
};