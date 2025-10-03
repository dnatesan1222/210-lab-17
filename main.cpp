// COMSC-210 | Lab 17 | Diksha Tara Natesan
// IDE used: Vim/Terminal

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};


//function prototypes

// headNode() takes the original head of the Linked List 
//   and creates a new node and makes it the head of the LL
// arguments: takes in the head Node of an LL and takes a 
//   float value to create a new head node to add to the LL
void headNode(Node *&head, float val);

// tailNode() takes the head of the Linked List and
//   creates a new node and makes it the tail of the LL
// arguments: takes in the head Node of an LL and takes a
//   float value to create a new node to add to the LL as a tail
void tailNode(Node *&head, float val);

// delete() takes the head of the Linked List and a position in the LL
//   where the Node should be deleted
// arguments: takes in the head Node of an LL and takes an
//   int value to know what to delete from the LL
void delete(Node *&head, int place);

// headNode() takes the head of the Linked List and
//   creates a new node and adds it to the specified place in the LL
// arguments: takes in the head Node of an LL and takes a
//   float value to create a new node and place where node is added to LL
void insert(Node *&head, int place, float val);


void output(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
