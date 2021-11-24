#include <stdio.h>
#include <stdlib.h>

int C=0, a=0;
int ans[300000];

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *new_node(int item){
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data=item;
    node->left = NULL;
    node->right=NULL;
    return node;
}

TreeNode *insert(int data, TreeNode *node){
    C++;
    
    if(node==NULL){
        C--;
        ans[a++]=C;
        return new_node(data);
        
    }
    if(data < (node->data)){
        node->left=insert(data,node->left);
        
    }
    else{
        node->right=insert(data,node->right);
        
    }
    return node;
}

int main(void){
    int N;
    int root_num, num;
    TreeNode *root = NULL;
    scanf("%d",&N);
    


    for(int i=0; i<N; i++){
        scanf("%d",&num);
        root = insert(num, root);
    }
    for(int i=0; i<N; i++){
        printf("%d\n",ans[i]);
    }
}