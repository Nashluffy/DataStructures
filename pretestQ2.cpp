// Partial implementation of a linked list.
// Code is buggy. Fix bugs. Do NOT re-write the whole code!


#include <iostream>
using namespace std;


class Node {
    private:
        string data;
        Node* next;
    public:
        Node(string s, Node* n);
        string getData() {return data;}
        Node* getNext() {return next;}
};

Node::Node(string s, Node* n){
    data = s;
    next = n;
}

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList();
        bool insert(string s);
        friend ostream& operator<<(ostream& os, LinkedList l);
};

LinkedList::LinkedList() : head(nullptr){

}


bool LinkedList::insert(string s){  // Create a node
    Node* n = new Node(s, head);
    head = n;
}

ostream& operator<<(ostream& os, LinkedList l){
    Node* n = l.head;
    while (n != nullptr) {
        os << n->getData() << " ";
        n = n->getNext();
    }
    return os;
}
int main(){
    LinkedList poets;
    poets.insert("Wordsworth");
    poets.insert("Shelley");
    poets.insert("Byron");
    cout << poets << endl; //Should print Byron Shelley Wordsworth
}

