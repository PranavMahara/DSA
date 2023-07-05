//Program to find the maximum element in a binary search tree
//Max element will be the right most node.

# include <iostream>
using namespace std;

struct node* maxinBST(struct node *root)
{
if(root==NULL)
return NULL;
else if(root->right==NULL) //If there is no right subtree then root will be storing the maximum
return root;
else
maxinBST(root->right);
}
Same way, minimum element can be found by looking for the leftmost node. Change the code
accordingly.