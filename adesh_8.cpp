#include <iostream>
using namespace std;

class pair_data
{
public:
    int first;
    int second;
    pair_data()
    {
        first = 0;
        second = 0;
    }
};
class node
{

public:
    int data;
    node *left, *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class OBST
{
public:
    node *root;
    pair_data **m;
    int size;
    OBST(int n)
    {
        root = NULL;
        size = n;
        m = new pair_data *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            m[i] = new pair_data[n + 1];
        }
    }

    void create()
    {
        int n = size;
        pair_data arr[n];

        for (int i = 0; i < n; i++)
        {
            cout << "enter the element you want to add" << endl;
            cin >> arr[i].first;
            cout << "enter the frequency" << endl;
            cin >> arr[i].second;
        }

        for (int l = 0; l < n + 1; l++) // its a variable not the root
        {
            for (int i = 0; i < n + 1; i++)
            {
                for (int j = 0; j < n + 1; j++)
                {
                    if ((j - i) == l)
                    {
                        m[i][j] = cost(i, j, arr);
                    }
                }
            }
        }

        make(root, arr, 0, n);
    }

    pair_data cost(int i, int j, pair_data v[])
    {
        if (i == j)
        {
            pair_data o;
            return o;
        }
        int l1 = cost(i, i, v).first + cost(i + 1, j, v).first; // remeber first calculating cost for k =i+1 i.e for first root
        int root = i + 1;
        for (int k = i + 2; k <= j; k++)
        {
            int l2 = cost(i, k - 1, v).first + cost(k, j, v).first;

            if (l2 < l1)
            {
                l1 = l2;
                root = k;
            }
        }
        int weight = 0;
        for (int w = i; w < j; w++) // starting from i to less than j as starting from 0,   nahitar fromi <w<=j
        {
            weight += v[w].second;
        }
        pair_data o;
        o.first = l1 + weight;
        o.second = root;

        return o;
    }

    void printer()
    {
        for (int i = 0; i < size + 1; i++)
        {
            for (int j = 0; j < size + 1; j++)
            {
                cout << m[i][j].first << "-" << m[i][j].second << "\t";
            }
            cout << endl;
        }
    }

    void make(node *&root, pair_data arr[], int i, int j)
    {
        if (i == j)
        {
            return;
        }
        root = new node(arr[m[i][j].second - 1].first);

        int k = m[i][j].second;
        make(root->left, arr, i, k - 1);
        make(root->right, arr, k, j);
    }

    void inorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};
int main()
{

    OBST obj(4);
    obj.create();
    obj.printer();
    obj.inorder(obj.root);
    return 0;
}

// 10 4 20 2 30 6 40 3