#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;

	struct node *left;
	struct node *right;
};

typedef struct node Node;

Node* createNode(int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	newNode->left  = NULL;
	newNode->right = NULL;

	return newNode;
}

void preorder(Node *root)
{
	if(root == NULL)
		return;	

	printf("%d ",root->data);
	
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	
	printf("%d ",root->data);
	
	inorder(root->right);
}

void postorder(Node *root)
{
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);

	printf("%d ",root->data);
}

int main()
{
	/*create a tree		1
			       / \
			      2   3
			     /	   \
			    4	    5
	*/

	Node *root = createNode(1);
	printf("%d\n",root->data);

	root->left = createNode(2);
	printf("%d\n",root->left->data);

	root->right = createNode(3);
	printf("%d\n",root->right->data);

	root->left->left = createNode(4);
	printf("%d\n",root->left->left->data);

	root->right->right = createNode(5);
	printf("%d\n",root->right->right->data);

	printf("\nPreorder Traversal : ");
	preorder(root);


	printf("\nInorder Traversal : ");
	inorder(root);

	printf("\nPostorder Traversal : ");
	postorder(root);

	return 0;
}
