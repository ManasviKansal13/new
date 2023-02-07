//left and right view
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h> 
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *Next;
};
struct node *Front,*Rear;
struct node* MakeNode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->Next=NULL;
    return p;
} 
void Intialize(){
    Rear=NULL;
    Front=NULL;
}
void EnQueue(struct node *p){
    if(Rear!=NULL)
        Rear->Next=p;
    else
        Front=p;
    Rear=p;
}
struct node *DeQueue(){
    struct node *p;
    p=Front;
    Front=Front->Next;
    if(Front==NULL)
        Rear=NULL;
    return p;
}
int IsEmpty(){
    if(Front==NULL)
        return 1;
    else
        return 0;
}
void InsHT(int HT[10][10],struct node *x){
    int R=x->Next;
    int C=0;
    while(HT[10][10]!=0)
        C++;
    HT[10][10]=x->data;
}
int Max(int a,int b){
    if(a>=b)
        return a;
    else    
        return b;
}
int Height(struct node *t){
    if(t==NULL)
        return 0;
    else{
        if(t->left==NULL && t->right==NULL)
            return 0;
        else
            return Max(Height(t->left),Height(t->right))+1;
    }
}
void CreateTree(struct node **t){
    int choice,x;
    struct node *p;
    printf("Whether the left of %d exists?(0/1)",(*t)->data);
    scanf("%d",&choice);
    if(choice==1){
        printf("Input the data of left of %d ",(*t)->data);
        scanf("%d",&x);
        p=MakeNode(x);
        (*t)->left=p;
        CreateTree(&p);
    }
    printf("Whether the right of %d exists?(0/1)",(*t)->data);
    scanf("%d",&choice);
    if(choice==1){
        printf("Input the data of right of %d ",(*t)->data);
        scanf("%d",&x);
        p=MakeNode(x);
        (*t)->right=p;
        CreateTree(&p);
    }
}
void PreOrderTraversal(struct node *t){
    if(t!=NULL){
        printf("%d ",t->data);
        PreOrderTraversal(t->left);
        PreOrderTraversal(t->right);
    }
}
void InOrderTraversal(struct node *t){
    if(t!=NULL){
        InOrderTraversal(t->left);
        printf("%d ",t->data);
        InOrderTraversal(t->right);
    }
}
void PostOrderTraversal(struct node *t){
    if(t!=NULL){
        PostOrderTraversal(t->left);
        PostOrderTraversal(t->right);
        printf("%d ",t->data);
    }
}
int LeftViewTraversal(struct node *T)
{
    Intialize();
    int HT[10][10];
    int R=0;
    T->Next=0;
    EnQueue(T);
    InsHT(HT[10][10],T);
    struct node *x;
    while(!IsEmpty()){
        x=DeQueue();
        //printf("%d\t",x->data);
        if(x->left!=NULL){
            x->left->Next=x->Next+1;
            if(R<x->left->Next){
                R=x->left->Next;
                EnQueue(x->left);
                InsHT(HT[10][10],x->left);
            }
        }
        if(x->right!=NULL){
            x->right->Next=x->Next+1;
            if(R<x->right->Next){
                R=x->right->Next;
                EnQueue(x->right);
                InsHT(HT[10][10],x->right);
            }
        }
        printf("%d",x->data);
    }
    printf("LEFT ORDER TRAVERSAL>>> ");
    for(int i=0;i<R;i++)
        printf("%d\t",HT[i][0]);
    printf("RIGHT ORDER TRAVERSAL>>> ");
    for(int i=0;i<R;i++){
        int j=0;
        while(HT[i][j]!=0)
            j++;
        printf("%d\t",HT[i][j-1]);
    }
}
int main(){
    struct node *root=NULL;
    int x;
    printf("Enter the data of  root node: ");
    scanf("%d",&x);
    root=MakeNode(x);
    CreateTree(&root);
    printf("\n Pre order...-> ");
    PreOrderTraversal(root);
    printf("\n In order...-> ");
    InOrderTraversal(root);
    printf("\n Post order...-> ");
    PostOrderTraversal(root);
    printf("\n Left View...-> ");
    LeftViewTraversal(root);
    return 0;
}