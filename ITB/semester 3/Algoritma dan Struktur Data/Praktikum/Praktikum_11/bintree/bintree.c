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
    Address address = (Address)malloc(sizeof(TreeNode));
    if (address != NULL)
    {
        ROOT(address) = val;
        LEFT(address) = NULL;
        RIGHT(address) = NULL;
    }

    return address;
}

void deallocTreeNode(Address p)
{
    free(p);
}

boolean isTreeEmpty(BinTree p)
{
    return p == NULL;
}

boolean isOneElmt(BinTree p)
{
    if (isTreeEmpty(p))
    {
        return false;
    }
    else
    {
        return (LEFT(p) == NULL && RIGHT(p) == NULL);
    }
}

boolean isUnerLeft(BinTree p)
{
    if (isTreeEmpty(p))
    {
        return false;
    }
    else
    {
        return (LEFT(p) != NULL && RIGHT(p) == NULL);
    }
}

boolean isUnerRight(BinTree p)
{
    if (isTreeEmpty(p))
    {
        return false;
    }
    else
    {
        return (LEFT(p) == NULL && RIGHT(p) != NULL);
    }
}

boolean isBinary(BinTree p)
{
    if (isTreeEmpty(p))
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
    for (int i = 0; i < current_indent; i++)
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

boolean isEqual(BinTree p1, BinTree p2)
{
    if (isOneElmt(p1) && isOneElmt(p2))
    {
        if (ROOT(p1) == ROOT(p2))
        {
            return true;
        }
    }
    if (isUnerLeft(p1) && isUnerLeft(p2))
    {
        return (isEqual(LEFT(p1), LEFT(p2)));
    }
    if (isUnerRight(p1) && isUnerRight(p2))
    {
        return (isEqual(RIGHT(p1), RIGHT(p2)));
    }
    if (isBinary(p1) && isBinary(p2))
    {
        return (isEqual(LEFT(p1), LEFT(p2)) && isEqual(RIGHT(p1), RIGHT(p2)));
    }
    return false;
}

int getMaximumDepth(BinTree p)
{
    if (isBinary(p))
    {
        if (getMaximumDepth(LEFT(p)) > getMaximumDepth(RIGHT(p)))
        {
            return 1 + getMaximumDepth(LEFT(p));
        }
        else
        {
            return 1 + getMaximumDepth(RIGHT(p));
        }
    }

    if (isUnerLeft(p))
    {
        return 1 + getMaximumDepth(LEFT(p));
    }

    if (isUnerRight(p))
    {
        return 1 + getMaximumDepth(RIGHT(p));
    }

    return 1;
}

BinTree createBinSearchTreeFromSortedArray(ElType *arr, ElType start, ElType end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    BinTree root = newTreeNode(arr[mid]);
    if (root != NULL || start == end)
    {
        LEFT(root) = createBinSearchTreeFromSortedArray(arr, start, mid - 1);
        RIGHT(root) = createBinSearchTreeFromSortedArray(arr, mid + 1, end);
    }
    return root;
}

int countNodes(BinTree p)
{
    if (isTreeEmpty(p))
    {
        return 0;
    }
    else
    {
        return countNodes(LEFT(p)) + countNodes(RIGHT(p)) + 1;
    }
}

void printPathUtil(BinTree p, ElType target, ElType path[], int pathIndex, boolean *found)
{
    if (p == NULL || *found)
    {
        return;
    }

    path[pathIndex] = ROOT(p);
    pathIndex++;

    if (ROOT(p) == target)
    {
        for (int i = 0; i < pathIndex; i++)
        {
            if (i > 0)
                printf(" -> ");
            printf("%d", path[i]);
        }
        printf("\n");
        *found = true;
        return;
    }

    printPathUtil(LEFT(p), target, path, pathIndex, found);
    printPathUtil(RIGHT(p), target, path, pathIndex, found);
}

void printPathToElement(BinTree p, ElType target)
{
    ElType path[100];
    boolean found = false;
    printPathUtil(p, target, path, 0, &found);
    if (!found)
    {
        printf("-1\n");
    }
}