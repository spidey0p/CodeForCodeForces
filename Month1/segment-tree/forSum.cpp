#include <bits/stdc++.h>

using namespace std;

struct segTree {

    int size;
    vector<long long> sums;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx) {   //vec_index, node, tree_index, leftIndex, rightIndex
        if(rx - lx == 1) {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;   // calculating mid of the range
        if(i < m) {
            //it is in left side of the tree
            //call recursion to the left sub tree
            set(i, v, 2 * x + 1, lx, m);
        } else {
            //recursion call for the right side
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v) {   // index, node
        set(i, v, 0, 0, size);
    }

    long long sum (int l, int r, int x, int lx, int rx) {
        if(lx >= r || l >= rx) return 0;   //when it is outside of the range;
        if(lx >= l && rx <= r) return sums[x] ;  // when the total range is inside of the range
        //if any portion of the range is inside then call recursion on both left and right side
        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lx, m);        //left side call
        long long s2 = sum(l, r, 2 * x + 2, m, rx);         //right side call

        return s1 + s2;
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
        int n, m;
        cin>>n>>m;

        segTree st;
        st.init(n);

        for(int i = 0; i < n; i++) {
            int v;
            cin>>v;
            st.set(i, v);
        }

        while (m--) {
            int op;
            cin>>op;
            if(op == 1) {
                int i, v;
                cin>> i >> v;
                st.set(i, v);
            } else {
                int l, r;
                cin>> l >> r;
                cout<< st.sum(l,r) << "\n";
            }
        }
    return 0;
}



/*
Testcases
5 5 
5 4 2 3 5
2 0 3
1 1 1
2 0 3
1 3 1
2 0 5


output:
11
8
14
*/