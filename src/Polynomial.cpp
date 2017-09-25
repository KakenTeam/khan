#include "Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial()
{
   this->init();
}

void Polynomial::init() {
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
    this->init();
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
    while (currentNode != NULL) {
        if (currentNode->hs) {
            if (currentNode == this->tail) {
                if (currentNode->hs != 0 )
                    cout << currentNode->hs;
            } else
            if (currentNode->hs == 1)
                cout << "x^" << currentNode->sm;
            else if (currentNode->hs != 1 && currentNode->hs != 0)
                cout << currentNode->hs << "x^" << currentNode->sm;
        }
        if (currentNode->next == NULL) return;
        currentNode = currentNode->next;
        if (currentNode->hs) {
            if (currentNode->hs > 0) cout << " + ";
                else cout << " ";
        }
    }
}

Polynomial Polynomial::operator+(const Polynomial& poly) {
    Polynomial result;
    Node *p = new Node(), *q = new Node();
    if (this->head->sm > poly.head->sm) {
        p = this->head;
        q = poly.head;
    }
    else {
        p = poly.head;
        q = this->head;
    }

    while (p->sm > q->sm) {
        result.addTail(p);
        p = p->next;
    }

    while (p != NULL) {
        p->hs += q->hs;
        result.addTail(p);
        p = p->next;
        q = q->next;
    }

    return result;
}

