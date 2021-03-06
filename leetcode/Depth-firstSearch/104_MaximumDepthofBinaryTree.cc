#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1；
    }
};

int main(){
    Solution a;
    
    return 0;
}


