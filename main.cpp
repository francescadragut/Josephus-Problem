#include<iostream>

using namespace std;

class Node{
    private:
        int key;
        Node * next;
    public:
        Node();
        Node(int);
        int getkey();
        Node * getnext();
        void setkey(int);
        void setnext(Node *);
};

Node::Node(){
    key = 0;
    next = NULL;
}

Node::Node(int k){
    key = k;
}

int Node::getkey(){
    return key;
}

Node * Node::getnext(){
    return next;
}

void Node::setnext(Node * p){
    next = p;
}

void Node::setkey(int n){
    key = n;
}

class Circle{

    private:
        Node * head;
        int size;

    public:
        Circle();
        Node * search(int);
        void appendNode(Node *, int);
        void createList(int);
        void deleteByKey(int);
        int getsize();
        int increasesize();
        int decreasesize();
        void printList();
        void thirdnode(Node *);
        void Josephus(int, int);
};

Circle::Circle(){
    head = NULL;
    size = 0;
}

int Circle::getsize(){
    return size;
}

int Circle::increasesize(){
    return size++;
}

int Circle::decreasesize(){
    return size--;
}

Node * Circle::search(int i){

    int j, n;
    Node *p = head;

    if (p == NULL){
        return p;
    }
    else{
        n = getsize();
        for(j = 1; j <= n; j++){
            if(j == i){
                return p;
            }
            p = p -> getnext();
        }
    }
}

void Circle::appendNode(Node * node, int size){

    if (head == NULL){
        head = node;
        node -> setnext(head);
    }
    else{
        Node * p = head;
        while (p -> getnext() != head){
            p = p -> getnext();
        }
        p -> setnext(node);
        node -> setnext(head);
    }
    increasesize();
}

void Circle::createList(int n){

    int i;
    for(i = 1; i <= n; i++){
        Node * n1 = new Node();
        n1 -> setkey(i);
        appendNode(n1,n);
    }
}

void Circle::deleteByKey(int k){

    Node * p = search(k);

    if (p == head){
        if (head -> getnext() == NULL){
            head = NULL;
        }
        else{
            Node * p1 = head;
            while (p1 -> getnext() != head){
                p1 = p1 -> getnext();
            }
            p1 -> setnext(head -> getnext());
            head = head -> getnext();
        }
    }
    else{
        Node * n = NULL;
        Node * previous = head;
        Node * current = head -> getnext();
        while (current != NULL){
            if (current -> getkey() == k){
                n = current;
                current = NULL;
            }
            else{
                previous = previous -> getnext();
                current = current -> getnext();
            }
        }
        previous -> setnext(n -> getnext());
    }
    decreasesize();
}

void Circle::printList(){
    if (head == NULL){
        cout << "There are no people in the circle.";
    }
    else{
        Node * n = head;
        cout << "Linear representation of the circle: " << endl;
        do{
            cout << n -> getkey() << " -> ";
            n = n -> getnext();
        }
        while (n != head);
        cout << head -> getkey() << endl << endl;
    }
}

void Circle::thirdnode(Node * givenNode){

    if(givenNode != NULL){
        Node * p = givenNode;
        for(int i = 1; i < 3; i++){
            givenNode = givenNode -> getnext();
        }
        cout << givenNode -> getkey();
    }
}

void Circle::Josephus(int i, int n){

    Node * p;
    int del;

    p = search(i);

    cout << "The process is:" << endl;
    while (getsize() > 1){
        cout << p -> getkey() << " goes to ";
        thirdnode(p);
        cout << " and " << p -> getnext() -> getkey() << " is killed." << endl;

        del = p->getnext()->getkey();
        deleteByKey(del);

        p = p->getnext();
    }
    cout<< endl<< "Last person to survive is " << p->getkey() << endl;
}

int main(){

    Circle obj;
    int n, i;

    cout << "Enter the number of people in the circle: ";
    cin >> n;
    cout << endl;
    cout << "Enter the person from which the process starts: ";
    cin >> i;
    cout << endl;

    obj.createList(n);
    obj.printList();
    obj.Josephus(i,n);

    return 0;
}
