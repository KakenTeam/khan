#include "Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial()
{
    this->head = this->tail = NULL;
}

Node *Polynomial::createNode(int hs, int sm) {
    Node *p = new Node;
    p->hs = hs;
    p->sm = sm;
    p->next = NULL;
    return p;
}

void Polynomial::addTail(Node *node) {
    if (this->head == NULL) this->head = this->tail = node;
    else {
        this->tail->next = node;
        this->tail = node; // cap nhat lai l tail
    }
}

void Polynomial::Nhap() {
    int levelPolynomial, x;
    cout << "\nNhap bac cua da thuc: "; cin >> levelPolynomial;
    for(int i = levelPolynomial; i >= 0; i--) {
        cout << "\n\tNhap he so cua x^" << i << ": "; cin >> x;
        Node *node = createNode( x, i);
        addTail(node);
    }
}

void Polynomial::Xuat() {
    Node *currentNode = this->head;
    while (currentNode != this->tail) {
        if (currentNode->hs) cout << currentNode->hs << "x^" << currentNode->sm;
        currentNode = currentNode->next;
        if (currentNode->hs) {
            if (currentNode->hs > 0) cout << "+";
                else cout << " ";
        }
    }
}

