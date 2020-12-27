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
    Node *head=null;
    Node *tail=null;
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
Node *appendLastNtoFirstN(Node *head, int n) {
    int count=0;
    Node *temp = head;
    Node *temp1 = head;
    Node *last = head;
    while(temp != null) {
        count++;
        last=temp;
        temp=temp->next;
    }
    if(count==0)
    return null;
    if(count==1) {
        return head;
    }
    last->next=head;
    for(int i=0;i<count-n-1;i++) {
        temp1=temp1->next;
    }
    head=temp1->next;
    temp1->next=null;
    return head;
}
void print(Node *head) {
    Node *temp=head;
    while(temp != null) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
int main() {
    Node *head = takeInput();
    int n;
    cin >> n;
    head = appendLastNtoFirstN(head, n);
    print(head);
}