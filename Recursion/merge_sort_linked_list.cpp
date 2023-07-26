#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        cout << " HI " << endl;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";

    print(head->next);
}

void add(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *temp = head;
    Node *newNode = new Node(data);

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


Node *mid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (slow->next != NULL && (fast != NULL && fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


void mergeSort(Node *head){
    if (head == NULL) {
        cout << head
        
        return;
        }
    Node *midNode = mid(head);
    Node *h1 = head;
    Node *h2 = midNode->next;

}


int main()
{

    Node *head = NULL;
    add(head, 5);
    add(head, 2);
    add(head, 1);
    add(head, 7);
    add(head, 10);

    print(head);
    cout << endl;

    Node *midNode = mid(head);

    cout << midNode->data << endl;

    return 0;
}