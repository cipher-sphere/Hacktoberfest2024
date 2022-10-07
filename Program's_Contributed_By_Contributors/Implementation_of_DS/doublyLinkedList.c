#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} ;

void insertHead(struct Node** head, int new_data);
void insertAfter(struct Node* prevNode, int new_data);
void insertEnd(struct Node** head, int newData);
void printList(struct Node* temp);
void deleteEnd(struct Node** head);
void deleteHead(struct Node** head);
void deleteUser(struct Node** head, int position);


int main()
{
    /*Let us create a DLL with three nodes*/
    /*We first initialize the nodes */
    struct Node *head;
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    /*We now allocate memory to the nodes*/
    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    
    /*Assigning values and connecting the nodes*/

    /*First node with data as 5 and connection*/
    first->data = 5;
    first->next = second;
    first->prev = NULL;

    /*Second node with data as 9 and connection*/
    second->data = 9;
    second->next = third;
    second->prev = first;

    /*Third node with data as 6 and connection*/
    third->data = 6;
    third->next = NULL;
    third->prev = second;
    
    /*save address of first node as head*/
    head = first;

    printf("The initial list is : ");
    printList(head);

    printf("\nInserting 7 at the head :");
    insertHead(&head, 7);
    printList(head);

    printf("\nInserting 8 after a node :");
    insertAfter(head->next, 8);
    printList(head);

    printf("\nDeleting at position 3");
    deleteUser(&head, 3);
    printf(" and the list becomes :");
    printList(head);

    printf("\nInserting 3 at end :");
    insertEnd(&head, 3);
    printList(head);

    printf("\nDeleting head node becomes : ");
    deleteHead(&head);
    printList(head);

    printf("\nDeleting last node becomes : ");
    deleteEnd(&head);
    printList(head);

    return 0;
}

void insertHead(struct Node** head, int new_data)
{
    //allocating a new node
    struct Node* newNode = malloc(sizeof(struct Node));

    //assigning data to new node
    newNode->data = new_data;

    //make previous as NULL
    newNode->prev = NULL;

    //make next point to head node
    newNode->next = (*head);

    //make previous of head node to new node
    if ((*head) != NULL)
        (*head)->prev = newNode;

    //make head to be new node
    (*head) = newNode; 
}

/*Inserting a node after given node*/
void insertAfter(struct Node* prevNode, int new_data)
{
    //allocating memory to new node
    struct Node* newNode = malloc(sizeof(struct Node));

    //allocate data to new node
    newNode->data = new_data;

    //make newNode.prev equal to prevNode.prev
    newNode->next = prevNode->next;

    //make prevNode.next equal newNode
    prevNode->next = newNode;

    //make newNode.prev equal prevNode
    newNode->prev = prevNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

/*Insrting node at end*/
void insertEnd(struct Node** head, int newData)
{
    //allocate memory of node
    struct Node* newNode = malloc(sizeof(struct Node));

    //assign data to new node
    newNode->data = newData;

    //assign NULL to next of newNode
    newNode->next = NULL;

    //store head node temporarily
    struct Node* temp = *head;

    //if LL empty make newNode head and return
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;   
    }
    //traverse LL to last node
    while (temp->next != NULL)
        temp = temp->next;

    //make temp.next equal newNode
    temp->next = newNode;
    //prev will be temp
    newNode->prev = temp;
}

void printList(struct Node* temp)
{
    while(temp != NULL)
    {
        //print temp data
        printf(" %d ", temp->data);
        //make temp point to next data
        temp = temp->next;
    }
}

void deleteEnd(struct Node** head)
{
    //if head has one node
    if ((*head)->next == NULL)
        {
            //free the memory
            free(head);
            head = NULL;
        }
    //struct variable called temp
    struct Node* temp = *head, *prev_node;

    //traverse through DLL
    while(temp->next != NULL)
    {
        prev_node = temp;
        temp = temp->next;
    }
    //free memory of last node
    free(temp);
    //make previous nod.Next equal to NULL
    prev_node->next = NULL;
}

void deleteHead(struct Node** head)
{
    //create a temp variable to store head
    struct Node* temp;

    if (*head == NULL)
    {
        printf(" Cannot delete from an empty list ");
        return;
    }
    else
    {
        temp = *head;

        //update head value to next value in LL
        *head = (*head)->next;

        //head.Prev will equal NULL
        (*head)->prev = NULL;

        //free memory
        free(temp);
    }
    
}

void deleteUser(struct Node** head, int position)
{
    struct Node* temp = *head;
    
    while (position > 1)
    {
        temp = temp->next;
        position--;
    }
    //this line will make the the next of previous node point to the next node
    temp->prev->next = temp->next;

    //this line makes the previous of next node to be deleted point to prev node
    temp->next->prev = temp->prev;

    //free unused memory
    free(temp);
}