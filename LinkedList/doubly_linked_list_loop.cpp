#include <bits/stdc++.h>

using namespace std;

class DoublyNode
{
public:
    int data;
    DoublyNode *pre, *next;

    DoublyNode(int data){
        this->data = data;

        pre = NULL;
        next = NULL;
    }

    DoublyNode(){

    }
};

void display(DoublyNode *&head){
    cout << "Displing" << endl;
    DoublyNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";

        temp = temp->next;
    }
    
}

void insertAtTail(DoublyNode *&head, int data){
    DoublyNode *newDoublyNode = new DoublyNode(data);

    DoublyNode *temp = head;

    if (head == NULL){
        head = newDoublyNode;
        return;
    }

    while (temp->next != NULL)  
    {
        temp = temp->next;
    }
    


    temp->next = newDoublyNode;
    newDoublyNode->pre = temp;
    newDoublyNode->next = NULL;
}


int main()
{
    DoublyNode *head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    display(head);

    return 0;
}