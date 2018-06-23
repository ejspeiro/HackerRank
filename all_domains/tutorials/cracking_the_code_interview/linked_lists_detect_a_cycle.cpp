/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Check for empty list.
    if (head == nullptr) {
        return false;
    }
    // Initialize the vigilantes array.
    size_t max_num_nodes{100};
    Node **vigilantes = new Node*[max_num_nodes];
    for (size_t ii = 0; ii < max_num_nodes; ++ii) {
      vigilantes[ii] = nullptr;
    }
    // Traverse the list assisted by the vigilantes.
    Node *aux = head;
    size_t curr_node_idx{};
    while (aux != nullptr) {
      for (size_t ii = 0; ii <= curr_node_idx; ++ii) {
        if (aux == vigilantes[ii]) {
          return true;
        }
      }
      vigilantes[curr_node_idx] = aux;
      aux = aux->next;
      curr_node_idx++;
    }
    delete [] vigilantes;
    return false;
}
