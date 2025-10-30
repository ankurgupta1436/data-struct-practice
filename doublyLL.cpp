#include <stdio.h> 
#include <stdlib.h> 
 
// Structure of Doubly Linked List Node 
struct Node { 
    int data; 
    struct Node* prev; 
    struct Node* next; 
}; 
 
struct Node* head = NULL;
 
// Function to insert at beginning 
void insertBeginning(int value){
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode-> data = value;
    newNode-> prev = NULL;
    newNode-> next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}
// Function to insert at end
void insertEnd(int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
    newNode->prev = NULL; 
 
    if (head == NULL) { 
        head = newNode; 
        return; 
    } 
 
    struct Node* temp = head; 
    while (temp->next != NULL) 
        temp = temp->next; 
 
    temp->next = newNode; 
    newNode->prev = temp; 
} 
 
// Function to delete by value 
void deleteNode(int value) { 
    if (head == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
 
    struct Node* temp = head; 
 
    // Search node 
    while (temp != NULL && temp->data != value) 
        temp = temp->next; 
 
    if (temp == NULL) { 
        printf("Node %d not found.\n", value); 
        return; 
    } 
 
    if (temp == head) { 
        head = head->next; 
        if (head != NULL) 
            head->prev = NULL; 
    } else { 
        if (temp->next != NULL) 
            temp->next->prev = temp->prev; 
        if (temp->prev != NULL) 
            temp->prev->next = temp->next; 
    } 
 
    free(temp); 
    printf("Node %d deleted.\n", value); 
} 
 
// Function to display list 
void display() { 
    if (head == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
    struct Node* temp = head; 
    printf("Doubly Linked List: "); 
    while (temp != NULL) { 
        printf("%d <-> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
// Main function 
int main() { 
    int choice, value; 
    while (1) { 
        printf("\n--- Doubly Linked List Menu ---\n"); 
        printf("1. Insert at Beginning \n2. Insert at End \n3. Delete\n4. Display\n5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert at beggining: "); 
                scanf("%d", &value); 
                insertBeginning(value); 
                break; 
            case 2: 
                printf("Enter value to insert at end: "); 
                scanf("%d", &value); 
                insertEnd(value); 
                break; 
            case 3: 
                printf("Enter value to delete: "); 
                scanf("%d", &value); 
                deleteNode(value); 
                break; 
            case 4: 
                display(); 
                break; 
            case 5: 
                exit(0); 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
    return 0; 
} 
 
