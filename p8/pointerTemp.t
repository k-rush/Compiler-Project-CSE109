/*
  Kyle Rush
  CSE 109
  p6
  This file includes the Node and Link classes. */

#include <iostream>
using namespace std;

/* This is the definition of the Node class. */
template<class KEY, class DATA>
class Node {
public:
  KEY key;
  DATA data;
  Node *next;
  Node(KEY k, Node* n);
  Node(KEY k, DATA d, Node *n);
  Node(const Node &n);
};

/* 2-arg constructor for Node. */
template<class KEY, class DATA>
Node<KEY, DATA>::Node (KEY k, Node<KEY,DATA>* n)
{
  key=k;
  next=n;
}

/* 3-arg constructor for Node. */
template<class KEY, class DATA>
Node<KEY, DATA>::Node(KEY k, DATA d, Node<KEY,DATA> *n) {
  key = k;
  data = d;
  next = n;
}

/* Node's copy constructor. */
template<class KEY, class DATA>
Node<KEY,DATA>::Node(const Node<KEY,DATA> &n) {
  next = n.next;
  key = n.key;
  data = n.data;
}

/* This is the definition of the Link class. */
template<class KEY, class DATA>
class Link {
private:
  Node<KEY,DATA> *head;
public :
  Link();
  Link(const Link &l);
  ~Link();

  Node<KEY,DATA>* copy (Node<KEY,DATA>* target);
  Node<KEY,DATA>* add(KEY k);
  void print(Node<KEY,DATA> *temp, ostream &out) const;
  DATA & operator [] (KEY k);

  template<class K, class D>
  friend ostream & operator << (ostream &out, const Link<K,D> &l);
  bool inList(KEY k);
};

/* default constructor for Link. */
template<class KEY, class DATA>
Link<KEY,DATA>::Link() {
  head = NULL;
}

/*This is a recursive helper method to the copy constructor. */
template<class KEY, class DATA>
Node<KEY,DATA>* Link<KEY,DATA>::copy (Node<KEY,DATA>* target)
{
  if(target == NULL)
      return NULL;

  return new Node<KEY,DATA> (target->key, target->data, copy(target->next));
}

/*Copy constructor for Link. */
template<class KEY, class DATA>
Link<KEY,DATA>::Link(const Link<KEY,DATA> &l) {
  
  head = copy(l.head);
}

/*Destructor for Link. */
template <class KEY, class DATA>
Link<KEY,DATA>::~Link() {
  delete head;
}

/*Method used to add a Node to the linked list. */
template<class KEY, class DATA>
Node<KEY,DATA>* Link<KEY,DATA>::add(KEY k) {
  if (head == NULL)
    return (head = new Node<KEY,DATA> (k, NULL));

  Node<KEY,DATA> *temp = head;
  
  while(temp->next != NULL && temp->next->key > k)
    temp = temp->next;
  temp->next = new Node<KEY,DATA>(k,temp->next);
  return temp->next;
}

/* Operator searches for KEY inside the list, and returns the location
   of the DATA stored with that KEY. */
template<class KEY, class DATA>
DATA& Link<KEY,DATA>::operator [] (KEY k)
{
  if (!inList (k))
    return add (k)->data;

  Node<KEY, DATA> *temp = head;
  while (temp != NULL && temp->key != k)
    temp = temp->next;

  return temp->data;
}

/*Checks to see if a KEY is in the list. */
template<class KEY, class DATA>
bool Link<KEY,DATA>::inList(KEY k) {
  Node<KEY,DATA> *temp = head;
  bool found = false;
  while(temp != NULL && !found) {
    if(temp->key == k) found = true;
    temp = temp->next;
  }
  return found;
}

/*Prints out the list. */
template<class KEY, class DATA>
ostream & operator << (ostream &out, const Link<KEY,DATA> &l) {
  l.print(l.head, out);
  return out;
}

/*Recursive helper method to the << operator. */
template<class KEY, class DATA>
void Link<KEY,DATA>::print(Node<KEY,DATA> *temp, ostream &out) const {
  if(temp != NULL) {
     out<<"(\""<<temp->key<<"\", "<<temp->data<<")->";
     print(temp->next, out);
  }
  else out<<"NULL";
}

