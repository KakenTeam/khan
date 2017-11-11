#include "Polynomial.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Polynomial::Polynomial()
{
   this->head = this->tail = NULL;
}

Polynomial::Polynomial(Polynomial& p)
{
    this->init();
    Node* cur = head;
    Node* curP = p.head;
    while (curP != NULL)
    {
        Node* newNode = createNode(curP->hs, curP->sm);
        this->addTail(newNode);
        curP = curP->next;
    }
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

void Polynomial::DaoHam() {
    Node *current = this->head;
    while (current != NULL) {
        current->hs *= current->sm;
        current->sm -= 1;

        if (current->next == this->tail) {
            current->next = NULL;
            return;
        }
        current = current->next;
    }
}

string In(Node* cur) {
    int hs = cur->hs, sm = cur->sm;
    stringstream res;
    if (hs) {
        if (sm == 0) res << hs;
        if (sm == 1) res << hs << "x";
        if (sm !=0 && sm != 1) res << hs << "x^" << sm;
    }
    return res.str();
}

void Polynomial::Xuat() {
    Node *currentNode = this->head;
    while (currentNode != NULL) {
        int hs = currentNode->hs;
        cout << In(currentNode);
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
    Node *p = this->head, *q = poly.head;

    while (p != NULL || q != NULL)
    {
        if (p == NULL)
        {
            result.addTail(q);
            q = q->next;
            continue;
        }
        if (q == NULL)
        {
            result.addTail(p);
            p = p->next;
            continue;
        }

        if (p->sm > q->sm) {
            result.addTail(p);
            p = p->next;
            continue;
        }

        if (p->sm < q->sm) {
            result.addTail(q);
            q = q->next;
            continue;
        }

        p->hs += q->hs;
        result.addTail(p);
        p = p->next;
        q = q->next;
    }
    return result;
}
Polynomial Polynomial::multiTerm(Polynomial &p, Node *term)
{
    Polynomial result(p);
    Node* cur = result.head;
    while (cur != NULL)
    {
        cur->hs *= term->hs;
        cur->sm += term->sm;
        cur = cur->next;
    }
    return result;
}
Polynomial Polynomial::operator*(Polynomial& poly) {

    Polynomial result;
    result.SetZero();
    Node* cur = this->head;
    while(cur != NULL){
        result = result + multiTerm(poly, cur);
        cur = cur->next;
    }
    return result;
}

void Polynomial::SetZero()
{
    Node* nodeZero = createNode(0, 0);
    this->init();
    this->addTail(nodeZero);
}

