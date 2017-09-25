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
        void Nhap();
        void Xuat();
        Polynomial operator+(const Polynomial& poly);

    private:
        void init();
        Node *createNode(int hs, int sm);
        void addTail(Node *p);
};

#endif // Polynomial_H
