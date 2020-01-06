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
  	/* method 1: using curr node and a stack */
  	vector<int> inorder(TreeNode* root)
  	{
  		if (root == nullptr)
  			return {};

  		std::stack<TreeNode*> s;
  		TreeNode* curr = root;
  		std::vector<int> res;

  		while (curr != nullptr || s.size() > 0)
  		{
  			// during the traversal, go left firstly
  			while (curr != nullptr)
  			{
  				s.push(curr);
  				curr = curr->left;
  			}

  			// if reach a leaf node while going left
  			///* step I: fetch the top element in the stack & pop it out
  			TreeNode* top = s.top();
  			s.pop();
  			///* step II: record the leaf node value into the vector
  			res.push_back(top->val); 
  			///* step III: go to the right branch and continue the traversal
  			curr = top->right;
  		}

  		return res;
  	}

  	/* method 2: not using curr node but just push the root into the stack */
  	/* NOT WORKING!!! WE NEED A CURR NODE TO RECORD IF A PATH HAS BEEN TRAVERSED */
  	vector<int> inorder(TreeNode* root)
  	{
  		if (root == nullptr)
  			return {};

  		std::stack<TreeNode*> s;
  		s.push(root);

  		std::vector<int> res;

  		while (s.size() > 0)
  		{
  			// during the travesal, go left firstly
  			TreeNode* curr = s.top();
  			if (curr->left)
  				s.push(curr->left);
  			else
  			{
  				// if reach a leaf node while going left
  				///* step I: fetch the top element in the stack & pop it out (here, s.top() == curr)
  				s.pop();
  				///* step II: record the leaf node value into the vector
  				res.push_back(curr->val);
  				///* step III: go to the right branch and continue the traversal
  				if (curr->right)
  					s.push(curr->right);
  			}
  		}

  		return res;
  	}
};