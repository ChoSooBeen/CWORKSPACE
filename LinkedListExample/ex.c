#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_node.h"

int main(void) {
    linkhead *h;

    h = createLinkedList();
    printf("linkedlist에 1, 2, 3 삽입하기\n");
    insertLastNode(h, 1);
    insertLastNode(h, 2);
    insertLastNode(h, 3);
    printList(h);

    printf("2 노드 탐색하기\n");
    node *two = searchNode(h, 2);
    if (two == NULL) {
        printf("no exist\n");
    }
    else {
        printf("exist!\n");
        printf("2 노드 뒤에 4 노드 삽입하기\n");
        insertMiddleNode(h, two, 4);
        printList(h);

        printf("2 노드 삭제하기\n");
        deleteNode(h, two);
        printList(h);
        return 0;
    }
}