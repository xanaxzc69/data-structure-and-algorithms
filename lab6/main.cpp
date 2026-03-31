#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<int> st;

    for (int i = 0; i < 5; i++)
        st.push(rand() % 10);

    int sum = 0, count = 0;

    while (!st.empty()) {
        int x = st.top();
        st.pop();

        if (x > 5) {
            sum += x;
            count++;
        }
    }

    if (count)
        cout << "Average >5: " << (double)sum / count << endl;

    queue<int> q;

    for (int i = 0; i < 5; i++)
        q.push(rand() % 10);

    queue<int> newQ;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x % 2 == 0)
            newQ.push(x);
    }

    cout << "New queue:\n";
    while (!newQ.empty()) {
        cout << newQ.front() << " ";
        newQ.pop();
    }

    return 0;
}
