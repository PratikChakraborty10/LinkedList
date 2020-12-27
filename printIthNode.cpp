#include<iostream>
using namespace std;
#define null NULL
class Node {
  public:
    int data;
    Node *next;
    Node(int data) {
        this->data=data;
        next=null;
    }  
};
Node *takeInput() {
    int data;
    cin >> data;
    Node *head = null;
    Node *tail = null;
    while(data != -1) {
    Node *newNode = new Node(data);
    if(head==null) {
        head=newNode;
        tail=newNode;
    } else {
        tail->next=newNode;
        tail=newNode;
        }
        cin >> data;
    }
    return head;
}
void printIthNode(Node *head, int i){
    int count=0;
    Node *curr = head;
    while(curr != null) {
        if(count==i) 
            cout << curr->data;
            count++;
             curr=curr->next;
        }       
}
int main() {
    Node *head = takeInput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
}