#include<iostream>
using namespace std;
struct BSTnode
{
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
};
BSTnode* GetNewNode(int data)
{
    BSTnode* newNode = new BSTnode();
    (newNode)->data= data;
    return newNode;
}
BSTnode* Insert(BSTnode* root, int value)
{
    if(root == NULL)
    {
        root = GetNewNode(value);
    }
    else if(root->data<=value)
    {
        root->right =Insert(root->right,value);
    }
    else
    {
       root->left =Insert(root->left,value);
    }
    return root;
}
void Inorder(BSTnode* root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<endl;
    Inorder(root->right);
}
bool Search(BSTnode* root, int value)
{
    if(root==NULL)
        return false;
    else if ( root->data < value)
        return Search(root->left,value);
    else if(root->data > value)
        return Search(root->right,value);
    else
        return true;
}
BSTnode* FindSuccessor(BSTnode* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}
struct BSTnode* Remove(struct BSTnode* root, int value)
{

    if(root == NULL)
        return root;
    else if(root->data<value)
        root->right= Remove(root->right,value);
    else if(root->data>value)
        root->left= Remove(root->left,value);

    else
    {
        //case 1: No child
        if(root->left == NULL&& root->right ==NULL)
        {
            delete root;
            root= NULL;

        }
        //case 2 : one child
        else if (root->right == NULL)
        {
            BSTnode* temp;
            temp = root;
            root = root->left;
            delete temp;

        }

        else if(root->left==NULL)
        {
            BSTnode* temp;
            temp=root;
            root= root->right;
            delete temp;

        }
        //case 3 : two children
        else
        {
            struct BSTnode* temp = FindSuccessor(root->right);
            root->data = temp->data;
            root->right = Remove(root->right, temp->data);

        }


    }
    return root;
}

int main()
{
    BSTnode* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);

	// Deleting node with value 5, change this value to test other cases
	root = Remove(root,1);

	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";



}
