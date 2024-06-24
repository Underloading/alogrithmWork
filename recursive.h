#ifndef __RECURSIVE_H
#define __RECURSIVE_H

struct Triple {
    int x, y, z;
    Triple () {}
    Triple (int _x, int _y, int _z) {
        x = _x; y = _y; z = _z;
    }
    inline int size () {
        return sizeof (int) * 3;
    }
    inline void print () {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

struct RecursiveSystem {
    int maxDeep, curDeep;
    int allstep;
    std::stack <Triple> stk;
    inline int Room () {
        return stk.size () * Triple ().size ();
    };
    inline void push (Triple x) {
        stk.push (x);
        curDeep++;
        maxDeep = std::max (maxDeep, curDeep);
        std::cout << "push";
        x.print ();
        std::cout << std::endl;
    }
    inline void pop () {
        stk.pop ();
        curDeep--;
        std::cout << "pop" << std::endl;
    }
    int execute (int x) {
        push (Triple (1, n, x));
        while (!stk.empty ()) {
            auto temp = stk.top ();
            pop ();
            int mid = (temp.x + temp.y) >> 1;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] > x) {
                push (Triple (temp.x, mid - 1, x));
            } else {
                push (Triple (mid + 1, temp.y, x));
            }
        }
        std::cout << "maxStep = " << maxDeep << std::endl;
        return -1;
    }
} sys;

#endif