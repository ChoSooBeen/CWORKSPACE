#include "linkedlist_node.h"
#include <stdlib.h>
#include <stdio.h>


// 공백 연결 리스트 생성
linkhead* createLinkedList(void) {
    linkhead *list = (linkhead *)malloc(sizeof(linkhead));
    list->head = NULL;
    return list;
}

//연결리스트의 전체 메모리 해제
void freeLinkedList(linkhead *h){
    node *n;
    while (h->head != NULL) {
        n = h->head;
        h->head = h->head->link;
        free(n);
        n = NULL;
    }
}

//연결리스트 순서대로 출력
void printList(linkhead *h){
    node *n;
    printf("list 출력 : (");
    n = h->head;
    while (n != NULL)
    {
        printf("%d", n->data);
        n = n->link;
        if (n != NULL) {
            printf(", ");
        }
    }
    printf(")\n");
}

//첫번째 노드로 삽입하는 연산
void insertFirstNode(linkhead *h, int x){
    node *n = (node *)malloc(sizeof(node));
    n->data = x;
    n->link = h->head;
    h->head = n;
}

//중간 노드(pre 뒤로)로 삽입하는 연산
void insertMiddleNode(linkhead *h, node *pre, int x){
    node *n = (node *)malloc(sizeof(node));
    n->data = x;
    if (h == NULL) {
        n->link = NULL;
        h->head = n;
    }
    else if(pre == NULL) {
        n->link = h->head;
        h->head = n;
    }
    else {
        n->link = pre->link;
        pre->link = n;
    }
}

//마지막 노드로 삽입하는 연산
void insertLastNode(linkhead *h, int x){
    node *n = (node *)malloc(sizeof(node));
    n->data = x;
    n->link = NULL;
    if (h->head == NULL) {
        h->head = n;
    }
    else {
        node *tmp = h->head;
        while (tmp->link != NULL) {
            tmp = tmp->link;
        }
        tmp->link = n;
    }
}

//노드 p 삭제하는 연산
void deleteNode(linkhead *h, node *p) {
    node *pre;
    if (h == NULL) { //빈 리스트일 경우
        printf("already empty!\n");
        return;
    }
    // 한개의 노드만 갖고 있을 경우
    if (h->head->link == NULL) {
        free(h->head);
        h = NULL;
        return;
    }
    //p가 없을 경우
    if (p == NULL) {
        printf("current node aleady empty!\n");
        return;
    }
    pre = h->head;
    while(pre->link != p) {
        pre = pre->link;
    }
    pre->link = p->link;
    free(p);
}

//리스트에서 x 탐색
node *searchNode(linkhead *h, int x) {
    node *tmp = h->head;
    while (tmp != NULL) {
        if (tmp->data == x) {
            return tmp;
        }
        tmp = tmp->link;
    }
    return tmp;
}