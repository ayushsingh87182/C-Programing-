#include<stdio.h> 
#include<stdlib.h> 
struct treeNode
{
int data;
struct treeNode *left;
struct treeNode *right;
};
struct treeNode* insert(struct treeNode *root, int data)
{
if (root == NULL)
{
struct treeNode *temp;
temp = (struct treeNode*) malloc (sizeof(struct treeNode));
temp->data = data;
temp->left = temp->right = NULL;
return temp;
}
if (data<(root->data))
root->left = insert(root->left, data);
else if (data>root->data)
root ->right = insert(root->right, data);
return root;
}
void inorder(struct treeNode *root)
{
if(root == NULL)
return;
inorder(root->left); 
printf("%d\t", root->data); 
inorder(root->right);
}
void preorder(struct treeNode *root)
{
if(root == NULL)
return;
printf("%d\t", root->data); 
preorder(root->left); 
preorder(root->right);
}
void postorder(struct treeNode *root)
{
if(root == NULL)
return;
postorder(root->left);
postorder(root->right); 
printf("%d\t", root->data);
}
void search(struct treeNode *root, int data)
{
if(root == NULL)
printf("\nElement not found"); 
else if(data<root->data)
search(root->left, data);
else if(data>root->data)
search(root->right, data);
else
printf("\nElement found is: %d", root->data);
}
int main()
{
int data, ch, i, n;
struct treeNode *root = NULL; 
while (1)
{
printf("\n1.Creation of Binary Search Tree");
printf("\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit"); 
printf("\nEnter your choice: ");
scanf("%d",&ch); 
switch (ch)
{
case 1: int a[]={6,9,5,2,8,15,24,14,7,8,5,2}; 
        int n=sizeof(a)/sizeof(a[0]);
        for(i=0; i<n; i++)
        {
        root = insert(root, a[i]);
        }
        break;
case 2: printf("\nInorder Traversal: \n");
        inorder(root);
        break;
case 3: printf("\nPreorder Traversal: \n");
        preorder(root);
        break;
case 4: printf("\nPostorder Traversal: \n");
        postorder(root);
        break;
case 5: printf("\nEnter the element to Search: "); 
        scanf("%d",&data);
        search(root, data); 
        break;
case 6: exit(0);
default: printf("\nWrong Option");
            break;
}
}
return 0;
}