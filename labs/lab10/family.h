#include <iostream>
#include <fstream>
using namespace std;

class FamilyTree {
  public:
    FamilyTree(string filename);
    ~FamilyTree();
    void preOrder();
    void postOrder();
  private:
    static const int MaxChildren = 5;
    struct Node {
        string name;
        int numChildren;
        Node *children[MaxChildren];
        Node *parent;
    };
    Node *root;
    void visit(Node *, int indent);
    void preOrder(Node *, int indent);
    void postOrder(Node *, int indent);
    void destroyAll(Node *);
};

