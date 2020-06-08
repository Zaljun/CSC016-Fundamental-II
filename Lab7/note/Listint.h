#include <iostream>
#include <cassert>

using namespace std;

#ifndef LISTINT
#define LISTINT

class Listint
{
   private:
       int *ptr_list;
       int capacity;
       int size;
   public:
       Listint(int new_capacity = 100);
       Listint(const Listint &other);
       int insert(int new_item, int pos = 0);
       void display() const;
       ~Listint();
};

#endif
