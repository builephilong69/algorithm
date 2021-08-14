#include<iostream>
using namespace std;
struct BST
{
    int data;
    BST* left;
    BST* right;
};
BST* GetNewNode(int value)
{
    BST* NewNode = new BST();
    NewNode->data = value;
    return NewNode;
}
BST* Insert(BST* root, int value)
{
    if(root==NULL)
    {root = GetNewNode(value);}
    else if(value <= root->data )
    {
        root->left = Insert(root->left,value);
    }
    else
    {
        root->right = Insert(root->right, value);
    }
    return root;
}
void Inorder(BST* root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    cout<<root->data<<endl;;
    Inorder(root->right);
}
bool Search(BST* root, int value)
{
    if(root == NULL)
        return false;
    else if(value < root->data)
        return Search(root->left,value);
    else if( value > root->data)
        return Search(root->right, value);
    else
        return true;
}
BST* FindSuccessor(BST* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}
BST* Delete(BST* root, int value)
{
    if(root == NULL)
        return root;
    else if( value < root->data)
        root->left= Delete(root->left,value);
    else if ( value > root->data)
        root-> right = Delete(root->right, value);
    else
    {
        //case 1 : no child
        if(root->right == NULL&& root->left == NULL)
        {
            delete root;
            root = NULL;
        }
        //case 2 : 1 child
        else if( root -> left = NULL)
        {
            BST* temp =  root;
            root = root->right;
            delete temp;
        }
        else if(root -> right = NULL)
        {
            BST* temp = root;
            root= root->left;
            delete temp;
        }
        //case 3 : 2 children
        else
        {
            BST* temp = FindSuccessor(root);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
      return root;

    }
}
int main()
{
    BST* root =NULL;
    root = Insert(root, 15);
    root = Insert(root, 6);
    root = Insert(root,18);
    root = Insert(root,3);
    root = Insert(root,7);
    root = Insert(root,17);
    root = Insert(root, 20);
    root = Insert(root, 2);
    root = Insert(root,4);
    root = Insert(root,13);
    root = Insert(root,9);



    Delete(root, 9);

    Inorder(root);
}
