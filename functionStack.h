#ifndef TEAM_ALGORITHM_FUNCTIONSTACK_H
#define TEAM_ALGORITHM_FUNCTIONSTACK_H

struct Function {
    std::string name;

};

struct funcStack {
    std::string name;
    std::vector <int> vec;
    funcStack () {}
    funcStack (std::string _name, std::vector <int> _vec) {
        name = _name;
        for (auto x : _vec)
            vec.push_back (x);
    }
    inline void print () {
        std::cout << name << "( ";
        for (int i = 0; i < vec.size (); i++) {
            if (i == vec.size () - 1) {
                std::cout << vec[i] << " )";
            } else {
                std::cout << vec[i] << ", ";
            }
        }
    }
    inline int memSize () {
        return sizeof (int) * vec.size ();
    }
    inline int len () {

    }
};

#endif //TEAM_ALGORITHM_FUNCTIONSTACK_H
