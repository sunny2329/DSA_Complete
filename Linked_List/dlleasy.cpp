#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node *constructDLL(vector<int> &arr)
{
    // code here
    Node *head = new Node(arr[0]);
    Node *temp = head;
    int n = arr.size();
    int i = 1;
    while (i < n)
    {
        Node *newN = new Node(arr[i]);
        temp->next = newN;
        newN->prev = temp;
        temp = newN;
        i++;
    }
    return head;
}

// delete a node from dll

Node *deleteNode(Node *head, int x)
{
    // Your code here

    int i = 2;
    Node *temp = head;
    if (x == 1)
    {
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }
    while (i < x)
    {
        temp = temp->next;
        i++;
    }
    Node *del = temp->next;
    if (del->next == NULL)
    {
        temp->next = NULL;
        delete del;
        return head;
    }
    temp->next = del->next;
    del->next->prev = temp;
    delete del;
    return head;
}

Node *reverseDLL(Node *head)
{
    // Your code here
    if (head == NULL || head->next == NULL)
        return head;

    Node *prevs = NULL;
    Node *current = head;
    while (current != NULL)
    {
        prevs = current->prev;
        current->prev = current->next;
        current->next = prevs;
        current = current->prev;
    }
    return prevs->prev;
}

int main()
{
}