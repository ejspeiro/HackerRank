/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  if (head == NULL) {
    head = new Node;
    head->next = NULL;
    head->data = data;
  } else {
    Node *aux = head;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = new Node;
    aux->next->data = data;
  }
  return head;
}
