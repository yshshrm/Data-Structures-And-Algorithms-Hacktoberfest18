

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newnode, *temp;
    newnode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    temp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    temp->next = head;
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }    
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head; 
}

