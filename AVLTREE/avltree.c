#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

//이진 탐색 트리를 중위 순회하면서 출력
void display(node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

// 값이 x인 노드의 위치 탐색
node* searchBST(node *root, int x) {
    node *p = root;
    int count = 0;
    while (p != NULL)
    {
        count++;
        if (x < p->data)
        {
            p = p->left;
        }
        else if (x > p->data) {
            p = p->right;
        }
        else {
            printf("%d번째에서 search success!\n", count);
            return p;
        }
    }
    count++;
    printf("%d번째에서 search fail\n", count);
    return p;
}

node* LL_rotate(node *parent) {
    node *root = parent->left;
    parent->left = root->right;
    root->right = parent;
    return root;
}

node* RR_rotate(node *parent) {
    node *root = parent->right;
    parent->right = root->left;
    root->left = parent;
    return root;
}

node* LR_rotate(node *parent) {
    node *left = parent->left;
    left = RR_rotate(left);
    return LL_rotate(parent);
}

node* RL_rotate(node *parent) {
    node *right = parent->right;
    right = LL_rotate(right);
    return RR_rotate(parent);
}

//서브 트리의 높이를 구하는 연산
int getHeight(node *p) {
    int height = 1;
    if (p == NULL) {
        return 0;
    }
    else if (p->left == NULL && p->right == NULL) {
        return 0;
    }
    else if (p->left != NULL) {
        height += getHeight(p->left);
    }
    else if (p->right != NULL) {
        height += getHeight(p->right);
    }
    return height;
}

// 균형인수를 구하는 연산
int getBF(node *p) {
    if (p == NULL) {
        return 0;
    }
    return getHeight(p->left) - getHeight(p->right);
}

//불균형이 발생한 경우 회전 연산 호출
node* rebalance(node *p) {
    int bf = getBF(p);
    // 현재 노드의 bf가 2 이상일 경우 - 양수 = 왼쪽
    if (bf > 1) {
        // 왼쪽 노드의 bf가 양수일 경우 = 왼쪽
        if (getBF(p->left) > 0) {
            p = LL_rotate(p);
        }
        else {
            p = LR_rotate(p);
        }
    }
    //현재 노드의 bf가 -2 이하일 경우 - 음수 = 오른쪽
    else if (bf < -1) {
        // 오른쪽 노드의 bf가 음수일 경우 = 오른쪽
        if (getBF(p->right) < 0) {
            p = RR_rotate(p);
        }
        else {
            p = RL_rotate(p);
        }
    }
    return p;
}

//AVL 트리에 노드 삽입 -> rebalance() 호출
node* insertNode(node *root, int x) {
    if (root == NULL) { //현재 아무것도 없을 경우
        root = (node *)malloc(sizeof(node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
    // root보다 작은 값일 경우 -> 왼쪽
    else if(x < root->data) {
        root->left = insertNode(root->left, x);
        root = rebalance(root);
    }
    // root보다 큰 값일 경우 -> 오른쪽
    else if(x > root->data) {
        root->right = insertNode(root->right, x);
        root = rebalance(root);
    }
    else {
        printf("same value exist!\n");
        return root;
    }
    return root;
}

int main(void) {
    node *root = NULL;

    // 트리 생성
    insertNode(root, 50);
    insertNode(root, 60);
    insertNode(root, 70);
    insertNode(root, 90);
    insertNode(root, 80);
    insertNode(root, 75);
    insertNode(root, 73);
    insertNode(root, 72);
    insertNode(root, 78);

    //연산 실행
    printf("트리 출력하기\n");
    display(root);
    printf("\nAVL Tree에서 70 탐색\n");
    searchBST(root, 70);
    printf("\nAVL Tree에서 72 탐색\n");
    searchBST(root, 72);
    printf("\nAVL Tree에서 77 탐색\n");
    searchBST(root, 77);
}