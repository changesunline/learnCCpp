#include <iostream>
#define maxSize 100000

/**
 * ���� ��2��-���Ա�
 */

// �ṹ�嶨�� - ����
typedef struct {
    int data[maxSize];
    int length;
}Sqlist;
// �ṹ�嶨�� - ��������
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode;
// �ṹ�嶨�� - ˫������
typedef struct DLNode {
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;

// =============================================================== ��������� ======================================================================
// β�巨�ϲ�����������
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
// ͷ�巨�ϲ�����������
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

// β�巨����������
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
// ͷ�巨����������
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

// ɾ�����
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

// =============================================================== ˫������� =======================================================================
// β�巨����˫����
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
        r = s; // rָ��ָ������β��
    }
    r->next = NULL;
}

// ���ҽ��
DLNode *findDLNode(DLNode *C, int x) {
    DLNode *p = C->next;
    while (p != NULL) {
        if (p->data == x) break;
        p = p->next;
    }
    return p;
}

// ������
void insertDLNode(DLNode *p, DLNode *s) {
    s->next = p->next;
    p->next = s;
    s->prior = p;
    s->next->prior = s;
}

// =============================================================== ���Ա�Ԫ������ ====================================================================
void reverse(int a[], int left, int right, int k) {
    int temp;
    // ����leftΪ����a�����λ�ã�rightΪa���Ҷ�λ��
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
 * ���� ��3��-ջ�Ͷ���
 */

// �ṹ�嶨�� - ˳��ջ�����飩
typedef struct {
    int data[maxSize];
    int top;
}SqStack;
// �ṹ�嶨�� - ��ջ��㣨������
typedef struct LSNode {
    int data;
    struct LSNode *next;
}LSNode;
// �ṹ�嶨�� - ˳����У����飩
typedef struct {
    int data[maxSize];
    int front; //����
    int rear; //��β
}SqQueue;
// �ṹ�嶨�� - ���ӽ�㣨������
typedef struct QNode {
    int data;
    struct QNode *next;
}QNode;
// �ṹ�嶨�� - ���ӽṹ��
typedef struct {
    struct QNode *front;
    struct QNode *rear;
}LiQueue;

// ============================================================ ˳��ջ ===============================================================
// ��ʼ��˳��ջ
void initSqStack(SqStack &st) {
    st.top = -1;
}
// ��ջ
int push(SqStack &st, int x) {
    if (st.top == maxSize-1)
        return 0;
    initSqStack(st);
    ++(st.top);
    st.data[st.top] = x;
        return 1;
}
// ��ջ
int pop(SqStack &st, int &x) {
    if (st.top == -1)
        return 0;
    x = st.data[st.top];
    --(st.top);
    return 1;
}

// =========================================================== ��ջ ==================================================================
// ��ʼ����ջ
void initLStack(LSNode *lst) {
    lst = (LSNode *)malloc(sizeof(LSNode));
    lst->next = NULL;
}
// ��ջ
void pushLS(LSNode *lst, int x) {
    LSNode *p;
    p = (LSNode *)malloc(sizeof(LSNode));
    p->data = x;

    p->next = lst->next;
    lst->next = p;
}
// ��ջ
int popLS(LSNode *lst, int &x) {
    LSNode *p;
    if (lst->next == NULL)
        return 0;
    p = lst->next;
    x = p->data;=
    lst->next = p->next;
    free(p);
        return 1;
}

// ============================================================ ջ��Ӧ�ã��ǳ����ʵ��㷨�� =============================================================
// 1��˳��ջ - �ж�һ���ַ����������Ƿ�ɶ�ƥ��
int expMatch(char exp[], int n) {
    // ��ʼ��һ��˳��ջ
    char stack[maxSize];
    int top = -1;
    // ��¼���ֵ�����
    int i;
    for (i=0; i<n; ++i) {
        if (exp[i] == '(') {stack[++top] = exp[i];}
        if (exp[i] == ')') {
            if (top == -1)
                return 0;
            else
                --top;
        }
    }
    // ջ��˵�����Ŷ��ɶԳ��֣������෴
    if (top == -1)
        return 1;
    else
        return 0;
}
// 2��˳��ջ - ��׺ʽ�ļ���
int expOp(int a, char op, int b) { //���㺯��
    if (op == '+') return a+b;
    if (op == '-') return a-b;
    if (op == '*') return a*b;
    if (op == '/') {
        if (b == 0) {
            cout << "ERROR" << endl;
            return 0;
        } else {
            return a/b;
        }
    }
}
int expComput(char exp[]) { //���㺯��
    int i, a, b, c; //a��b��¼�������֣�c��¼���
    char op; //��¼�����
    int stack[maxSize]; int top = -1; //��ʼ��һ��ջ
    for (i=0; exp[i]!='\0'; ++i) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            stack[++top] = exp[i] - '0';
        } else {
            op = exp[i];
            a = stack[top--];
            b = stack[top--];
            c = expOp(a,op,b);
            stack[++top] = c;
        }
    }
    return stack[top];
}
// 3����ջ - ����ͷ���ĵ���������ջ
void initNHStack(LSNode *&lst) { //��ʼ����ջ
    lst = NULL;
}
int isEmptyNHStack(LSNode *lst) { //�ж���ջ�Ƿ�Ϊ��
    if (lst == NULL) {
        return 1;
    } else {
        return 0;
    }
}
void pushNHStack(LSNode *&lst, int x) {
    LSNode *p;
    p->next = NULL;
    p = (LSNode *)malloc(sizeof(LSNode));
    p->data = x;
    p->next = lst;
    lst = p;
}