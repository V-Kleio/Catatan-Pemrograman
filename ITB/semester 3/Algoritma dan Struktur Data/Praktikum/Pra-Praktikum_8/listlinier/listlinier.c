#include "listlinier.h"

#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) 
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL) 
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l) 
{ 
    *l = NULL; 
}

boolean isEmpty(List l) 
{ 
    return FIRST(l) == NULL; 
}

ElType getElmt(List l, int idx) 
{
	int i;
	Address p = FIRST(l);
	for (i = 0; i < idx; ++i) 
    {
		p = NEXT(p);
	}
	return INFO(p);
}


void setElmt(List *l, int idx, ElType val) 
{
	int i;
	Address p = FIRST(*l);
	for (i = 0; i < idx; ++i) 
    {
		p = NEXT(p);
	}
	INFO(p) = val;
}

int indexOf(List l, ElType val) 
{
	Address p = l;
	int idx = 0;
	while (p != NULL) {
		if (INFO(p) == val) 
        {
			return idx;
		}
		p = NEXT(p);
		idx++;
	}
	return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) 
{
	Address p = newNode(val);
	if (p == NULL) return;

	NEXT(p) = *l;
	*l = p;
}

void insertLast(List *l, ElType val) 
{
	if (isEmpty(*l)) 
    {
		insertFirst(l, val);
		return;
	}
	Address p = newNode(val);
	if (p == NULL) return;

	Address lp = FIRST(*l);
	while (NEXT(lp) != NULL) 
    {
		lp = NEXT(lp);
	}
	NEXT(lp) = p;
}

void insertAt(List *l, ElType val, int idx) 
{
	if (idx == 0) 
    {
		insertFirst(l, val);
		return;
	}
	Address p = newNode(val);
	if (p == NULL) return;

	Address lp = FIRST(*l);
	Address np = NEXT(lp);
	idx--;
	while (np != NULL && idx > 0) 
    {
		lp = NEXT(lp);
		np = NEXT(np);
		idx--;
	}

	NEXT(lp) = p;
	NEXT(p) = np;
}

void deleteFirst(List *l, ElType *val) 
{
	Address f = FIRST(*l);
	*val = INFO(f);
	*l = NEXT(f);
	free(f);
	f = NULL;
}

void deleteLast(List *l, ElType *val) 
{
	Address f = FIRST(*l);
	if (NEXT(f) == NULL) 
    {
		*val = INFO(f);
		*l = NULL;
		free(f);
		f = NULL;
		return;
	}

	while (NEXT(NEXT(f)) != NULL) 
    {
		f = NEXT(f);
	}
	*val = INFO(NEXT(f));
	free(NEXT(f));
	NEXT(f) = NULL;
	f = NULL;
}

void deleteAt(List *l, int idx, ElType *val) 
{
	if (idx == 0) 
    {
		deleteFirst(l, val);
		return;
	}

	Address lp = FIRST(*l);
	Address np = NEXT(lp);
	idx--;
	while (np != NULL && idx > 0) 
    {
		lp = NEXT(lp);
		np = NEXT(np);
		idx--;
	}
	NEXT(lp) = NEXT(np);
	*val = INFO(np);
	free(np);
	np = NULL;
}

void displayList(List l) 
{
	printf("[");
	Address p = FIRST(l);
	if (p != NULL) 
    {
		printf("%d", INFO(p));
		p = NEXT(p);
	}
	while (p != NULL) 
    {
		printf(",%d", INFO(p));
		p = NEXT(p);
	}
	printf("]");
}

int length(List l) 
{
	Address p = FIRST(l);
	int len = 0;
	while (p != NULL) 
    {
		len++;
		p = NEXT(p);
	}
	return len;
}

List concat(List l1, List l2) 
{
	List l3;
	CreateList(&l3);

	Address p = l1;
	while (p != NULL) 
    {
		insertLast(&l3, INFO(p));
		p = NEXT(p);
	}

	p = l2;
	while (p != NULL) 
    {
		insertLast(&l3, INFO(p));
		p = NEXT(p);
	}

	return l3;
}