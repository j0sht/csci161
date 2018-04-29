#include "family.h"

FamilyTree::FamilyTree(string filename)
{
    ifstream in(filename.c_str());

    if (in.fail() || in.eof()) {
        root = 0;
        in.close();
        return;
    }

    string line;
    getline(in, line);
    if (line == "<" || line == ">") {
        in.close();
        throw string("invalid file format");
    }
    root = new Node;
    root->name = line;
    root->numChildren = 0;
    root->parent = 0;

    Node *ptr = 0;
    while (!in.eof()) {
        getline(in, line);
        // for debug purposes:
        // cout << "Here -> " << line << endl;
        if (line == ">") {
            ptr = ptr->parent;
        } else if (line == "<") {
            if (ptr == 0)
                ptr = root;
            else
                ptr = ptr->children[ptr->numChildren - 1];
        } else if (line != "") {
            if (ptr->numChildren == MaxChildren) {
                in.close();
                throw string("invalid file format");
            }
            ptr->children[ptr->numChildren] = new Node;
            ptr->children[ptr->numChildren]->numChildren = 0;
            ptr->children[ptr->numChildren]->name = line;
            ptr->children[ptr->numChildren]->parent = ptr;
            ptr->numChildren++;
        }
    }

    if (ptr != 0) {
        in.close();
        throw string("invalid file format");
    }
    in.close();
}
    
FamilyTree::~FamilyTree()
{
    destroyAll(root);
}

void FamilyTree::destroyAll(FamilyTree::Node *ptr)
{
    if (ptr == 0)
        return;

    for(int i = 0; i < ptr->numChildren; i++)
        destroyAll(ptr->children[i]);

    delete ptr;
}

void FamilyTree::preOrder()
{
    preOrder(root, 0);
}

void FamilyTree::visit(FamilyTree::Node *ptr, int indent)
{
    for(int i = 0; i < indent; i++)
        cout << " ";
    cout << ptr->name << endl;
}

void FamilyTree::preOrder(FamilyTree::Node *ptr, int indent)
{
    if (ptr == 0)
        return;

    visit(ptr, indent);

    for(int i = 0; i < ptr->numChildren; i++)
        preOrder(ptr->children[i], indent+4);
}

void FamilyTree::postOrder()
{
    postOrder(root, 0);
}

void FamilyTree::postOrder(FamilyTree::Node *ptr, int indent)
{
    if (ptr == 0)
        return;

    for(int i = 0; i < ptr->numChildren; i++)
        postOrder(ptr->children[i], indent+4);

    visit(ptr, indent);
}


