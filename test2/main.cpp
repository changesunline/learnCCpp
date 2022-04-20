#include <iostream>

#define maxSize 100000

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode;

/**
 * ���� ��2��-���Ա�
 */
// =============================================================== ��������� ======================================================================
// β�巨�ϲ�����������
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
// ͷ�巨�ϲ�����������
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

// β�巨��������C
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
// ͷ�巨������C
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

// ɾ��