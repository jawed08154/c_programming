#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct tree 
{
	uint32_t data;
	struct tree *left;
	struct tree *right;
} NODE;

void create_bst(NODE **head, const uint32_t data)
{
	/*create node*/
	NODE *new_node = malloc(sizeof(NODE));
	if (!new_node)
	{
		printf("\nMemory allocation failed! \n");
		return;
	}

	new_node->data  = data;
	new_node->left  = NULL;
	new_node->right = NULL;

	/*Check for the empty BST */
	if (!*head)
	{
		*head = new_node;
		return;
	}

	/*Find the appropriate position to insert the node*/
	NODE *prev  = *head;
	NODE *curr  = *head;

	while (curr != NULL)
	{
		prev = curr;
		if (curr->data > data)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}
	}

	/*Insert the node using prev node*/
	if (prev->data > data)
	{
		prev->left = new_node;
	}
	else
	{
		prev->right = new_node;
	}
}

void inorder_display_bst(NODE *head)
{
		if (head != NULL) 
		{ 
				inorder_display_bst(head->left); 
				printf("%d \n", head->data); 
				inorder_display_bst(head->right); 
		} 
}

void preorder_display_bst(NODE *head)
{
		if (head != NULL) 
		{ 
				printf("%d \n", head->data); 
				preorder_display_bst(head->left); 
				preorder_display_bst(head->right); 
		} 
}

void postorder_display_bst(NODE *head)
{
		if (head != NULL) 
		{ 
				postorder_display_bst(head->left); 
				postorder_display_bst(head->right); 
				printf("%d \n", head->data); 
		} 
}



int main (int args, char *argv[])
{
	uint32_t num     = 0;
	uint32_t data    = 0;

	NODE *head = NULL;

	printf("\nEnter Number of Elements = ");
	scanf("%d", &num);

	printf("\nEnter Elements = ");
	for (uint32_t i = 0; i < num; i++)
	{
		scanf("%d",&data);
		create_bst(&head, data);
	}	 

	printf("\nDisplay BST Inorder\n");
	inorder_display_bst(head);

	printf("\nDisplay BST preorder\n");
	preorder_display_bst(head);

	printf("\nDisplay BST postorder\n");
	postorder_display_bst(head);

	return EXIT_SUCCESS;
}

