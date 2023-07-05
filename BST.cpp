#include <iostream>
using namespace std;

class node
{
	node *left;
	node *right;
	int num;

public:

	node *root = NULL;
	
	node *insert(node *root, int info)		// node * insert and also node * root
	{
		if (root == NULL)
		{
			root = new node;		// just root, no node * root
			root->num = info;
			root->left = NULL;
			root->right = NULL;
		}
		else
		{
			if (info < root->num)
				root->left = insert(root->left, info);		// not just insert(root->left, info)
			else
				root->right = insert(root->right, info);
		}
		return root;		// VIMP
	}

	void inorder(node *root)
	{
		if (root != NULL)
		{
			inorder(root->left);		// left, root, right
			cout << root->num << " ";	// that root above means display 
			inorder(root->right);
		}
		return;
	}

	void preorder(node *root)
	{
		if (root != NULL)
		{
			cout << root->num << " ";
			preorder(root->left);
			preorder(root->right);
		}
		return;
	}

	void postorder(node *root)
	{
		if (root != NULL)
		{
			postorder(root->left);
			postorder(root->right);
			cout << root->num << " ";
		}
	}

	node *inordersucc(node *isucc)		// node "*" inorder and node * isucc
	{
		if (isucc == NULL)
			return NULL;
		while (isucc->left != NULL)
			isucc = isucc->left;
		return isucc;		// return it imp
	}

	node *del(node *root, int info)
	{
		node *temp;								//classic deletion requirement
		if (root == NULL)
			cout << "element not present";
		else if (info < root->num)
			root->left = del(root->left, info);		// not just del(root->left, info)
		else if (info > root->num)
			root->right = del(root->right, info);
		else
		{
			if (root->left != NULL && root->right != NULL)
			{
				temp = inordersucc(root->right);
				root->num = temp->num;
				root->right = del(root->right, root->num);		// here it aint info its root->num
			}
			else
			{
				temp = root;
				if (root->left != NULL)
					root = root->left;
				else if (root->right != NULL)
					root = root->right;
				else
					root = NULL;
				delete (temp);
			}
		}
		return root;		// return root
	}
};
int main()
{
	int choice, info;
	node obj;
	cout << "enter the data to be inserted\n";		// insert an element urself
	cin >> info;
	obj.root = obj.insert(obj.root, info);		//format 
	do
	{
		cout << "do u want to continue\n1-insert 2-delete\n";
		cout << "3-preorder 4-inorder 5-postorder 6-exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "enter the data to be inserted\n";
			cin >> info;
			obj.root = obj.insert(obj.root, info);		// why the f is it obj.root=
			break;
		case 2:
			cout << "enter the value to be deleted\n";
			cin >> info;
			obj.root = obj.del(obj.root, info);
			break;
		case 3:
			obj.preorder(obj.root);
			break;
		case 4:
			obj.inorder(obj.root);
			break;
		case 5:
			obj.postorder(obj.root);
			break;
		case 6:
			exit(0);
		}
	} while (choice != 6);
}