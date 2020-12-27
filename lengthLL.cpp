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
void print(Node *head) {
    Node *temp = head;
    while(temp != null) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
int lenght(Node *head) {
    int count=0;
    Node *curr = head;
    while(curr != null) {
        count++;
        curr=curr->next;
    }
    return count;
}
int main() {
    cout << "Enter the linked list (Followed by -1 at end to end the Linked List)" << endl;
    Node *head =  takeInput();
    cout << "Lenght: " << lenght(head) << endl;
}