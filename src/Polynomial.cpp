#include "Polynomial.h"

Polynomial::Polynomial()
{
    this->head = this->tail = NULL;
}

Node *Polynomial::createNode(int hs, int sm) {
    Node *p = new Node;
    if (p == NULL) exit(1);
    p->hs = hs;
    p->sm = sm;
    p->next = NULL;
    return p;
}

void Polynomial::addTail(int hs, int sm) {
    if (this->head == NULL) this->head = this->tail = node;
    else {
        this->tail->next = p;
        this->tail = p; // cap nhat lai l tail
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

