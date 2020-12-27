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
    Node *head= null;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head==null) {
            head=newNode;
        } else {
            Node *temp = head;
            while(temp->next!=null) {
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head) {
    Node *temp=head;
    while(temp!=null) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
} 
Node *mergerSortLL(Node *head1, Node *head2) {
    if(!head1) {
        return head2;
    }
    if(!head2) {
        return head1;
    }
    if(head1->data < head2->data) {
        head1->next=mergerSortLL(head1->next,head2);
        return head1;
    } else {
        head2->next=mergerSortLL(head1,head2->next);
        return head2;
    }
} 
int main() {
    Node *head1=takeInput();
    Node *head2=takeInput();
    Node *head3=mergerSortLL(head1,head2);
    print(head3);
}

// Coded by - Pratik Chakraborty