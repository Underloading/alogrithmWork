#include<iostream>
#include<limits.h>
#include<string.h>
#include<stack>
using namespace std;
int cost[105];
int value[105];
int Time;
int n;  //记录物品种类
int mem[105][1005]; //mem[i][j] 表示在j时间内获取后i件物品
// struct Double {
//     int pos;
//     int timeLeft;
//     Double(int _pos, int _timeLeft) {
//         pos = _pos;
//         timeLeft = _timeLeft;
//     }
//     int size () {
//         return sizeof(int) * 2;
//     }
// };
// struct RecursiveSystem {
//     int maxDeep;
//     int curDeep;
//     int step;
//     stack<Double> dfs_stack;
//     void push(Double x) {
//         dfs_stack.push(x);
//         cout << "push" << endl;
//         curDeep++;
//         maxDeep = max(maxDeep, curDeep);
//     }
//     void pop() {
//         dfs_stack.pop();
//         cout << "pop" << endl;
//         curDeep--;
//     }
//     int dfs() {
//         push(Double(1, Time));
//         while(!dfs_stack.empty()) {
//             int dfs1, dfs2 = INT_MIN;
//             auto temp = dfs_stack.top();
//             if(temp.pos == n + 1) {
//                 mem[temp.pos][temp.timeLeft] = 0;
//                 pop();
//                 continue;
//             }
//             else {
//                 push(Double(temp.pos + 1, temp.timeLeft));
//                 continue;
//             }
//             //push(Double(temp.pos + 1, temp.timeLeft));
//             if(temp.timeLeft >= cost[temp.pos]) {

//             }
//         }
//     }

// };
// int main () {
    
// }












int dfs(int pos, int timeLeft) {
    if(mem[pos][timeLeft] != -1) return mem[pos][timeLeft];
    if(pos == n + 1) {
        return mem[pos][timeLeft] = 0;
    }
    //cout << "dfs(" << pos << " + 1," << timeLeft << ")" << endl;
    int dfs1, dfs2 = INT_MIN;
    dfs1 = dfs(pos + 1, timeLeft);
    //cout << "dfs(" << pos << " + 1," << timeLeft << " - " << "cost[" << pos <<"]," << "+" << "value[" << pos << "]" << endl;
    if(timeLeft >= cost[pos]) {
        dfs2 = dfs(pos + 1, timeLeft - cost[pos]) + value[pos];
    }
    return mem[pos][timeLeft] = max(dfs1, dfs2);
    
}
int main() {
    memset(mem, -1, sizeof(mem));
    cin >> Time >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i] >> value[i];
    }
    cout << dfs(1, Time);
    return 0;
}
