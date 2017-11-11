#ifndef Polynomial_H
#define Polynomial_H

struct Node {
    int sm;
    int hs;
    Node *next;
};


class Polynomial
{
    Node *head, *tail;

    public:
        Polynomial();
        Polynomial(Polynomial& p);
        void Nhap();
        void Xuat();
        void DaoHam();
        Polynomial operator+(const Polynomial& poly);
        Polynomial operator*(Polynomial& Poly);
        void SetZero();

    private:
        void init();
        Node *createNode(int hs, int sm);
        void addTail(Node *p);
        Polynomial multiTerm(Polynomial&p, Node* term);
};

#endif // Polynomial_H
