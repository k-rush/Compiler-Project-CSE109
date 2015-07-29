#include "link.h"

Link::Link(const Link & l) {
  head = new Node(head);
}

Link::~Link() {
  delete head[];
}

Link::Link() {
  head = new Node(NULL,NULL);
}

ostream & operator << (ostream &out, Link &l) {
  display(out, l->head);
}

void Link::display(ostream &out, Node *next) {
  if(next != NULL) {
    out<<*next<<" ";
    display(out, next->next);
  }
}

DATA & Link::operator[](KEY k) {
  List temp = head;
  //search for word, add it if doesn't exist.
  return temp->data;
}


