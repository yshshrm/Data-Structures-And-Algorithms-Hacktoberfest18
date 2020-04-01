using namespace std; 
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
void push(struct Node **head_ref, int new_data) 
{ 
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        cout << node->data << " "; 
        node = node->next; 
    } 
    cout << endl; 
} 
int countNodes(struct Node *s) 
{ 
    int count = 0; 
    while (s != NULL) 
    { 
        count++; 
        s = s->next; 
    } 
    return count; 
} 
void swapKth(struct Node **head_ref, int k) 
{ 
    // Count nodes in linked list 
    int n = countNodes(*head_ref);
    if (n < k)  return; 
    if (2*k - 1 == n) return; 
    Node *x = *head_ref; 
    Node *x_prev = NULL; 
    for (int i = 1; i < k; i++) 
    { 
        x_prev = x; 
        x = x->next; 
    }
    Node *y = *head_ref; 
    Node *y_prev = NULL; 
    for (int i = 1; i < n-k+1; i++) 
    { 
        y_prev = y; 
        y = y->next; 
    } 
    if (x_prev) 
        x_prev->next = y; 
    if (y_prev) 
        y_prev->next = x; 
    Node *temp = x->next; 
    x->next = y->next; 
    y->next = temp;  
    if (k == 1) 
        *head_ref = y; 
    if (k == n) 
        *head_ref = x; 
}  
int main() 
{ 
    struct Node *head = NULL; 
    for (int i = 8; i >= 1; i--) 
       push(&head, i); 
    cout << "Original Linked List: "; 
    printList(head); 
    for (int k = 1; k < 9; k++) 
    { 
        swapKth(&head, k); 
        cout << "\nModified List for k = " << k << endl; 
        printList(head); 
    } 
  return 0; 
} 
