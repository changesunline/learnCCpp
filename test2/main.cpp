#include <iostream>

#define maxSize 100000

// 结构体定义 - 数组
typedef struct {
    int data[maxSize];
    int length;
}Sqlist;
// 结构体定义 - 单链表
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode;
// 结构体定义 - 双链表
typedef struct DLNode {
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;

/**
 * 天勤 第2章-线性表
 */
// =============================================================== 单链表操作 ======================================================================
// 尾插法合并两个单链表
void mergeTop(LNode *A, LNode *B, LNode *&C) {
    LNode *p = A -> next;
    LNode *q = B -> next;
    LNode *r;
    C = A;
    C -> next = NULL;
    free(B);
    r = C;
    while (p!=NULL && q!=NULL) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
            r = r->next;
        } else {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    if (p!=NULL) {r->next = p;}
    if (q!=NULL) {r->next = q;}
}
// 头插法合并两个单链表
void mergeBottom(LNode *A, LNode *B, LNode *&C) {
    LNode *p = A -> next;
    LNode *q = B -> next;
    LNode *r, *s;
    C = A;
    C -> next = NULL;
    free(B);
    r = C;
    while (p!=NULL && q!=NULL) {
        if (p->data <= q->data) {
            s = p;
            p = p->next;
            s->next = r->next;
            r->next = s;
        } else {
            s = q;
            q = q->next;
            s->next = r->next;
            r->next = s;
        }
    }
    while (p!=NULL) {
        s = p;
        p = p->next;
        s->next = r->next;
        r->next = s;
    }
    while (q!=NULL) {
        s = q;
        q = q->next;
        s->next = r->next;
        r->next = s;
    }
}

// 尾插法建立链表C
void createListRTop(LNode *&C, int a[], int n) {
    LNode *s, *r;
    int i;

    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    r = C;

    for (i = 0; i < n; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}
// 头插法建立表C
void createListRBottom(LNode *&C, int a[], int n) {
    LNode *s, *r;
    int i;

    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    r = C;

    for (i = 0; i < n; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = r->next;
        r->next = s;
    }
}

// 删除结点
int findAndDelete(LNode *&C, int x) {
    LNode *p, *q;
    p = C;
    while (p->next != NULL) {
        if (p->next->data == x) break;
        p = p->next;
    }
    if (p->next == NULL) {
        return 0;
    } else {
        q = p->next;
        p->next = p->next->next;
        free(q);
        return 1;
    }
}


// =============================================================== 双链表操作 =======================================================================
