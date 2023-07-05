//Program to find the sum of all elements in a binary tree
//Similar to previous problem but here instead of adding 1, root’s data is added.

# include <iostream>
using namespace std;

int sum(struct node *root)
{
if(root==NULL)
return 0;
else
return (sum(root->left)+ (root->data)+sum(root->right));
}