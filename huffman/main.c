#include <stdio.h>
#include <stdlib.h>
#define MAXN 100


struct Node {
    char c;
    float f;
    struct Node *left;
    struct Node *right;
};


typedef struct {
    struct Node node[MAXN];
    int size;
} Queue;


void insert(Queue *q, struct Node z) {
    q->node[q->size] = z;
    q->size++;
}


struct Node extractMin(Queue *q) {
    
    int minIdx = 0;
    
    for (int i = 1; i < q->size; ++i)
        if (q->node[i].f < q->node[minIdx].f) minIdx = i;
        
    struct Node minNode = q->node[minIdx];

    for (int i = minIdx; i < q->size - 1; ++i)
        q->node[i] = q->node[i + 1];
    
    q->size--;

    return minNode;
}


struct Node huffmanTree(char c[], float f[], int n) {

    Queue q;
    q.size = 0;
    
    for (int i = 0; i < n; ++i) {
        struct Node z;
        z.c = c[i];
        z.f = f[i];
        z.left = NULL;
        z.right = NULL;
        insert(&q, z);
    }

    while (q.size > 1) {
        struct Node *x = (struct Node *)malloc(sizeof(struct Node));
        struct Node *y = (struct Node *)malloc(sizeof(struct Node));

        *x = extractMin(&q);
        *y = extractMin(&q);

        struct Node *z = (struct Node *)malloc(sizeof(struct Node));
        z->f = x->f + y->f;
        z->left = x;
        z->right = y;

        insert(&q, *z);
    }

    return extractMin(&q);
}


int isLeaf(struct Node *node) { return node->left == NULL && node->right == NULL; }


void print(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d", a[i]);
    printf("\n");
}


void printFloatArray(float *a, int n) {
    printf("[%.2f", a[0]);
    for (int i = 1; i < n; i++) printf(", %.2f", a[i]);
    printf("]\n");
}


void printCharArray(char *a, int n) {
    printf("[%c", a[0]);
    for (int i = 1; i < n; i++) printf(", %c", a[i]);
    printf("]\n");
}


void printBits(struct Node *root, int *a, int i) {

    if (root->left != NULL) {
        a[i] = 0;
        printBits(root->left, a, i + 1);
    }

    if (root->right != NULL) {
        a[i] = 1;
        printBits(root->right, a, i + 1);
    }

    if (isLeaf(root)) {
        printf("- %c: ", root->c);
        print(a, i);
    }
}


int main() {

    char c[4] = {'A', 'C', 'G', 'T'};
    float f[4] = {0.45, 0.05, 0.05, 0.45};
    int n = 4;

    printf("Characters: ");
    printCharArray(c, n);
    printf("Frequencies: ");
    printFloatArray(f, n);

    struct Node root = huffmanTree(c, f, n);
    int *a = (int *) malloc(n * sizeof(int));
    printBits(&root, a, 0);

    return 0;
}
