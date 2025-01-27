#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right,*parent;
};
struct Node* search(struct Node *root,int val)
{
    
    struct Node *ptr=root;
    while(ptr != NULL)
    {
        if(ptr->data <val)
        {
            if(ptr->data==val || ptr==NULL)
            {
                return ptr;
            }
            else
            {
                ptr=ptr->right;
            }
        }
        else
        {
           if(ptr->data==val || ptr==NULL)
            {
                return ptr;
            }
            else
            {
                ptr=ptr->left;
            }
        }
    }

}

struct Node* root=NULL;
void insert(int key){
    struct Node*t=root;
    struct Node*r,*p;
    if(root==NULL){
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->left=p->right=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data){
            t=t->left;
        }
        else if (key>t->data)
        {
            t=t->right;
        }
        else
        return;
        
    }
    p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->left=p->right=NULL;
        

        if(key<r->data) r->left=p;
        else r->right=p;
}


// struct Node* insertBST(struct Node*root, int val){
//     if(root == NULL){
//         root->data=val;
//     }
//     if (val<root->data){
//         root->left = insertBST(root->left,val);
//     }
//     else{
//         root->right = insertBST(root->right,val);
//     }
//     return root;

// }
void inorder(struct Node * root){
    if(root == NULL){
        return;
    }
    
        inorder(root->left);
        printf("%d🫡  ",root->data);
        inorder(root->right);
    
}
struct Node* min(struct Node* root)
{
    struct Node* ptr2;
    ptr2=root;
    while(ptr2->left != NULL)
    {
        ptr2=ptr2->left;
    }
    return ptr2;
}
struct Node* max(struct Node* root)
{
    struct Node* ptr2;
    ptr2=root;
    while(ptr2->right != NULL)
    {
        ptr2=ptr2->right;
    }
    return ptr2;
}
struct Node* successor(struct Node *root)
{
    printf("\nenter the value whose successor has to be find:");
    int num;
    scanf("%d",&num);
    struct Node* find,*pa;
    find=search(root,num);
    if(find->right != NULL)
    {
        return min(find->right);
    }
    pa=find->parent;
    while(pa != NULL && find==pa->right)
    {
        find=pa;
        pa=pa->parent;
    }
    return pa;
}
struct Node* predecessor(struct Node* root)
{
    printf("\nenter the value whose predecessor has to be found:");
    int x;
    scanf("%d",&x);
    struct Node* find,*pa;
    find=search(root,x);
    if(find->left != NULL)
    {
        return max(find->left);
    }
    pa=find->parent;
    while(pa!= NULL && pa->left==find)
    {
        find=pa;
        pa=pa->parent;
    }
    return pa;
}
int Height( struct Node *p) {
    int x;
    int y;
    if (p == NULL){
        return 0;
    }
    x = Height(p->left);
    y = Height(p->right);
    return x > y ? x + 1 : y + 1;
}
struct Node*Delete(struct Node *p, int key) {
    struct Node* q;
 
    if (p == NULL){
        return NULL;
    }
 
    if (p->left == NULL && p->right== NULL){
       p = NULL;
        free(p);
        return NULL;
    }
 
    if (key < p->data){
        p->left = Delete(p->left, key);
    } else if (key > p->data){
        p->right= Delete(p->right, key);
    } else {
        if (Height(p->left) > Height(p->right)){
            q = predecessor(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        } else {
            q = successor(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }
    return p;
}
 



int main(){
    int n;
    int size;
    printf("Enter the number of values you wanna add:");
    scanf("%d",&size);
    printf("Enter the numbers to be instered:");
    for(int i=0;i<size;i++){
    
    scanf("%d",&n);
    insert(n);
    }
    
    inorder(root);
    root = min(root);
    printf("%d",root->data);
    
}