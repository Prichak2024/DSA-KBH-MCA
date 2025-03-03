//Write a Menu driven C program to accomplish the following functionalities in circular linked list.
//a) Create a circular linked list.
//b) Display the elements of a circular linked list.
//c) Insert a node at the beginning of a circular linked list.
//d) Insert a node at the end of a circular linked list.
//e) Delete a node from the beginning of a circular linked list.
//f) Delete a node from the end of a circular linked list.
//g) Delete a node after a given node of a circular linked list.
//h) Delete the entire circular linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a circular linked list
void createCircularList(int data) {
    struct Node* new_node = newNode(data);
    head = new_node;
    new_node->next = new_node;
}

// Function to display the circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    if (head == NULL) {
        createCircularList(data);
        return;
    }
    struct Node* new_node = newNode(data);
    new_node->next = head;
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = new_node;
    head = new_node;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    if (head == NULL) {
        createCircularList(data);
        return;
    }
    struct Node* new_node = newNode(data);
    new_node->next = head;
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    head = temp->next;
}

// Function to delete a node from the end
void deleteAtEnd() {
    if (head == NULL) {
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
}

// Function to delete a node after a given node
void deleteAfter(int x) {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    while (temp->next != head && temp->data != x) {
        temp = temp->next;
    }
    if (temp->next == head) {
        printf("Node not found\n");
        return;
    }
    struct Node* to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

// Function to delete the entire circular linked list
void deleteList() {
    if (head == NULL) {
        return;
    }
    struct Node* current = head;
    while (current->next != head) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    free(current);
    head = NULL;
}

int main() {
    int choice, data, x;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete After\n");
        printf("8. Delete List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                createCircularList(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter node after which to delete: ");
                scanf("%d", &x);
                deleteAfter(x);
                break;
            case 8:
                deleteList();
                printf("List deleted\n");
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
