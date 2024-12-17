#include "bintree.h"

#include <stdlib.h>
#include <stdio.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree)
{
    Address address = newTreeNode(root);
    if (address != NULL)
    {
        LEFT(address) = left_tree;
        RIGHT(address) = right_tree;
    }

    return address;
}

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
{
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val)
{
    Address address = (Address) malloc(sizeof(TreeNode));
    if (address != NULL)
    {
        ROOT(address) = val;
        LEFT(address) = NULL;
        RIGHT(address) = NULL;
    }

    return address;
}

void deallocTreeNode (Address p)
{
    free(p);
}

boolean isTreeEmpty (BinTree p)
{
    return p == NULL;
}

boolean isOneElmt (BinTree p)
{
    if(isTreeEmpty(p))
    {
        return false;
    }
    else
    {
        return (LEFT(p) == NULL && RIGHT(p) == NULL);
    }
}

boolean isUnerLeft (BinTree p)
{
    if(isTreeEmpty(p))
    {
        return false;
    }
    else
    {
        return (LEFT(p) != NULL && RIGHT(p) == NULL);
    }
}

boolean isUnerRight (BinTree p)
{
    if(isTreeEmpty(p))
    {
        return false;
    }
    else
    {
        return (LEFT(p) == NULL && RIGHT(p) != NULL);
    }
}

boolean isBinary (BinTree p)
{
    if(isTreeEmpty(p))
    {
        return false;
    }
    else
    {
        return (LEFT(p) != NULL && RIGHT(p) != NULL);
    }
}

void printPreorder(BinTree p)
{
    if (isTreeEmpty(p))
    {
        printf("()");
    }
    else
    {
        printf("(");
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
}

void printInorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p))
    {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p)
{
    if (isTreeEmpty(p))
    {
        printf("()");
    }
    else
    {
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
        printf(")");
    }
}

void printTreeHelper(BinTree p, int current_indent, int indent_step)
{
    if (isTreeEmpty(p))
    {
        return;
    }

    // Print indentation
    for(int i = 0; i < current_indent; i++)
    {
        printf(" ");
    }

    // Print node's info
    printf("%d\n", ROOT(p));

    // Recurse on left and right children with increased indentation
    printTreeHelper(LEFT(p), current_indent + indent_step, indent_step);
    printTreeHelper(RIGHT(p), current_indent + indent_step, indent_step);
}

void printTree(BinTree p, int indent_step)
{
    printTreeHelper(p, 0, indent_step);
}