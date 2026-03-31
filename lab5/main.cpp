#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void pushBack(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

double average(Node* head) {
    int sum = 0, count = 0;
    while (head) {
        sum += head->data;
        count++;
        head = head->next;
    }
    return (double)sum / count;
}

void removeFirstEven(Node*& head) {
    if (!head) return;

    if (head->data % 2 == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* cur = head;
    while (cur->next && cur->next->data % 2 != 0)
        cur = cur->next;

    if (cur->next) {
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 4; i++)
        pushBack(head, i);

    printList(head);

    cout << "Avg: " << average(head) << endl;

    removeFirstEven(head);
    printList(head);

    return 0;
}
