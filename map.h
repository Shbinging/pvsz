#pragma once
#include "object.h"
#include "diag.h"
#include "config.h"


using namespace std;
struct node{
    int x, y;
    object* p;
    node(int x, int y, object* q){
        this->x = x;
        this->y = y;
        p = q;
    }
    node();
};


class MAP {
private:
    vector<node> g;
    int maxX, maxY;
public:
    MAP(int xx, int yy) {
        maxX = xx;
        maxY = yy;
        g.clear();
    }
    void clear() {
        g.clear();
    }
    vector<object*> getListAll() {
        vector<object*> f;
        For(i, 0, int(g.size()) - 1)
            if (!g[i].p->isDead()) f.push_back(g[i].p);
        return f;
    }

    vector<node> getList(int xx, int yy) {
        vector<node> f;
        f.clear();
        For(i, 0, int(g.size()) - 1) {
            if (!g[i].p->isDead() && g[i].p->getLocation().x == xx && g[i].p->getLocation().y == yy) f.push_back(g[i]);
        }
        return f;
    }
    vector<node> getlList(int xx, int yy) {
        vector<node> f;
        f.clear();
        For(i, 0, int(g.size()) - 1) {
            if (!g[i].p->isDead() && g[i].p->getLocation().x == xx && g[i].p->getLocation().y <= yy) f.push_back(g[i]);
        }
        return f;
    }
    bool isList(int xx, int yy) {
        vector<node> f;
        f.clear();
        For(i, 0, int(g.size()) - 1) {
            if (!g[i].p->isDead() && g[i].p->getLocation().x == xx && g[i].p->getLocation().y == yy) f.push_back(g[i]);
        }
        return f.size();
    }
    bool push(int xx, int yy, object* q) {
        if (xx < 1 || xx > maxX || yy <0 || yy > maxY) return 0;
        else {
            g.push_back(node(xx, yy, q));
            return 1;
        }
    }
    bool push(object* q){
        int xx = q->getLocation().x, yy = q->getLocation().y;
        g.push_back(node(xx, yy, q));
        return 1;
    }
};

