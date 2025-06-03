#include<iostream>
using namespace std;
class BST
{
int data;
BST *left,*right;

public:
    BST()
    {
        data=0;
        left=right=NULL;
    }

    BST(int value)
    {
         data=value;
        left=right=NULL;
    }
BST *InsertNode(BST*root,int value)
{
    if(root==NULL)
    {
        return new BST(value);
    }
    if(value>root->data)
    {
        root->right=InsertNode(root->right,value);
    }
 else if (value<root->data)
 {
     root->left=InsertNode(root->left,value);
 }
 return root;
 }
 void inorder(BST*root)
 {
     if(root==NULL)
     {
         return;
     }
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
 }
 void postorder(BST*root)
 {
   if (root == NULL)
    {
        return;
    }
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
   }

 void preorder(BST*root)
  {
   if (root == NULL)
    {
        return;
    }
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
   }

void Search(BST*root, int data)
{
	int p = 0;
	BST *t = new BST();
	t = root;
	while(t != NULL)
	{
		p++;
		if(t->data == data)
		{
			cout<<"\ndata found at position: "<<p;

			return;
		}
		else if(t->data>data)
			t = t->left;
		else
			t = t->right;
	}
cout<<"\ndatanot found";
	return;
}

BST* Delete(BST* root,int value)
{

	if(root==NULL)
		return root;
	else if(value< root->data)
	{
		root->left= Delete(root->left,value);
	}
	else if(value> root->data)
	{
		root->right= Delete(root->right,value);
	}

	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		else if(root->left==NULL)
		{
			BST* t=root;
			root=root->right;
			delete root;
			return root;
		}
		else if(root->right==NULL)
		{
			BST* t=root;
			root=root->left;
			delete t;
			return root;
		}

	}
	return root;
}
void display(BST* root)
{
    if (root == NULL)
     {
         return;
         }
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }

 };
 int main()
 {
     int n;

     BST bst,*root=NULL;
    root=bst.InsertNode(root,70);
     bst.InsertNode(root,10);
     bst.InsertNode(root,20);
     bst.InsertNode(root,50);
     bst.InsertNode(root,60);
     bst.InsertNode(root,40);
     bst.InsertNode(root,90);
     bst.InsertNode(root,80);
     bst.InsertNode(root,30);
     cout<<"In-Order of the Binary Search Tree is: ";
    bst.inorder(root);
   cout<<"\nPost-Order of the Binary Search Tree is: ";
   bst.postorder(root);
   cout<<"\nPre-Order of the Binary Search Tree is: ";
   bst.preorder(root);
   cout<<"\nEnter the Element to be searched: ";
	cin>>n;
   cout<<"\nEnter the Element to be deleted: ";
	cin>>n;
    bst.Search(root,n);
    bst.Delete(root,n);
    cout<<"\nAfter delete elements are: "<<endl;
    bst.display(root);
    return 0;

 }
