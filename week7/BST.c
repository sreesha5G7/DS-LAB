#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int key;
	struct Node *left,*right;
};
struct Node* newNode(int item)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(struct Node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d",root->key);
		inorder(root->right);
	}
}
struct Node* insert(struct Node* node,int key)
{
	if(node == NULL)
	{
	   return newNode(key);
    }
	if(key < node->key)
	{
		node->left = insert(node->left,key);
	}
	else if(key > node->key)
	{
		node->right = insert(node->right,key);
	}
	return node;
}
struct Node* search(struct Node* root,int key)
{
	if(root == NULL || root->key == key)
	    return root;
	if(key < root->key)
	    return search(root->left,key);
	else
	    return search(root->right,key);
}
struct Node* minValueNode(struct Node* node)
{
	struct Node* current = node;
	while(current && current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
struct Node* deleteNode(struct Node* root,int key)
{
	if(root == NULL)
	   return root;
	if(key < root->key)
	{
		root->left = deleteNode(root->left,key);
	}
	else if (key > root->key)
	{
		root->right = deleteNode(root->right,key);
	}
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left == NULL)
		{
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		struct Node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right,temp->key);
	}
	return root;
}
int main()
{
	struct Node* root = NULL;
	int option,val;
	do
	{
		printf("\n****MAIN MENU****");
		printf("\n1.INORDER");
		printf("\n2.INSERT");
		printf("\n3.SEARCH");
		printf("\n4.MINIMUM VALUE");
		printf("\n5.DELETE");
		printf("\n6.EXIT");
		printf("\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				inorder(root);
				break;

			case 2:
				printf("Enter value to insert: ");
				scanf("%d", &val);
				root = insert(root, val);
				printf("%d inserted\n", val);
				break;

			case 3:
				printf("Enter value to search: ");
				scanf("%d", &val);
				if (search(root, val))
					printf("%d found in the tree\n", val);
				else
					printf("%d not found in the tree\n", val);
				break;

			case 4:
				if (root == NULL)
					printf("Tree is empty\n");
				else {
					struct Node* newNode = minValueNode(root);
					printf("Minimum value in BST is %d\n", newNode->key);
				}
				break;

			case 5:
				printf("Enter value to delete: ");
				scanf("%d", &val);
				root = deleteNode(root, val);
				printf("%d deleted if it existed\n", val);
				break;

		}
	}
	while(option!=6);
	return 0;
}


























































