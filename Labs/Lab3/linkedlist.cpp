#include <iostream>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL; // Initialize tail
}

LinkedList::~LinkedList() {
    Node *curr = head;
    while (curr) {
        Node *temp = curr;
        curr = curr->next;
        delete temp; // Delete each node
    }
}

void LinkedList::add(char ch) {
    Node *temp = new Node; // Allocate memory
    temp->data = ch;
    temp->next = NULL;
    if (!head) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void LinkedList::printHelper(Node *first) {
    if (!first){
	return;
    }
    cout << first->data << " ";
    printHelper(first->next);
}

void LinkedList::print() {
	if (!head){
		cout << "List is empty" << endl;
        	return;
     	}

    printHelper(head);
    cout << endl;
}

bool LinkedList::del(char ch) {
    return delHelper(head, ch); // Return the result of delHelper
}

bool LinkedList::delHelper(Node *&head, char ch) {
    if (!head)
        return false;
    if (head->data == ch) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    return delHelper(head->next, ch);
}
bool LinkedList::find(char ch) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data == ch) {
            return true; // Found the character
        }
        current = current->next;
    }
    return false; // Character not found
}

