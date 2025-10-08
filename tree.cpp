#include <stdio.h> 
#include <stdlib.h> 
// Structure for a tree node 
struct Node { 
int data; 
struct Node* left; 
struct Node* right; 
}; 
// Create a new node 
struct Node* createNode(int value) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = value; 
newNode->left = NULL; 
newNode->right = NULL; 
return newNode; 
} 
int main() { 
struct Node* root = NULL; 
int choice, value; 
while (1) { 
printf("\n--- Simple Tree Menu ---\n"); 
printf("1. Create Root\n"); 
printf("2. Add Left Child to Root\n"); 
printf("3. Add Right Child to Root\n"); 
printf("4. Display Tree\n"); 
printf("5. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
if (root == NULL) { 
printf("Enter value for root: "); 
scanf("%d", &value); 
root = createNode(value); 
printf("Root created with value %d\n", value); 
} else { 
printf("Root already exists!\n"); 
} 
break; 
case 2: 
if (root == NULL) { 
printf("Create root first!\n"); 
                } else if (root->left == NULL) { 
                    printf("Enter value for left child: "); 
                    scanf("%d", &value); 
                    root->left = createNode(value); 
                    printf("Left child added.\n"); 
                } else { 
                    printf("Left child already exists!\n"); 
                } 
                break; 
 
            case 3: 
                if (root == NULL) { 
                    printf("Create root first!\n"); 
                } else if (root->right == NULL) { 
                    printf("Enter value for right child: "); 
                    scanf("%d", &value); 
                    root->right = createNode(value); 
                    printf("Right child added.\n"); 
                } else { 
                    printf("Right child already exists!\n"); 
                } 
                break; 
 
            case 4: 
                if (root == NULL) { 
                    printf("Tree is empty!\n"); 
                } else { 
                    printf("\n Tree Structure:\n"); 
                    printf("   %d\n", root->data); 
                    if (root->left != NULL) 
                        printf("  / \n %d", root->left->data); 
                    else 
                        printf("  / \n NULL"); 
 
                    if (root->right != NULL) 
                        printf("    \\ \n     %d\n", root->right->data); 
                    else 
                        printf("    \\ \n     NULL\n"); 
                } 
                break; 
 
            case 5: 
                printf("Exiting...\n"); 
                exit(0); 
 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
 
return 0; 
}