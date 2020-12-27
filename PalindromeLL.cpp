#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data=data;
            next = NULL;
        }
};
Node *takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head==NULL) {
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
int lenght(Node *head) {
    int count = 0;
    Node *temp = head;
    while(temp != NULL) {
        count++;
        temp=temp->next;
    }
    return count;
}
Node* reverse(Node* head){
    Node* cur = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head = prev;
    return head;
}
bool isPalindrome(Node *head)
{
    //Write your code here
    if(head==NULL)
        return true;
    Node* temp1 = head;
    Node* temp2 = NULL;
    Node* head2 = NULL;
    int len = lenght(head);
    int mid= len/2;
    if(len==1){
        return true;
    }
    for(int i=0;i<mid-1;i++){
        temp1=temp1->next;
    }
    if(len%2==0){
        head2 = temp1->next;
    }
    else{
        head2 = temp1;
    }
    
    head2 = reverse(head2);
    temp2=head2;
    temp1=head;
    while(temp1!=NULL&&temp2!=NULL){
        if(temp1->data!=temp2->data){
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
    }
    return true;
}
int main() {
    Node *head = takeInput();
    bool ans = isPalindrome(head);
    if(ans)
    cout << "true" << endl;
    else
    cout << "false" << endl;
}