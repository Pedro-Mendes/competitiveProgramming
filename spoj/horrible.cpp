/* https://www.spoj.com/problems/HORRIBLE/ */

#include<bits/stdc++.h>
using namespace std;

long long int tree[400100]={0};
long long int lazy[400100]={0};
/*vector<long long int> A;*/ //not this time

void build(int node, int start, int end){
    if(start == end){
        // Leaf node will have a single element
        /*tree[node] = A[start];*/ //In this exercise, we will only need zeros in tree
        tree[node] = 0;
        lazy[node] = 0;
    }else{
        long long int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end, int l, int r, long long int val){
    if(lazy[node] != 0){
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end){
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r){
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end){
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    long long int mid = (start + end) / 2;
                                               
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

long long int queryRange(int node, int start, int end, int l, int r){
    
    if(lazy[node] != 0){
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end){
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    long long int mid = (start + end) / 2;
    long long int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    long long int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

int main(){
    int n,l,r,x,t,OP,n_operations;
    long long int diff;
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n;
        /*for (int j = 0; j < n; ++j){
            cin >> x;
            A.push_back(x);
        }*/ //We will not use an input vector this time
        //build(1,0,n-1);
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        cin >> n_operations;
        for (int k = 0; k < n_operations; ++k){
            cin >> OP;
            if (OP == 0){
                cin >> l >> r >> diff;
                updateRange(1, 0, n-1, l-1, r-1, diff);
            }else{
                cin >> l >> r;
                cout << queryRange(1,0, n-1, l-1, r-1) << endl;
            }
        }

    }
return 0;
}
                           
