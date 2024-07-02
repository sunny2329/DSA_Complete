#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

//1. Convert an array to a linked list and return the head

Node* arrayToLinkedlist(vector<int> ans){
    Node* head = new Node(ans[0]);
    Node* tail = head;
    for(int i = 1;i<ans.size();i++){
        Node* temp = new Node(ans[i]);
        tail -> next = temp;
        tail = temp;
    }
    return head;
}


//2. Insert a new node at beginning
Node* insertAtbBeginning(Node* head, int x){
    Node* temp = new Node(x);
    temp -> next = head;
    head = temp;
    return head;
}

//3. delete the last node of the linked list
Node* deleteTail(Node* head){
    Node* tail = head;
    while(tail->next->next != NULL){
        tail = tail -> next;
    }
    Node* temp = tail -> next;
    tail -> next = NULL;
    delete temp;
    return head;
}




int main()
{
}
