/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  if (head != NULL) {
    Node *aux = head;
    int list_size{1};
    while (aux->next != NULL) {
      aux = aux->next;
      list_size++;
    }
    Node **nodes;
    nodes = new Node*[list_size];
    aux = head;
    for (int ii = 0; ii < list_size; ii++) {
      nodes[ii] = aux;
      aux = aux->next;
    }
    for (int ii = list_size - 1; ii >= 0; ii--) {
      cout << nodes[ii]->data << endl;
    }
    delete [] nodes;
  }
}
