#pragma once
// 리스트 노드
typedef struct node
{
    int data;
    struct node *link;
}node;

// 리스트 시작 노드
typedef struct linkhead
{
    node *head;
}linkhead;

linkhead* createLinkedList(void);
void freeLinkedList(linkhead *h);
void printList(linkhead *h);
void insertFirstNode(linkhead *h, int x);
void insertMiddleNode(linkhead *h, node *pre, int x);
void insertLastNode(linkhead *h, int x);
void deleteNode(linkhead *h, node *p);
node *searchNode(linkhead *h, int x);