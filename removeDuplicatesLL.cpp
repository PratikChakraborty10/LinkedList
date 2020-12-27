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
// input function
Node *takeInput() {
    int data;
    cin >> data;
    Node *head = null;
    Node *tail = null;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head==null) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next=newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
Node *removeDplicates(Node *head) {
    if(head==null) {
        return null;
    }
    Node *temp=head;
    Node *q;
    while(temp != null && temp->next != null) {
        if(temp->data == temp->next->data) {
        q=temp->next->next;
        if(q==null) {
            temp->next=null;
            break;
        }
        temp->next=q;
        }
        if(temp->data != temp->next->data)
        temp=temp->next;
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
int main() {
    Node *head = takeInput();
    head = removeDplicates(head);
    print(head);
}