#include <iostream>

using namespace std;

template <class T>
class CList
{
 public:
  struct Node {
    T value;
    Node *pNext;
  };

 public:
  void operator = (const CList &certainList)
    {
      erase(list_);

      Node* list = certainList.list_;

      add(list_, list);
    }

  CList operator - (T n)
  {
    CList resuit;

    add(resuit.list_, list_);

    Node *pCur = resuit.list_, *pPrev = resuit.list_;
    find(pCur, pPrev, n);
    if (pCur != NULL) {
      if (resuit.list_->value == n)
        resuit.list_ = resuit.list_->pNext;
      else
        pPrev->pNext = pCur->pNext;

      delete pCur;
    }

    return resuit;
  }

  CList operator - (const CList &certainList)
  {
    CList resuit;

    add(resuit.list_, list_);

    Node* list = certainList.list_;

    while (list != NULL) {
      resuit = resuit - list->value;
      list = list->pNext;
    }

    return resuit;
  }

  void printList() {
    if (list_ == NULL)
      cout << " empty:(\n";
    else {
      Node* list = list_;
      while (list != NULL) {
        cout << " " << list->value;
        list = list->pNext;
      }
      cout << endl;
    }
  }

 private:
  bool suitable (Node* list, T n)
  {
    while (list != NULL) {
      if (list->value == n)
        return false;
      list = list->pNext;
    }
    return true;
  }

  void add(Node* &top, int value)
  {
    Node *node = new Node;
    node->value = value;

    if (top == NULL)
      top = node;
    else {
      node->pNext = top;
      top = node;
    }
  }

  void add(Node* &res, Node* list)
  {
    while (list != NULL) {
      if (suitable(res, list->value)) {
        Node *node = new Node;
        node->value = list->value;
        node->pNext = res;
        res = node;
      }
      list = list->pNext;
    }
  }

  void find (Node* &pCur, Node* &pPrev, T key)
  {
    while ((pCur != NULL) && (pCur->value != key)) {
      pPrev = pCur;
      pCur = pCur->pNext;
    }
  }

  void erase(Node* &list)
  {
    while (list != NULL) {
      Node* toDel = list;
      list = list->pNext;
      delete toDel;
    }
  }


 public:
  CList()
    {
      list_ = NULL;
    }

  CList(T n)
    {
      Node* node = new Node;
      node->value = n;
      node->pNext = NULL;

      list_ = node;
    }

  CList(T* array, int n)
    {
      list_ = NULL;

      for (int i = 0; i < n; i++) {
        Node* node = new Node;
        node->value = array[i];
        node->pNext = list_;
        list_ = node;
      }
    }

  CList(const CList &certainList)
    {
      list_ = NULL;

      add(list_, certainList.list_);
    }

  ~CList()
    {
      erase(list_);//	cout << " destructor done\n";
    }


 private:
  Node *list_;
};
