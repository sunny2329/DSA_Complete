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

Node *middleNode(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// isPalindrome in linked list

bool isPalindrome(Node *head)
{
    Node *temp = head;
    stack<int> s;
    while (temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (!s.empty())
    {
        if (s.top() != temp->data)
            return false;
        temp = temp->next;
        s.pop();
    }
    return true;
}

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    if (head == NULL || head->next == NULL)
        return head;

    while (curr != NULL)
    {
        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

Node *solve(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *head1 = solve(head->next);
    head->next->next = head;
    head->next = NULL;
    return head1;
}

Node *reverseLLrec(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    return solve(head);
}

// has cycle in the linked list

bool hasCycle(Node *head)
{
    Node *temp = head;
    map<Node *, bool> mp;
    while (temp != NULL)
    {
        if (mp[temp] == true)
            return true;
        mp[temp] = true;
        temp = temp->next;
    }
    return false;
}

// detect cycle in the linked list
// approach: pehle fast aur slow ko iterate karvoa jaise hi fast == slow ho jai slow=head kar do aur ek baar aur loop chalega jab tak slow == fast nahi hota then return slow as answer.
Node *detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            slow = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    return NULL;
}

// Odd Even linked list
Node *oddEvenLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *first = head;
    Node *second = head->next;
    Node *temp = second;
    while (first->next != NULL && second->next != NULL)
    {
        // cout << first ->next->next->val;

        first->next = first->next->next;
        first = first->next;
        second->next = second->next->next;
        second = second->next;
    }
    first->next = temp;

    return head;
}

// remove the node from kth behind
int lengthLL(Node *head)
{

    int ans = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        ans++;
        temp = temp->next;
    }
    return ans;
}
Node *removeNthFromEnd(Node *head, int n)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return NULL;
    if ((lengthLL(head) - n) == 0)
    {
        head = head->next;
        return head;
    }
    int i = lengthLL(head) - n - 1;
    Node *temp = head;
    while (i > 0)
    {
        temp = temp->next;
        i--;
    }
    temp->next = temp->next->next;
    return head;
}

int main()
{
}