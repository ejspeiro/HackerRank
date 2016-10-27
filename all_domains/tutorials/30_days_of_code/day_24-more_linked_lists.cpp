#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

          Node* removeDuplicates(Node *head)
          {
            if (head != NULL || head->next != NULL) {
              Node *aux = head;
              // For each element in the list...
              while (aux->next != NULL) {
                Node *tmp = aux->next;
                // Check all of the other elements after said element...
                while (tmp != NULL) {
                  // If a duplicate is found, then...
                  if (tmp->data == aux->data) {
                    // Remove the duplicate.
                    Node *buf1 = tmp;
                    Node *buf2 = aux;
                    while (buf2->next != buf1) {
                      buf2 = buf2->next;
                    }
                    buf2->next = buf1->next;
                    tmp = tmp->next;
                    delete buf1;
                  } else {
                    tmp = tmp->next;
                  }
                }
                // In a case in where all duplicates comprise the list, we must verify that, after eliminating all of the
                // duplicates, referencing to aux->next would not tield a segfault, which will occur when validating if
                // the outter loop should continue.
                if (aux->next == NULL) {
                  break;
                } else {
                  aux = aux->next;
                }
              }
            }
            return head;
          }

         Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;

               }
                    return head;


          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};

int main()
{
    Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }
    head=mylist.removeDuplicates(head);

    mylist.display(head);

}
