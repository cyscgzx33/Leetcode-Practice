**Binary Tree**
---
* Very challenging but fascinating algorithm type
* Usually correlated with **traversal**
* Can sometimes define a customized class `ResultType` to assist traversal, especially in problems related to **divide and conquer** or in some situations that one needs to **access father nodes**, here's an example of using this technique:
    ```C++
    class ResultType
    {
      public:
        int level;          // current level
        TreeNode* LCA;      // lowest common ancester
        ResultType(int l, TreeNode* root) : level(l), LCA(root) {}
    };
    ```

**Basic Sub-topics**
---
| # | Sub-topic | Classic Examples |
|---| --------- | ---------------- |
|1|[Binary Search Tree (BST)](BST/) | [Remove node in a BST](BST/remove_node_in_a_bst.cpp), [Inorder predecessor in BST](BST/inorder_predecessor_in_BST.cpp), [Inorder successor in BST](BST/inorder_successor_in_BST.cpp) |
|2|[Lowest Common Ancestor (LCA)](LCA/) | [Lowest common ancestor II](LCA/lowest_common_ancestor_II.cpp), [Smallest subtree with all the deepest nodes](ResultType/smallest_subtree_with_all_the_deepest_nodes.cpp) |
|3|[Questions using ResultType](ResultType/) | [Smallest subtree with all the deepest nodes](ResultType/smallest_subtree_with_all_the_deepest_nodes.cpp) |
|4| [Special Binary Tree Types](Special_Binary_Tree_Types/) | [Complete Tree](Special_Binary_Tree_Types/check_completeness_of_binary_tree.cpp)|

**References**
---
* [Wiki Page for Complete Binary Tree](https://en.wikipedia.org/wiki/Binary_tree)