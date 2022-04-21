#include <iostream>
#define maxSize 100000

/**
 * 天勤 第2章-线性表
 */

// 结构体定义 - 数组
typedef struct {
    int data[maxSize];
    int length;
}Sqlist;
// 结构体定义 - 单链表结点
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode;
// 结构体定义 - 双链表结点
typedef struct DLNode {
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;

// =============================================================== 单链表操作 ======================================================================
// 尾插法合并两个单链表
void mergeBottom(LNode *A, LNode *B, LNode *&C) {
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
void mergeTop(LNode *A, LNode *B, LNode *&C) {
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

// 尾插法建立单链表
void createListRBottom(LNode *&C, int a[], int n) {
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
// 头插法建立单链表
void createListRTop(LNode *&C, int a[], int n) {
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
// 尾插法建立双链表
void createDLNodeBottom(DLNode *&L, int a[], int n) {
    DLNode *r, *s;
    int i;
    L = (DLNode *)malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    r = L;
    for (i = 0; i < n; ++i) {
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s; // r指针指向链表尾部
    }
    r->next = NULL;
}

// 查找结点
DLNode *findDLNode(DLNode *C, int x) {
    DLNode *p = C->next;
    while (p != NULL) {
        if (p->data == x) break;
        p = p->next;
    }
    return p;
}

// 插入结点
void insertDLNode(DLNode *p, DLNode *s) {
    s->next = p->next;
    p->next = s;
    s->prior = p;
    s->next->prior = s;
}

// =============================================================== 线性表元素逆置 ====================================================================
void reverse(int a[], int left, int right, int k) {
    int temp;
    // 定义left为数组a最左端位置，right为a最右端位置
    for (int i=left, j=right; i<left+k && i<j; ++i,--j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
void moveToEnd(int a[], int n, int k) {
    reverse(a, 0, k-1, k);
    reverse(a, 0, n-1, k);
}
void moveToEnd2(int a[], int n, int k) {
    reverse(a, 0, k-1, k);
    reverse(a, k, n-1, n-k);
    reverse(a, 0, n-1, n);
}


/**
 * 天勤 第3章-栈和队列
 */

// 结构体定义 - 顺序栈（数组）
typedef struct {
    int data[maxSize];
    int top;
}SqStack;
// 结构体定义 - 链栈结点（单链表）
typedef struct LSNode {
    int data;
    struct LSNode *next;
}LSNode;
// 结构体定义 - 顺序队列（数组）
typedef struct {
    int data[maxSize];
    int front; //队首
    int rear; //队尾
}SqQueue;
// 结构体定义 - 链队结点（单链表）
typedef struct QNode {
    int data;
    struct QNode *next;
}QNode;
// 结构体定义 - 链队结构体
typedef struct {
    struct QNode *front;
    struct QNode *rear;
}LiQueue;

// ============================================================ 顺序栈 ===============================================================
// 初始化顺序栈
void initSqStack(SqStack &st) {
    st.top = -1;
}
// 进栈
int push(SqStack &st, int x) {
    if (st.top == maxSize-1)
        return 0;
    initSqStack(st);
    ++(st.top);
    st.data[st.top] = x;
        return 1;
}
// 出栈
int pop(SqStack &st, int &x) {
    if (st.top == -1)
        return 0;
    x = st.data[st.top];
    --(st.top);
    return 1;
}

// =========================================================== 链栈 ==================================================================
// 初始化链栈
void initLStack(LSNode *lst) {
    lst = (LSNode *)malloc(sizeof(LSNode));
    lst->next = NULL;
}
// 进栈
void pushLS(LSNode *lst, int x) {
    LSNode *p;
    p = (LSNode *)malloc(sizeof(LSNode));
    p->data = x;

    p->next = lst->next;
    lst->next = p;
}
// 出栈
int popLS(LSNode *lst, int &x) {
    LSNode *p;
    if (lst->next == NULL)
        return 0;
    p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
        return 1;
}
