#include<stdio.h>
#include<conio.h>
#define DMA (struct BST*)malloc(sizeof(struct BST))
struct BST *insert_bst(struct BST *root,int data);
void preorder(struct BST *root); /* Function Prototype */
void inorder(struct BST *root);  /* Function Prototype */
void postorder(struct BST *root);/* Function Prototype */
void height_of_tree(struct BST *root);/* Function Prototype */
struct BST
{
   int data;
   struct BST *left;
   struct BST *right;
};
void main()  /* Main function definition  */
{
    int data,ch;
    struct BST *root;
    root=NULL;
	while(1)
	{
	  clrscr();
	  printf("Menu of Binary Search Tree\n");
	  printf("1.Create Tree\n");
	  printf("2.Inorder\n");
	  printf("3.postorder\n");
	  printf("4.preorder\n");
	  printf("5.Height of tree\n");
	  printf("0.Quit\n");
	  printf("Enter your choice=");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	    case 1:
		printf("Enter data=");
		scanf("%d",&data);
		root=insert_bst(root,data);break;
	    case 2:
		inorder(root);break;
	    case 3:
		postorder(root);break;
	    case 4:
		preorder(root);break;
	   case 5:
	      height_of_tree(root);break;
	    case 0:
		exit(0);
	  }
	}
}
/* Insert_Binary_Search_Tree  */
struct BST *insert_bst(struct BST *root,int data)
{
    struct BST *newnode,*prevnode,*temp;
       newnode=DMA;
       newnode->data=data;
       newnode->left=NULL;
       newnode->right=NULL;
       if(root==NULL)
	 root=newnode;
       else
       {
	   temp=root;
	   while(temp)
	   {
	      if(data<=temp->data)
	      {
		  prevnode=temp;
		  temp=temp->left;
	      }
	      else
	      {
		prevnode=temp;
		temp=temp->right;
	      }
	   }
	   if(data<=prevnode->data)
	     prevnode->left=newnode;
	   else
	      prevnode->right=newnode;
       }
return root;
}
/* Inoder */
void inorder(struct BST *root)
{
   if(root==NULL)
   return;
   else
   {
     inorder(root->left);
     printf("%3d",root->data);
     inorder(root->right);
     }
     sleep(2);
}
/* preorder  */
void preorder(struct BST *root)
{
  if(root==NULL)
    return;
  else
  {
    printf("%3d",root->data);
    preorder(root->left);
    preorder(root->right);
  }
  sleep(2);

}
/* Postorder */
void postorder(struct BST *root)
{
  if(root==NULL)
  return;
  else
  {
    postorder(root->left);
    postorder(root->right);
    printf("%3d",root->data);
  }
  sleep(2);

}
/* Height_of_Tree */
void height_of_tree(struct BST *root)
{
   struct BST *temp1,*temp2,*temp;
   int h1,h2,h3;
   h1=h2=h3=0;
   temp=root;
   if(root==NULL)
   printf("tree Empty");
   else if(root->left==NULL && root->right==NULL)
   printf("Height of tree=1");
   else
   {     temp1=temp->left;
      while(temp1)
      {
	if(temp1->left)
	{
	h1++;
	 temp1=temp1->left;
	}
	else
	{
	 h1++;
	 temp1=temp1->right;
	}
      }
      temp2=temp->right;
      while(temp2)
      {
	if(temp2->left)
	{
	 h2++;
	 temp2=temp2->left;
	}
	else
	{
	  h2++;
	  temp2=temp2->right;
	}
      }
      if(h1>h2)
	h3=h1;
      else
	h3=h2;
   printf("\nHeight of left tree=%d",h1);
   printf("\nHeight of right tree=%d",h2);
   printf("\nMaximum hight of tree=%d",h3);
   }
   getch();
}

