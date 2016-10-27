/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  if (head != NULL) {
    if (position == 0) {
      Node *aux = head;
      head = aux->next;
      aux->next = NULL;
      delete aux;
    } else {
      Node *aux1 = head->next;
      Node *aux2 = head;
      int pos{1};
      while (pos < position && aux1->next != NULL) {
        pos++;
        aux1 = aux1->next;
        aux2 = aux2->next;
      }
      aux2->next = aux1->next;
      aux1->next = NULL;
      delete aux1;
    }
  }
  return head;
}
