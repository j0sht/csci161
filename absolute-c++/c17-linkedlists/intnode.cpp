#include <iostream>
using namespace std;

class IntNode {
public:
    IntNode() {} // you couldn't use method 1 below without this constructor
    IntNode(int theData, IntNode* theLink) : data(theData), link(theLink) {}
    IntNode* getLink() const { return link; }
    int getData() const { return data; }
    void setData(int theData) { data = theData; }
    void setLink(IntNode* pointer) { link = pointer; }
private:
    int data;
    IntNode *link;
};
typedef IntNode* IntNodePtr;

// Precondition: The pointer variable head points to the head
//               of a linked list.
// Postcondition: A new node containing theData has been added
//                at the head of a linked list.
void headInsert(IntNodePtr& head, int theData) {
    head = new IntNode(theData, head);
}

// Precondition: afterMe points to a node in a linked list.
// Postcondition: A new node containing theData has been added
//                after the node pointed to by afterMe.
void insert(IntNodePtr afterMe, int theData) {
    afterMe->setLink(new IntNode(theData, afterMe->getLink()));
}

void remove(IntNodePtr before, IntNodePtr discard) {
    before->setLink(discard->getLink());
    delete discard;
}

// Precondition: The pointer head points to the head of a linked list.
//               The pointer variable in the last node is nullptr.
//               If the list is empty, then ehad is nullptr.
//               Returns a pointer that points to the first node that
//                contains the target. If no node contains the target,
//                the function returns nullptr.
IntNodePtr search(IntNodePtr head, int target) {
    IntNodePtr here = head;
    if (here == nullptr)
	return nullptr;
    else {
	while (here->getData() != target && here->getLink() != nullptr)
	    here = here->getLink();
	if (here->getData() == target)
	    return here;
	else
	    return nullptr;
    }
}

int main() {
    IntNodePtr head;
    // Creating linked list method 1:
    // head = new IntNode;
    // head->setData(3);
    // head->setLink(nullptr);
    // Creating linked list method 2 (with constructor):
    head = new IntNode(3, nullptr);
    return 0;
}
