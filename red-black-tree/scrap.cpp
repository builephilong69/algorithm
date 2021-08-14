#include<iostream>
#include <bits/stdc++.h>
using namespace std;
enum Color {RED, BLACK};
struct Node
{
    int data;
    bool Color;
    Node *left,*right,*parent;

    Node(int data)
    {
        this->data= data;
        left=right=parent=NULL;
        Color = RED;
    }
};

//Class to present RB Tree
class RBTree
{
private:
    Node* root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&,Node *&);
    void fixViolation(Node *&, Node *&);
public:
    //Constructor
    RBTree(){root = NULL;}
    void insert(const int &n);
    void inorder();
    void levelOrder();
};
//A recursive function to do inorder traversal
void inorderHelper(Node *root)
{
    if(root == NULL)
        return;
    inorderHelper(root->left);
    cout<<root->data;
    inorderHelper(root->right);
}
// A ultility function to insert a new node with given key
Node* BSTInsert(Node* root, Node* pt)
{
    if(root == NULL)
        return pt;
    else if(pt->data<=root->data)
    {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent= root;
    }
    return root;

}
//Ultility function to do level order traversal
void levelOrderHelper(Node* root)
{
    if(root == NULL)
        return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left !=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

void RBTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if(pt->right !=NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if(pt->parent == NULL)
        root = pt_right;

    else if(pt == pt->parent->left)
    {
        pt->parent->left=pt_right;
    }

    else
    {
        pt->parent->right= pt_right;
    }

    pt_right->left = pt;
    pt->parent->left = pt_right;
}
void RBTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;

    pt->left = pt_left->right;


    if(pt->left != NULL)
        pt_left->parent = pt->parent;

    pt_left->parent=pt->parent;
    if(pt->parent==NULL)
        root=pt_left;

    else if(pt == pt->parent->left)
    {
        pt_left->parent->left = pt_left;
    }

    else if(pt == pt->parent->right)
    {
        pt_left->parent->right= pt_left;
    }

    pt_left->right = pt;
    pt->parent = pt_left;
}
void RBTree::fixViolation(Node *&root, Node *&pt)
{
    Node* parent_pt=NULL;
    Node* grand_parent_pt=NULL;

    while((pt!=root)&&(pt->Color!=BLACK)&&
          (pt->parent->Color==RED))
    {
        parent_pt = pt->parent;
        grand_parent_pt= parent_pt->parent;

        // Case parent pt is a left child of grandparent
        if(parent_pt == grand_parent_pt->left)
        {
            Node* uncle_pt = grand_parent_pt->right;
            // Case 1 : uncle pointer is also red, only recoloring require
            if(uncle_pt!=NULL&&uncle_pt->Color==RED)
            {
                grand_parent_pt->Color=RED;
                uncle_pt->Color=BLACK;
                parent_pt->Color=BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                //Case 2: pt is a right child of parent_pt, need to rotate left to LLC
                if(parent_pt->right == pt)
                {
                   rotateLeft(root,parent_pt);
                   pt = parent_pt;
                   parent_pt = pt->parent;
                }
                //Case 3: pt is a left child of parent pt, rotate G right then swap color
                {
                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->Color,grand_parent_pt->Color);
                    pt=parent_pt;
                }
            }
        }
        else
        {
            Node* uncle_pt = grand_parent_pt->left;
            //Case 1: uncle pt is red
            if(uncle_pt!=NULL && uncle_pt->Color==RED)
            {
                grand_parent_pt->Color=RED;
                uncle_pt->Color=BLACK;
                parent_pt->Color=BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                //Case 2 pt is the left child of parent
                if(pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt=pt->parent;
                }
                rotateLeft(root, grand_parent_pt);
                swap(grand_parent_pt->Color,parent_pt->Color);
                pt = parent_pt;
            }
        }
    }
    root->Color=BLACK;
}
//Function to insert a new node with given data
void RBTree::insert(const int&data)
{
    Node*pt = new Node(data);

    root = BSTInsert(root, pt);

    fixViolation(root,pt);
}
void RBTree::inorder()     {  inorderHelper(root);}
void RBTree::levelOrder()  {  levelOrderHelper(root); }

// Driver Code
int main()
{
    RBTree tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    cout << "Inoder Traversal of Created Tree\n";
    tree.inorder();

    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();

    return 0;
}
