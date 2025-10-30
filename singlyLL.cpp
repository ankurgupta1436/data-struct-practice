 #include <stdio.h> 
#include <stdlib.h> 
 
// Structure of a Node 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
// Head pointer 
struct Node* head = NULL; 
 
// Function to insert at beginning 
void insertAtBeginning(int value) { 
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); 
    newnode->data = value; 
    newnode->next = head; 
    head = newnode; 
    printf("Inserted %d at beginning\n", value); 
} 
 
// Function to insert at end 
void insertAtEnd(int value) { 
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); 
    newnode->data = value; 
    newnode->next = NULL; 
 
    if (head == NULL) { 
        head = newnode; 
    } else { 
        struct Node* temp = head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = newnode; 
    } 
    printf("Inserted %d at end\n", value); 
} 
 
// Function to delete a node by value 
void deleteNode(int value) { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct Node* temp = head; 
    struct Node* prev = NULL; 
 
    // If head node itself holds the value 
    if (temp != NULL && temp->data == value) { 
        head = temp->next; 
        free(temp); 
        printf("Deleted %d from list\n", value); 
        return; 
    } 
 
    // Search for the node 
    while (temp != NULL && temp->data != value) { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    if (temp == NULL) { 
        printf("Value %d not found in list\n", value); 
        return; 
    } 
 
    prev->next = temp->next; 
    free(temp); 
    printf("Deleted %d from list\n", value); 
} 
 
// Function to display list 
void displayList() { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct Node* temp = head; 
    printf("Linked List: "); 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
// Main function with menu 
int main() { 
    int choice, value; 
 
    while (1) { 
        printf("\n--- Singly Linked List Menu ---\n"); 
        printf("1. Insert at Beginning\n"); 
        printf("2. Insert at End\n"); 
        printf("3. Delete a Node\n"); 
        printf("4. Display List\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                insertAtBeginning(value); 
                break; 
 
            case 2: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                insertAtEnd(value); 
                break; 
 
            case 3: 
                printf("Enter value to delete: "); 
                scanf("%d", &value); 
                deleteNode(value); 
                break; 
 
            case 4: 
                displayList(); 
                break; 
 
            case 5: 
                printf("Exiting program.\n"); 
                exit(0); 
 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } 
 
    return 0; 
} 