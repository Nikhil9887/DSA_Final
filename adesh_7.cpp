#include <iostream>
using namespace std;

class Node
{
public:
    int path;
    int weight;

    Node()
    {
        path = 0;
        weight = 0;
    }
};

class graph
{
public:
    int ne;
    int nv;
    Node **arr;

    graph()
    {
        cout << "enter the number of the vertices ";
        cin >> nv;
        cout << "enter the number of the edges ";
        cin >> ne;

        arr = new Node *[nv + 1];

        for (int i = 0; i < nv + 1; i++)
        {
            arr[i] = new Node[nv + 1];
        }
    }

    void input()
    {
        int s, d;
        int w;
        for (int i = 0; i < ne; i++)
        {
            cout << "\nenter the source and destination : ";
            cin >> s >> d;

            cout << "enter the weight of " << s << "  " << d;
            cin >> w;

            arr[s][d].path = 1;
            arr[d][s].path = 1;

            arr[s][d].weight = w;
            arr[d][s].weight = w;
        }
    }

    void prims()
    {
        int total_weight = 0;
        bool visited[nv + 1] = {false};
        int edg = 0;

        int x, y;
        visited[1] = true;
        while (edg < nv - 1)
        {
            int min = 999;
            for (int i = 0; i <= nv; i++)
            {

                if (visited[i])
                {
                    for (int j = 0; j <= nv; j++)
                    {
                        if (!visited[j] && arr[i][j].path == 1)
                        {
                            if (arr[i][j].weight < min)
                            {
                                x = i;
                                y = j;
                                min = arr[i][j].weight;
                            }
                        }
                    }
                }
            }
            cout << x << "->" << y << "   " << arr[x][y].weight << endl;
            visited[y] = true;
            total_weight = total_weight + arr[x][y].weight;

            edg++;
        }

        cout << " total of minimum spanning tree is : " << total_weight << endl;
    }
};

int main()
{
    graph g;

    g.input();
    g.prims();
    return 0;
}

// 1 2 4 2 4 1 4 6 7 6 5 4 5 3 2 3 1 5 2 3 3 4 5 6