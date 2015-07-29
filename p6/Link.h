#ifndef LINK_H
#define LINK_H
#include "check.h"
template<class KEY, class DATA>
class Link {
private:
  Node *head;
public:
  Link();
  Link(Link & l);
  ~Link();
  DATA & operator [] (KEY k) const;
  friend ostream & operator << (const Link &l);
  bool inList();
}
#endif
