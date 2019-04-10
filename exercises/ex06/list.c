/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
  int poppy;
  Node *head = *list;
  if(head==NULL){
    return -1;
  }

  Node *newHead = head->next;
  poppy = head->val;
  free(head);
  *list = newHead;

  return poppy;// FILL THIS IN!
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    // FILL THIS IN!
    Node *newHead = make_node(val,*list);
    *list = newHead;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    // FILL THIS IN!
    int count = 0;
    Node *prev;
    Node *head =*list;
    while(head->val!=val){
      if(head->next == NULL){
        return 0;
      }
      prev = head;
      head=head->next;
    }
    prev->next=head->next;
    free(head);
    return 1;
}

int swap(Node **list){
  Node * head = *list;
  Node * temp;
  if(head -> next == NULL){
    return -1;
  }
  else{
    temp=head->next;
    head->next=temp->next;
    temp->next = head;
    *list=temp;
    return 1;
  }
}

/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    // FILL THIS IN!
    Node *head = *list;
    Node *temp;
    Node *prev = NULL;
    while(head!=NULL){
      temp=head->next;
      head->next=prev;
      prev = head;
      head=temp;
    }
  *list = prev;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int poop = swap(list);
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);

    pop(list);
    pop(list);
    print_list(list);
    printf("%d\n",swap(list));
}
