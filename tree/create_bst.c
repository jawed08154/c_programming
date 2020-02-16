#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node *insert_node(struct node *, int);
struct node *create_node(int);
int search(struct node *, int);
void inorder(struct node *);

struct node * create_node(int data)
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
	return root;
}

struct node * insert_node(struct node *root, int data)
{
	if (root == NULL) 
		root = create_node(data);
	else if(data <= root-> data)
	     root -> lchild = insert_node(root -> lchild, data);
	else
		root -> rchild = insert_node(root -> rchild, data);
return root;		
}

int search(struct node * root, int data)
{
	if (root == NULL)
		return 0;
	else if(root-> data == data) 
		return 1;
	else if(data <= root-> data)
	  return search(root->lchild, data);
	else
	 return search(root ->rchild, data);
}

void inorder(struct node *root)
{
	if (root == NULL)
		return;
	inorder(root->lchild);
	printf("%d ", root->data);
	inorder(root->rchild);
}

int main()
{
	struct node * root = NULL;  //created an instance of root node

	int i,data, num, elem;
	printf("Enter the number of nodes you want to create\n");
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
	printf("Enter the number to insert in the tree\n");
	scanf("%d", &data);
	root = insert_node(root, data);
	}
	/*traversing the nodes in inorder manner*/
	inorder(root);
	printf("\n\nEnter the number to search in tree: ");
	scanf("%d", &elem);
	if (search(root, elem) == 1)
		printf("\nfound\n");
	else
	   printf("\nnotfound\n");
return 0;
}
