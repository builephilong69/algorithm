#include<iostream>
#include<bits/stdc++.h>

using namespace std;
enum COLOR{RED,BLACK};

struct  Node
{
    int data ;
    int color;
    Node*left,*right,*parent;
    //Constructor
    Node(int value)
    {
        data=value;
        color = RED;
        left= right= parent = NULL;
    }
};
class RBTree
{
private:
    Node* root;
protected:
    void rotateLeft(Node*& ,Node*&);
    void rotateRight(Node*&, Node*&);
    void fixViolation(Node*&,Node*&);
public:
    RBTree()
    {
        root = NULL;
    }

    void inorder();
    void levelOrder();
    void insert(const int &);
};
Node* BSTInsert(Node*root, Node* pt)
{
    if(root ==NULL)
        return pt;
    if(pt->data < root ->data)
    {
        root ->left = BSTInsert(root->left,pt);
        root->left->parent = root;
    }
    else
    {
        root->right = BSTInsert(root->right,pt);
        root->right->parent=root;
    }
    return root;
}



void RBTree::rotateLeft(Node*& root, Node*&pt)
{
    Node *pt_right = pt->right;
    pt->right = pt_right->left;
    if(pt->right!=NULL)
        pt->right->parent=pt;

    pt_right->parent = pt->parent;
    if(pt->parent==NULL)
        root =pt_right;
    else if(pt == pt->parent->left)
        pt_right->parent->left= pt_right;
    else
        pt_right->parent->right = pt_right;

    pt->parent = pt_right;
    pt_right->left = pt;

}
void RBTree::rotateRight(Node *&root, Node*&pt)
{
    Node *pt_left = pt->left;
    pt->left = pt_left->right;

    if(pt->left !=NULL)
    {
        pt->left->parent = pt;
    }
    pt_left->parent = pt->parent;
    if(pt->parent==NULL)
        root=pt_left;
    else if(pt == pt->parent->left)
        pt_left->parent->left = pt_left;
    else
       pt_left->parent->right = pt_left;
    pt->parent = pt_left;
    pt_left->right = pt;
}
void RBTree::fixViolation(Node *& root, Node *& pt)
{
    Node* parent_pt = NULL;
    Node* grand_parent_pt = NULL;
    while(pt!=root&&pt->parent->color==RED&&pt->color!=BLACK)
    {
        parent_pt = pt->parent;
        grand_parent_pt = parent_pt->parent;
        //case A: parent is on the left side of grandparent
        if(parent_pt == grand_parent_pt->left)
        {
            Node* uncle_pt = grand_parent_pt->right;
            //case 1 : uncle color is red
            if(uncle_pt!=NULL&&uncle_pt->color==RED)
            {
                grand_parent_pt->color=RED;
                uncle_pt->color=BLACK;
                parent_pt->color=BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                //case 2: pt is the right child of parent
                if(pt == parent_pt->right)
                {
                    rotateLeft(root,parent_pt);

                    pt = parent_pt;
                    parent_pt=pt->parent;
                }
                //case 3 : pt is the left child of parent
                rotateRight(root,grand_parent_pt);
                swap(grand_parent_pt->color,parent_pt->color);
                pt = parent_pt;
            }
        }
        //case B:
        else
        {
            Node* uncle_pt = grand_parent_pt->left;
            if(uncle_pt!=NULL&&uncle_pt->color)
            {
                grand_parent_pt->color=RED;
                uncle_pt->color=BLACK;
                parent_pt->color=BLACK;

                pt = grand_parent_pt;
            }
            else
            {
                //case 2 : pt is left child of parent
                if(pt ==parent_pt->left)
                {
                    rotateRight(root, parent_pt);

                    pt=parent_pt;
                    parent_pt= pt->parent;
                }
                //case3
                rotateLeft(root, grand_parent_pt);
                swap(grand_parent_pt->color, parent_pt->color);
                pt = parent_pt;
            }

        }
    }
    root->color=BLACK;
}
void inorderHelper(Node* root)
{
    if(root == NULL)
        return;
    inorderHelper(root->left);
    cout<<root->data<<" ";
    inorderHelper(root->right);
}
void RBTree::inorder()
{
    inorderHelper(root);
}
void RBTree::insert(const int &data)
{
    Node* pt = new Node(data);

    root = BSTInsert(root, pt);
    fixViolation(root,pt);
}
int main()
{
    RBTree tree;
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.inorder();
}
