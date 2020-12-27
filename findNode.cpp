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
int findNode(Node *head, int pos) {
    int ans = -1;
    int count = 0;
    Node *temp = head;
    while(temp != null) {
        if(temp->data==pos) {
            ans = count;
            break;
        }
        temp=temp->next;
        count++;
    }
    return ans;
}
int main() {
    Node *head = takeInput();
    int pos;
    cin >> pos;
    cout << findNode(head, pos) << endl;
}