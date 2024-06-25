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
    inline int size () {
        if (type == 2) {
            return s.size ();
        } else {
            int temp = num;
            int ret = 0;
            if (num == 0)
                ret = 1;
            while (num) {
                num /= 10;
                ret++;
            }
            num = temp;
            return ret;
        }
    }
};

struct TuringMachine {
    int pos;
    int cnt;
    int moveTot;
    tuElement arr[MAXN];
    void insertNum (int x) {
        this->cnt++;
        this->pos = this->cnt;
        moveTot++;
        this->arr[cnt] = tuElement (1, x, "");
        this->print ();
    }
    void insertChar (char x) {
        this->cnt++;
        this->pos = this->cnt;
        moveTot++;
        std::string tempS;
        tempS += x;
        this->arr[cnt] = tuElement (0, 0, tempS);
        this->print ();
    }
    void erase () {
        this->cnt--;
        this->print ();
    }
    void print () {
        int l = 1, r = 1;
        for (int i = 1; i <= cnt; i++) {
            r += arr[i].size () + 3;
            if (pos == i) {
                int mid = (l + r) >> 1;
                for (int j = l; j <= mid - 1; j++)
                    std::cout << "_";
                std::cout << "v";
                for (int j = mid + 1; j <= r; j++)
                    std::cout << "_";
            } else {
                for (int j = l; j <= r; j++) {
                    std::cout << "_";
                }
            }
            l = r + 1;
        }
        std::cout << std::endl;
        for (int i = 1; i <= cnt; i++) {
            std::cout << "| ";
            if (this->arr[i].type == 1) {
                std::cout << this->arr[i].num;
            } else {
                std::cout << this->arr[i].s;
            }
            std::cout << " ";
        }
        std::cout << "|";
        std::cout << std::endl;
        for (int i = 1; i <= r; i++)
            std::cout << "-";
        std::cout << std::endl;
    }
    int binSearch (int x) {
        int L, R;
        this->pos = n + 2;
        moveTot++;
        this->print ();
        L = arr[this->pos].num;
        this->pos = n + 3;
        moveTot++;
        this->print ();
        R = arr[this->pos].num;
        this->insertChar ('$');
        this->insertNum ((L + R) >> 1);
        while (L <= R) {
            this->pos = n + 2;
            moveTot++;
            this->print ();
            L = arr[this->pos].num;
            this->pos = n + 3;
            moveTot++;
            this->print ();
            R = arr[this->pos].num;
            int mid = (L + R) >> 1;
            this->erase ();
            this->insertNum (mid);
            this->pos = mid;
            moveTot++;
            this->print ();
            if (arr[this->pos].num == x) {
                this->print ();
                return this->pos;
            } else if (arr[this->pos].num < x) {
                this->pos = n + 2;
                moveTot++;
                arr[this->pos].num = mid + 1;
                this->print ();
            } else {
                this->pos = n + 3;
                moveTot++;
                arr[this->pos].num = mid - 1;
                this->print ();
            }
        }
        return -1;
    }
} turing;

#endif //TEAM_ALGORITHM_TURING_H
