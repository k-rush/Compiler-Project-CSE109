template<class KEY, class DATA>
class Node {
public:
  KEY key;
  DATA data;
  Node *next;

  Node(KEY k, DATA d, Node *n);
}

template<class KEY, class DATA>
Node::Node(KEY k, DATA d, Node *n) {
  key = k;
  data = d;
  next = n;
}

template<class KEY, class DATA>
class Link {
private:
  Node *head;
public :
  Link();
  Link(const Link &l);
  ~Link();

  void add(KEY k, DATA d);
  void print(Node *temp, ostream &out);
  DATA & operator [] (KEY k);
  friend ostream & operator << (ostream &out, const Link &l);
  bool inList(KEY &k);
}

template<class KEY, class DATA>
Link::Link() {
  head = NULL;
}

template<class KEY, class DATA>
Link::Link(const Link &l) {
  head = new Node(l.head);
}

template <class KEY, class DATA>
Link::~Link() {
  delete head;
}

tempalte<class KEY, class DATA>
Link::add(KEY k, DATA d) {
  Node *temp = head;
  while(*temp.next.key > temp.key)
    temp = temp.next;
  temp.next = new Node(k,d,temp.next);
}

template<class KEY, class DATA>
bool Link::inList(KEY k) {
  Node *temp = head;
  bool found = false;
  while(temp != NULL && !found) {
    if(temp.key == k) found = true;
    temp = temp.next;
  }
}

template<class KEY, class DATA>
friend ostream & operator << (ostream &out, const Link &l) {
  Node *temp = head;
  print(temp, out);
}

template<class KEY, class DATA>
void Link::print(Node *temp, ostream &out) {
  if(temp != NULL) {
     out<<"(\""<<temp.key<<"\", "<<temp.data<<")->";
     print(temp, out);
  }
  else out<<"NULL";
}

