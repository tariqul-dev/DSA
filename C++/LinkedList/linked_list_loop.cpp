#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node()
    {
    }
};

struct Positions
{
    int position[1000];
};

void display(Node *head)
{
    cout << "Displaying: " << endl;

    while (head != NULL)
    {
        cout << head->data;
        head = head->next;

        if (head != NULL)
            cout << "->";
    }

    cout << endl;
}

void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;

    newNode->next = temp;
    head = newNode;
}
void insertAtIndex(Node *&head, int index, int data)
{
    int indexCount = 0;
    Node *newNode = new Node(data);
    Node *temp = head;
    if (index < 0)
    {
        return;
    }

    if (index == 1)
    {
        insertAtHead(head, data);
        return;
    }

    while (indexCount != index - 2)
    {
        temp = temp->next;
        indexCount++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtTail(Node *&head, int data)
{

    Node *newNode = new Node(data);
    Node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // temp = newNode;
    temp->next = newNode;

    // newNode->next = temp;
    // temp = newNode;
    // newNode->next = NULL;
}

int length(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}
int searchByValue(Node *&head, int value)
{
    Node *temp = head;
    int index = 0;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1;
}
Positions searchDuplicateValue(Node *&head, int value)
{
    Node *temp = head;
    int index = 0;
    // int arr[length(head)];
    int arrIndex = 1;
    Positions p;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            p.position[arrIndex++] = index;
        }
        temp = temp->next;
        index++;
    }
    p.position[0] = arrIndex;

    return p;
}

void insertAfterValueUniq(Node *&head, int value, int data)
{
    // Node *temp = head;
    // Node *newNode = new Node(data);

    int index = searchByValue(head, value);
    insertAtIndex(head, index + 2, data);
}

void insertAfterValueDuplicate(Node *&head, int value, int data)
{
    // Node *temp = head;
    // Node *newNode = new Node(data);

    Positions p = searchDuplicateValue(head, 4);
    // insertAtIndex(head, p.position[1] + 2, data);

    if (p.position[0] == 1)
    {
        cout << "Value not found" << endl;
        return;
    }

    for (int i = 1; i < p.position[0]; i++)
    {
        insertAtIndex(head, p.position[i] + i + 1, data);
        // cout << p.position[i] << " ";
    }
}

// =========== delete operation ===========

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->next;

        delete temp;
    }
}

void deleteAtTail(Node *&head)
{
    Node *temp = head;

    if (temp == NULL)
        return;

    if (temp->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *t = temp->next->next;
    temp->next = NULL;
    delete t;
    return;
}

void deleteAtIndex(Node *&head, int index)
{
    Node *temp = head;
    int count = 0;

    if (temp == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    if (index >= length(head) || index < 0)
    {
        cout << "Index Out of Range" << endl;
        return;
    }

    if (temp->next == NULL || index == 0)
    {
        deleteAtHead(head);
        return;
    }

    while (count != index - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *delNode = temp->next;

    temp->next = delNode->next;

    delete delNode;
}
void deleteByValueSingle(Node *&head, int value)
{
    int index = searchByValue(head, value);
    if (index == -1)
    {
        cout << "Value not found" << endl;
        return;
    }
    deleteAtIndex(head, index);
}

void deleteByValueMultiple(Node *&head, int value)
{
    Positions p = searchDuplicateValue(head, value);
    if (p.position[0] == 1)
    {
        cout << "Value not found" << endl;
        return;
    }

    for (int i = 1; i < p.position[0]; i++)
    {
        deleteAtIndex(head, p.position[i] - i + 1);
    }
}

Node *reverseList(Node *&head)
{
    if (head->next == NULL)
        return head;

    Node *newNode = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newNode;
}

// ================ advanced topic ==============
// finding mid value with two pointer
int findMid(Node *&head)
{

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}
//  creating cycle in a linked list
void createCycle(Node *&head, int pos)
{
    Node *temp = head;
    int count = 0;
    Node *startNode;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
        if (count == pos)
        {
            startNode = temp;
        }
    }
    temp->next = startNode;
}
// cycle detection
bool detectCycle(Node *&head)
{

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
// cycle remove
void removeCycle(Node *&head)
{

    Node *slow = head, *fast = head;

    bool cycleStatus = detectCycle(head);

    if (cycleStatus)
    {
        cout << "Cycle Detected" << endl;

        cout << "Removing Cycle..." << endl;

        // while (fast != NULL && fast->next != NULL)
        // {
        //     slow =  slow->next;
        //     fast = fast->next->next;

        //     if (slow == fast){
        //         slow = fast;
        //         fast = head;
        //         break;
        //     }
        // }

        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        // reinitialize
        slow = fast;
        fast = head;

        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = NULL;

        cout << "Cycle Removed" << endl;
    }
    else
    {
        cout << "No Cycle Detected" << endl;
    }
}

int main()
{
    Node *head = NULL;

    // insertAtHead(head, 43);
    // insertAtHead(head, 3);
    // insertAtHead(head, 4);

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    // insertAtTail(head, 9);

    // insertAtHead(head, 32);

    // // display(head);
    // insertAtIndex(head, 3, 10);
    // insertAtIndex(head, 1, 20);
    // insertAfterValueUniq(head, 1, 40);
    // insertAfterValueUniq(head, 4, 22);

    // insertAfterValueDuplicate(head, 4, 52);

    // deleteAtHead(head);
    // insertAtTail(head, 3);

    // createCycle(head, 3);

    removeCycle(head);

    display(head);

    // int mid = findMid(head);
    // cout << endl;
    // cout << "Mid: " << mid << endl;

    // deleteAtTail(head);
    // deleteAtIndex(head, 1);
    // deleteByValueMultiple(head, 7);

    // Node * newHead = reverseList(head);

    // display(newHead);

    // cout << "Length: " << length(head) << endl;

    // Positions p = searchDuplicateValue(head, 4);

    // if (p.position[0] == 1){
    //     cout << "Value not found" << endl;
    // }else{
    //     int size = p.position[0];

    //     for (int i = 1; i < size; i++)
    //     {
    //         cout << p.position[i] << " ";
    //     }

    // }

    return 0;
}
