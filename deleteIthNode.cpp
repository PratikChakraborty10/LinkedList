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
Node *deleteNode(Node *head, int pos) {
    if(head == NULL) 
       return NULL; 
    if(pos == 0) 
    { 
        Node *res = head; 
        head=head->next;
        delete res; 
        return head;   
    } 
      
    head->next = deleteNode(head->next, pos-1); 
    return head; 
}
void print(Node *head) {
    Node *temp = head;
    while(temp!=null) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
int main() {
    Node *head=takeInput();
    int pos;
    cout << "Enter the position for deletion node: ";
    cin >> pos;
    deleteNode(head, pos);
     cout << "Modified Linked List: ";
     print(head);
}