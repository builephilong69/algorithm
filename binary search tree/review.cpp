#include<iostream>
using namespace std;
struct BST
{
    int data;
    BST* left;
    BST* right;
};
BST* MakeNew(int value)
{
    BST* root = new BST();
    root->data=value;
    return root;
}
BST* Insert(BST* root, int value)
{
    if(root ==NULL)
    {
        root = MakeNew(value);
    }
    else if(value <= root ->data)
    {
        root->left=Insert(root->left,value);
    }
    else
    {
        root->right = Insert(root->right,value);
    }
    return root;

}
void PrintTree(BST* root)
{
    if(root ==NULL)
        return;
    else
    {
        PrintTree(root->left);
        cout<<root->data<<" ";
        PrintTree(root->right);
    }
}
bool Search(BST* root, int value)
{

    if(root == NULL)
        return 0;
    else
    {
        if(root->data ==value)
        {
            return 1;
        }
        else if(value < root->data)
        {
            return Search(root->left,value);
        }
        else
        {
            return Search(root->right,value);
        }

    }


}
void SearchTree(BST* root, int value)
{
    if(Search(root,value))
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;
}
BST* FindMin(BST* root)
{
    if(root->left!=NULL)
        return root->left;
    return root;
}
BST* Delete(BST* root, int value)
{
    if(root==NULL)
        return root;
    else if(value < root->data)
    {
        root->left=Delete(root->left,value);
    }
    else if(value>root->data)
    {
        root->right = Delete(root->right,value);
    }
    else
    {
        if(root->right == NULL && root->left==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left == NULL)
        {
            BST* temp = root;
            root = root->right;
            delete temp;
            temp = NULL;
        }
        else if(root->right == NULL)
        {
            BST* temp = root;
            root=root->left;
            delete temp;
            temp =NULL;
        }
        else
        {
            BST* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root, temp->data);
        }

    }
    return root;
}
int main()
{
    BST* root = NULL;
    root=Insert(root,6);
    root = Insert(root,2);
    root = Insert(root,3);
    root = Insert(root,15);
    root = Insert(root,12);
    root = Insert(root,7);
    root = Insert(root,9);
    root = Insert(root,0);
    root= Delete(root,7);
    PrintTree(root);


}
