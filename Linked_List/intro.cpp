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





int main()
{
}
