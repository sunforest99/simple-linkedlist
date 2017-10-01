//
//  main.cpp
//  linked list
//
//  Created by sun on 2017. 9. 19..
//  Copyright © 2017년 sun. All rights reserved.
//

#include <iostream>

class NODE
{
public:
	NODE* p_Next;
	int nData;
	NODE(){ p_Next = NULL; nData = 0; }
	~NODE();
};

class Linkedlist
{
public:
	NODE* p_Head;
	NODE* p_Tail;
	NODE* p_Current;
	Linkedlist() { p_Head = NULL; p_Tail = NULL; }
	~Linkedlist();
};

void CreateNode(Linkedlist* pl, int data);
void Release(Linkedlist* pl);
void printNodes(Linkedlist* L);


int main(int argc, const char * argv[])
{
	Linkedlist* plink = new Linkedlist();
	CreateNode(plink, 1);
	
	printNodes(plink);
	Release(plink);
	
	return 0;
}

void CreateNode(Linkedlist* pl, int nData)
{
	int i = 0;
	while(i < 10)
	{
		NODE* pNewnode = new NODE();
		pNewnode->nData = nData++;
		pNewnode->p_Next = NULL;
	
		if(pl->p_Head == NULL && pl->p_Tail == NULL)
		{
			pl->p_Head = pl->p_Tail = pNewnode;
		}
		else
		{
			pl->p_Tail->p_Next = pNewnode;
			pl->p_Tail = pNewnode;
		}
		pl->p_Current = pNewnode;
		i++;
	}
}

void Release(Linkedlist* pl)		// 이케하는거 맞나..?
{
	NODE* n;
	for( n = pl->p_Head; n != NULL; n = pl->p_Current)
	{
		pl->p_Current = n->p_Next;
		free(n);
	}
}

void printNodes(Linkedlist* L)
{
 NODE *p = L->p_Head;	putchar('[');
 while(p != NULL)
 {
	 std::cout << p->nData << ", ";
	 p = p->p_Next;
 }
 putchar(']');
 putchar('\n');
}
