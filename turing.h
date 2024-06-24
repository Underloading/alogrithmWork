#ifndef TEAM_ALGORITHM_TURING_H
#define TEAM_ALGORITHM_TURING_H

struct tuElement {
    int type;
    int num;
    std::string s;
    tuElement () {}
    tuElement (int _type, int _num, std::string _s) {
        type = _type; num = _num; s = _s;
    }
    inline void print () {
        if (type == 1) {
            std::cout << num;
        } else {
            std::cout << s;
        }
    }
};

struct TuringMachine {
    int pos;
    tuElement arr[MAXN];
    void print () {
        for (int i = 1; i <= n; i++) {

        }
    }
} turing;

#endif //TEAM_ALGORITHM_TURING_H
