#include <bits/stdc++.h>
using namespace std;

struct N 
{
    int v;
    N* n;
    N(int x) : v(x), n(nullptr) {}
};

N* addf(N* h, int x) 
{
    N* p = new N(x);
    p->n = h;
    return p;
}

N* addl(N* h, int x) 
{
    N* p = new N(x);
    if (!h) return p;
    N* t = h;
    while (t->n) t = t->n;
    t->n = p;
    return h;
}

N* del(N* h, int x) 
{
    if (!h) return h;
    if (h->v == x) {
        N* t = h->n;
        delete h;
        return t;
    }
    N* p = h;
    while (p->n && p->n->v != x) p = p->n;
    if (p->n) {
        N* t = p->n;
        p->n = t->n;
        delete t;
    }
    return h;
}

N* rev(N* h) 
{
    N* a = nullptr;
    while (h) {
        N* b = h->n;
        h->n = a;
        a = h;
        h = b;
    }
    return a;
}

void out(N* h) 
{
    for (N* p = h; p; p = p->n) cout << p->v << ' ';
    cout << '\n';
}

int main()
{
    N* h = nullptr;
    h = addl(h, 1);
    h = addl(h, 2);
    h = addl(h, 3);
    h = addf(h, 0);
    out(h);
    h = del(h, 2);
    out(h);
    h = rev(h);
    out(h);
    return 0;
}
