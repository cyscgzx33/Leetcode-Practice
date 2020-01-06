class TreeNode
{
  public:
  	int val;
  	TreeNode* left;
  	TreeNode* right;

  	TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution
{
  public:
  	/* method 1: using a [global] curr node and a stack */
  	// NOT GOING TO WORK...............
  	vector<int> preorder(TreeNode* root)
  	{
  		if (root == nullptr)
  			return {};

  		std::stack<TreeNode*> s;

  		TreeNode* curr = root;
  		std::vector<int> res;

  		while (curr != nullptr || s.size() > 0)
  		{
  			// record val into the vector
  			res.push_back(curr->val);
  			// push the curr node into the stack
  			s.push(curr);

  			// go left first
  			if (curr->left)
  			{
  				curr = curr->left;
  			}
  			else if (curr )
  			{

  			}
  		}

  		return res;
  	}


  	/* method 2: not using a [global] curr node but just push the root into the stack */
  	vector<int> preorder(TreeNode* root)
  	{
  		if (root == nullptr)
  			return {};

  		std::stack<TreeNode*> s;
  		s.push(root);
  		std::vector<int> res;

  		while (s.size() > 0)
  		{
  			TreeNode* curr = s.top();
  			s.pop();
  			res.push_back(curr->val);

  			if (curr->left) s.push(curr->left);
  			if (curr->right) s.push(curr->right);
  		}

  		return res;
  	}
};