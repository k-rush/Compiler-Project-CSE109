/*
  Kyle Rush
  CSE 109
  p6
  This file includes the Node and Link classes. */

#include <iostream>
using namespace std;


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

template<class KEY, class DATA>
Node<KEY, DATA>::Node (KEY k, Node<KEY,DATA>* n)
{
  key=k;
  next=n;
}

template<class KEY, class DATA>
Node<KEY, DATA>::Node(KEY k, DATA d, Node<KEY,DATA> *n) {
  key = k;
  data = d;
  next = n;
}

template<class KEY, class DATA>
Node<KEY,DATA>::Node(const Node<KEY,DATA> &n) {
  next = n.next;
  key = n.key;
  data = n.data;
}

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

template<class KEY, class DATA>
Link<KEY,DATA>::Link() {
  head = NULL;
}

template<class KEY, class DATA>
Node<KEY,DATA>* Link<KEY,DATA>::copy (Node<KEY,DATA>* target)
{
  if(target == NULL)
      return NULL;

  return new Node<KEY,DATA> (target->key, target->data, copy(target->next));
}

template<class KEY, class DATA>
Link<KEY,DATA>::Link(const Link<KEY,DATA> &l) {
  
  head = copy(l.head);
}

template <class KEY, class DATA>
Link<KEY,DATA>::~Link() {
  delete head;
}

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

template<class KEY, class DATA>
ostream & operator << (ostream &out, const Link<KEY,DATA> &l) {
  l.print(l.head, out);
  return out;
}

template<class KEY, class DATA>
void Link<KEY,DATA>::print(Node<KEY,DATA> *temp, ostream &out) const {
  if(temp != NULL) {
     out<<"(\""<<temp->key<<"\", "<<temp->data<<")->";
     print(temp->next, out);
  }
  else out<<"NULL";
}

