#include <iostream>

using namespace std;

template <class T>

class CDLList
{
 public:
  struct Node {
    T value;
    Node *pNext;
    Node *pPrev;
  };

 public:

  void printList()
  {
    Node* top = head_;

    if (top == NULL)
      cout << " empty:(\n";
    else {
      while (top != NULL) {
        cout << " " << top->value;
        top = top->pNext;
      }
      cout << "\n";
    }
  }

  Node* find (T key)
  {
    Node *top = head_;

    while ((top != NULL) && (top->value != key))
      top = top->pNext;

    return top;
  }

  int calcValue()
  {
    CDLList copy;

    add(copy.head_, copy.tail_, head_);

    int res = 0;

   while(copy.tail_ -> pNext != copy.head_)
        {

            res += (copy.tail_ -> value)+(copy.head_ -> value);
            cout << (copy.tail_ -> value)+(copy.head_ -> value)<<" ";

            copy.head_ = copy.head_ -> pNext;
            copy.tail_ = copy.tail_ -> pPrev;
        }


        cout<<endl<<endl;
        cout<<res;
        cout<<endl;

        return res;
  }

 private:
  void add(Node* &top, Node* &end, Node* source)
  {
    while (source != NULL) {
      add(top, end, source->value);

      source = source->pNext;
    }
  }

  void add(Node* &top, Node* &end, T n)
  {
    Node *node = new Node;
    node->value = n;
    node->pNext = NULL;
    node->pPrev = NULL;

    if (top == NULL) {
      top = node;
      end = node;
    } else {
      node->pNext = top;
      top->pPrev = node;
      top = node;
    }
  }

  void erase(Node* &head, Node* &tail)
  {
    tail = NULL;
    while (head != NULL) {
      Node* toDel = head;
      head = head->pNext;
      delete toDel;
    }
  }

  void delElement(Node* &top, Node* &prev, T key)
  {
    if (top == NULL)
      return;

    delElement(top->pNext, top, key);

    if (top->value == key) {
      Node* toDel = top;
      top->pPrev = prev;
      top = top->pNext;

      delete toDel;
    }
  }


 public:
  CDLList()
    {
      head_ = NULL;
      tail_ = NULL;
    }

  CDLList(T n)
    {
      head_ = NULL;
      tail_ = NULL;

      add(head_, tail_, n);
    }

  CDLList(T* array, int n)
    {
      head_ = NULL;
      tail_ = NULL;

      for (int i = 0; i < n; i++)
        add(head_, tail_, array[i]);
    }

  CDLList(const CDLList &certainList)
    {
      head_ = NULL;
      tail_ = NULL;

      Node* list = certainList.head_;

      add(head_, tail_, list);
    }

  ~CDLList()
    {
      erase(head_, tail_);// cout << " destructor done\n";
    }


 private:
  Node *head_, *tail_;
};
