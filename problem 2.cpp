#include <iostream>
using namespace std;

struct node
{
    int value;
    float cg;
    string id;
	node *left;
	node *right;
};

struct node *cg = NULL;

void insert(int key, node *leaf)
{
    if(cg == NULL)
    {
		cg = new node;
		cg->value = key;
		cg->left = NULL;
		cg->right = NULL;
	}

	else
    {
        if(key < leaf->value)
        {
            if(leaf->left != NULL)
            {
                insert(key, leaf->left);
            }

            else
            {
                leaf->left = new node;
                leaf->left->value = key;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        }

        else if(key > leaf->value)
        {
            if(leaf->right != NULL)
            {
                insert(key, leaf->right);
            }

            else
            {
                leaf->right = new node;
                leaf->right->value = key;
                leaf->right->right = NULL;
                leaf->right->left = NULL;
            }
        }
    }
}

struct node *search(int key, node *leaf)
{
	if(leaf != NULL)
    {
		if(key == leaf->value)
		{
		    cout << "Found." << endl;
			return leaf;
		}

		else if(key < leaf->value)
        {
			return search(key, leaf->left);
		}

		else
        {
			return search(key, leaf->right);
		}
	}

	else
    {
        cout << "Not Found." << endl;
		return NULL;
	}
}

void inorder_print(node *leaf)
{
	if(leaf != NULL)
    {
		inorder_print(leaf->left);
		cout << leaf->value << ", ";
		inorder_print(leaf->right);
	}
}

void postorder_print(node *leaf)
{
	if(leaf != NULL)
    {
		postorder_print(leaf->left);
		postorder_print(leaf->right);
		cout << leaf->value << ", ";
	}
}

void preorder_print(node *leaf)
{
	if(leaf != NULL)
    {
		cout << leaf->value << ", ";
		preorder_print(leaf->left);
		preorder_print(leaf->right);
	}
}

int main()
{
	insert(1.0, cg);
	insert(1.1, cg);
	insert(6.0, cg);
	insert(4.0, cg);
	insert(1.0, cg);
	insert(1.5, cg);
	insert(8.0, cg);
	insert(1.9, cg);

	cout << "In-order : ";
    inorder_print(cg);
    cout << endl << endl;
	cout << "Pre-order : " ;
	preorder_print(cg);
	cout << endl << endl;
	cout << "Post-order : " ;
	postorder_print(cg);
	cout << endl << endl;

	cout << "Search the item 4 : ";
    search(4.0, cg);
	cout << "Search the item 13 : ";
	search(1.3, cg);

    return 0;
}
