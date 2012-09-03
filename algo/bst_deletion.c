#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    struct node* left;
    struct node* right;
    int data;
}node;

void insert_node(node** root, int data)
{
    node* curnode = *root;
    if (!curnode)
    {
        curnode = malloc(sizeof(node));
        curnode->left = NULL;
        curnode->right = NULL;
        curnode->data = data;
        *root = curnode;
        return;
    }

    if (data < curnode->data)
        insert_node(&curnode->left, data);
    else if (data > curnode->data)
        insert_node(&curnode->right, data);
    else
        return;
}

void delete(node* delnode, node* parent)
{   
    int value = delnode->data;
    node** pchild = NULL;
    if (value < parent->data)
        pchild = &(parent->left);
    else
        pchild = &(parent->right);

    // case 1: Node has no child nodes
    if (delnode->left == NULL && delnode->right == NULL)
    {        
        *pchild = NULL;
        free(delnode);
    }        
    // case 2: Only left node
    // Assign left child as left child of parent
    else if (delnode->right == NULL)
    {
        *pchild = delnode->left;
        free(delnode);
    }
    // case 3: node has both left and right children
    // Replace node to be removed with min child of that right subtree
    // and delete duplicate min child node
    else
    {
        node* minchild = delnode->right;
        node** minparent = &(delnode->right);
        while(minchild->left)
        {
            minparent = &(minchild->left);
            minchild = minchild->left;
        }
        delnode->data = minchild->data;
        *minparent = NULL;
        free(minchild);
    }        
}

void delete_node (node** root, int value)
{
    node* curnode = *root;
    node* parent = curnode;
    if (!curnode)
        return;
    while (curnode && curnode->data != value)
    {   
        parent = curnode;
        if (value < curnode->data) 
            curnode = curnode->left;
        else if (value > curnode->data)
            curnode = curnode->right;
    }
    if (curnode)
        delete(curnode, parent); 
}    

void make_tree (node** root)
{
    int data[] = {5, 2, 21, 3, 9, 19, 25, -4, 18};
    int i;

    for (i = 0; i < (sizeof(data)/sizeof(int)); i++)
        insert_node(root, data[i]);
}

void traverse_tree(node* root)
{
    if (root)
    {
        traverse_tree(root->left);
        printf("%d ", root->data);
        traverse_tree(root->right);
    }
}    

int main()
{
    node* tree = NULL;
    make_tree(&tree);
    traverse_tree(tree); 
    printf("\n");
    delete_node(&tree, -4);
    traverse_tree(tree); 
    printf("\n");
    delete_node(&tree, 18);
    traverse_tree(tree); 
    printf("\n");
    delete_node(&tree, 5);
    traverse_tree(tree); 
    printf("\n");

    return 0;
}
