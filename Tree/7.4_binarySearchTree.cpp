// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nl cout << "\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define f(a, b, c) for (int a = b; a < c; a++)
#define cin(vec, n) \
    f(i, 0, n) { cin >> vec[i]; }
#define int long long
const int N = 2e5 + 10;
const int M = 1e9 + 7;
class Tree
{
public:
    int root;
    Tree *left;
    Tree *right;
    Tree(int n)
    {
        root = n;
        left = nullptr;
        right = nullptr;
    }
};
class binarytree
{
public:
    Tree *troot;
    binarytree()
    {
        troot = nullptr;
    }

    Tree *insert(Tree *node, int val)
    {
        if (node == nullptr)
            return (new Tree(val));
        else if (node->root > val)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }
    void preorder_tra(Tree *tree)
    {

        Tree *tmp = tree;
        if (tmp == nullptr)
            return;
        cout << tmp->root << " ";
        preorder_tra(tmp->left);
        preorder_tra(tmp->right);
    }
};
void solve(void)
{
    binarytree tree;
    tree.troot = tree.insert(tree.troot, 2);
    tree.insert(tree.troot, 8);
    tree.insert(tree.troot, 1);
    tree.insert(tree.troot, 4);
    tree.insert(tree.troot, 3);
    tree.insert(tree.troot, 5);
    tree.insert(tree.troot, 6);
    tree.preorder_tra(tree.troot);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}