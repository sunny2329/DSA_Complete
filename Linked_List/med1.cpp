#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};


Node* middleNode(Node* head){
    Node* fast = head -> next;
    Node* slow = head;
    while(fast!=NULL){
        fast = fast -> next;
        if(fast!=NULL) fast = fast->next;
        slow = slow -> next;
    }
    return slow;
}


Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    if(head == NULL || head -> next == NULL) return head;

    while(curr!=NULL){
        Node* fwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

Node* solve(Node* &head){
    if(head == NULL || head -> next == NULL) return head;
    Node* head1 = solve(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return head1;
}

Node* reverseLLrec(Node* head){
    if(head == NULL || head -> next == NULL ) return head;
    return solve(head);
}


// has cycle in the linked list

bool hasCycle(Node* head){
    Node* temp = head;
    map<Node*, bool> mp;
    while(temp!=NULL){
        if(mp[temp] == true) return true;
        mp[temp] = true;
        temp = temp -> next;
    }
    return false;
}



int main()
{
}