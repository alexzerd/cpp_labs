#include <iostream>

using namespace std;

template <class T>
class CTree
{
 public:
  struct Tree {
    T value;
    Tree *pLeft;
    Tree *pRight;
  };


 public:
  void searchPlace(Tree* top, Tree* &place, T key)
  {
    while (top != NULL) {
      place = top;
      if (top->value > key)
        top = top->pLeft;
      else
        top = top->pRight;
    }
  }

  void add(Tree* &top, T key)
  {
    Tree* node = new Tree;

    node->pLeft= NULL;
    node->pRight = NULL;
    node->value = key;

    if (top == NULL) {
      top = node;
    } else {
      Tree *placeForElem = NULL;
      searchPlace(top, placeForElem, key);
      if (placeForElem->value > key)
        placeForElem->pLeft = node;
      else
        placeForElem->pRight = node;
    }
  }

  void add(Tree* &top, Tree* certainTree)
  {
    if (certainTree == NULL)
      return;

    add(top, certainTree->value);

    add(top, certainTree->pLeft);
    add(top, certainTree->pRight);
  }

  void erase(Tree* &top)
  {
    if (top == NULL)
      return;

    erase(top->pLeft);
    erase(top->pRight);

    delete top;

    top = NULL;
  }

  void delElement(Tree* &top, T key)
  {
    Tree* p = NULL;
    searchPlace(top, p, key);

    delete *p;
    p = NULL;
  }

  void print_tree_level(Tree * top, int level, int &numOfL)
{
	if (top)
	{
	    numOfL = level > numOfL ? level : numOfL;
	    print_tree_level (top -> pLeft, level + 1, numOfL);

		/*for (int i = 0; i < level; i++)
            cout <<"    ";
		cout << top -> value <<endl;*/
		 numOfL = level > numOfL ? level : numOfL;
		print_tree_level(top -> pRight, level + 1, numOfL);

	}

}

 public:
  CTree()
    {
      top_ = NULL;
    }

  CTree(T number)
    {
      top_ = NULL;

      add(top_, number);
    }

  CTree(T* array, int N)
    {
      top_ = NULL;

      for (int i = 0; i < N; i++)
        add(top_, array[i]);
    }

  CTree(const CTree &certainTree)
    {
      top_ = NULL;

      add(top_, certainTree.top_);
    }

  ~CTree()
    {
      erase(top_);//	cout << "destructor done\n";
    }

 public:
  Tree* top_;
};
