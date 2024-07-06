#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

// 1. Convert an array to a linked list and return the head

Node *arrayToLinkedlist(vector<int> ans)
{
    Node *head = new Node(ans[0]);
    Node *tail = head;
    for (int i = 1; i < ans.size(); i++)
    {
        Node *temp = new Node(ans[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
}

// 2. Insert a new node at beginning
Node *insertAtbBeginning(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
    return head;
}

// 3. delete the last node of the linked list
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *tail = head;
    while (tail->next->next != NULL)
    {
        tail = tail->next;
    }
    Node *temp = tail->next;
    tail->next = NULL;
    delete temp;
    return head;
}

// 4. Delete the given node from the linked list without head

Node *deleteNode(Node *node)
{
    Node *nxt = node->next;
    Node *prev = NULL;
    while (nxt != NULL)
    {
        node->data = nxt->data;
        prev = node;
        node = nxt;
        nxt = nxt->next;
    }
    prev->next = NULL;
}

// 5. Function for number of node in the linked list

int countNode(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main()
{
}
