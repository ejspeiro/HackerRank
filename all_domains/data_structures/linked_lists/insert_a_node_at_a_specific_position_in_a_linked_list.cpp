/*
  Insert Node at a given position in a linked list
  head can be NULL
  First element in the linked list is at position 0
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  if (head == NULL) {
    // List is empty.
    head = new Node;
    head->data = data;
    head->next = NULL;
  } else {
    // List is not empty.
    if (position == 0) {
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = head;
      head = tmp;
    } else {
      Node *aux = head;
      int pp{1};
      while (pp < position && aux->next != NULL) {
        pp++;
        aux = aux->next;
      }
      Node *tmp = new Node;
      tmp->next = aux->next;
      tmp->data = data;
      aux->next = tmp;
    }
  }
  return head;
}
