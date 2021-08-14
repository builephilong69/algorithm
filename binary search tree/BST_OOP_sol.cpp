#include<iostream>
using namespace std;
class BST
{
private:
    int data;
    BST *left;
    BST *right;
public:
    BST()
    {
        this->data = 0;
        left = NULL;
        right = NULL;
    }
    BST(int data)
    {
        this->data= data;
        left=right=NULL;
    }
    BST* Insert( BST* root,int value)
    {
        if(root == NULL)
        {
            root = new BST(value);
        }
        else if(root->data <= value)
        {
            root = Insert(root->left,value);
        }
        else
        {
            root = Insert(root->right, value);
        }
        return root;
    }
    friend void Inorder(BST* root);
};
void Inorder(BST* root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    cout<<root->data<<endl;
    Inorder(root->right);
}
int main()
{
    BST b,*root=NULL;
    root = b.Insert(root, 15);

    Inorder(root);
}
