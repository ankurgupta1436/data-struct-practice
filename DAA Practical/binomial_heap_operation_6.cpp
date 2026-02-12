#include<stdio.h>
#include<stdlib.h>

struct node {
    int n, degree;
    struct node* parent;
    struct node* child;
    struct node* sibling;
};

struct node *H = NULL, *Hr = NULL;

struct node* MAKE_bin_HEAP() {
    return NULL;
}

void bin_LINK(struct node* y, struct node* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree++;
}

struct node* CREATE_NODE(int k) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->n = k;
    p->degree = 0;
    p->parent = p->child = p->sibling = NULL;
    return p;
}

struct node* bin_HEAP_UNION(struct node* H1, struct node* H2);
struct node* bin_HEAP_MERGE(struct node* H1, struct node* H2);

struct node* bin_HEAP_INSERT(struct node* H, struct node* x) {
    struct node* H1 = x;
    return bin_HEAP_UNION(H, H1);
}

struct node* bin_HEAP_MERGE(struct node* H1, struct node* H2) {
    if (!H1) return H2;
    if (!H2) return H1;

    struct node* H = NULL;
    struct node** pos = &H;

    while (H1 && H2) {
        if (H1->degree <= H2->degree) {
            *pos = H1; H1 = H1->sibling;
        } else {
            *pos = H2; H2 = H2->sibling;
        }
        pos = &(*pos)->sibling;
    }
    *pos = H1 ? H1 : H2;
    return H;
}

struct node* bin_HEAP_UNION(struct node* H1, struct node* H2) {
    struct node* H = bin_HEAP_MERGE(H1, H2);
    if (!H) return NULL;

    struct node *prev=NULL,*x=H,*next=x->sibling;

    while(next){
        if(x->degree!=next->degree ||
          (next->sibling && next->sibling->degree==x->degree)){
            prev=x; x=next;
        }else{
            if(x->n<=next->n){
                x->sibling=next->sibling;
                bin_LINK(next,x);
            }else{
                if(!prev) H=next;
                else prev->sibling=next;
                bin_LINK(x,next);
                x=next;
            }
        }
        next=x->sibling;
    }
    return H;
}

int DISPLAY(struct node* H){
    if(!H){
        printf("\nHEAP EMPTY\n");
        return 0;
    }
    printf("\nROOT NODES:\n");
    while(H){
        printf("%d ",H->n);
        H=H->sibling;
    }
    printf("\n");
    return 0;
}

struct node* bin_HEAP_EXTRACT_MIN(struct node* H1){
    if(!H1){
        printf("\nNothing to extract\n");
        return NULL;
    }

    struct node *minNode=H1,*prevMin=NULL,*p=H1;
    int min=H1->n;

    while(p->sibling){
        if(p->sibling->n<min){
            min=p->sibling->n;
            prevMin=p;
            minNode=p->sibling;
        }
        p=p->sibling;
    }

    if(prevMin) prevMin->sibling=minNode->sibling;
    else H1=minNode->sibling;

    H=H1;
    return minNode;
}

struct node* FIND_NODE(struct node* H,int k){
    if(!H) return NULL;
    if(H->n==k) return H;

    struct node* p=FIND_NODE(H->child,k);
    if(p) return p;

    return FIND_NODE(H->sibling,k);
}

int bin_HEAP_DECREASE_KEY(struct node* H,int i,int k){
    struct node* p=FIND_NODE(H,i);
    if(!p){
        printf("\nKey not found");
        return 0;
    }

    if(k>p->n){
        printf("\nNew key greater!");
        return 0;
    }

    p->n=k;
    struct node* z=p->parent;

    while(z && p->n<z->n){
        int t=p->n;
        p->n=z->n;
        z->n=t;
        p=z; z=z->parent;
    }

    printf("\nKey decreased successfully\n");
    return 1;
}

int bin_HEAP_DELETE(struct node* H,int k){
    bin_HEAP_DECREASE_KEY(H,k,-9999);
    struct node* p=bin_HEAP_EXTRACT_MIN(H);
    if(p) printf("\nNode deleted\n");
    return 1;
}

int main(){
    int n,m,l,i;
    char ch;
    struct node* p;

    printf("Enter number of elements:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&m);
        H=bin_HEAP_INSERT(H,CREATE_NODE(m));
    }

    DISPLAY(H);

    do{
        printf("\n1 Insert\n2 Extract Min\n3 Decrease Key\n4 Delete\n5 Exit\n");
        scanf("%d",&l);

        switch(l){
        case 1:
            printf("Enter value:");
            scanf("%d",&m);
            H=bin_HEAP_INSERT(H,CREATE_NODE(m));
            DISPLAY(H);
            break;

        case 2:
            p=bin_HEAP_EXTRACT_MIN(H);
            if(p) printf("Extracted=%d\n",p->n);
            DISPLAY(H);
            break;

        case 3:
            printf("Old key:");
            scanf("%d",&m);
            printf("New key:");
            scanf("%d",&i);
            bin_HEAP_DECREASE_KEY(H,m,i);
            DISPLAY(H);
            break;

        case 4:
            printf("Key delete:");
            scanf("%d",&m);
            bin_HEAP_DELETE(H,m);
            DISPLAY(H);
            break;

        }
    }while(l!=5);
}
