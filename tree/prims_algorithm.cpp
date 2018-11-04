#include <iostream>
#define MAX 50000

using namespace std;

int
minkey (int key[], bool mstset[])
{
    int min = MAX, min_index;
    for (int b = 0; b < 5; b++)
      {
          if (mstset[b] == false && key[b] < min)
              min = key[b], min_index = b;
      }
    return min_index;
}
int
printmst (int parent[], int n, int graph[5][5])
{
    cout << "Edge Weight\n";
    for (int i = 1; i < 5; i++)
        cout << parent[i] << "-" << i << " " << graph[i][parent[i]] << endl;
}

void
primmst (int graph[5][5])
{
    int parent[5];              //Array to store constructed MST
    int key[5];                 //Key values used to pick minimum weight edge
    bool mstset[5];             //To represent vertices not yet included in MST

    for (int i = 0; i < 5; i++)
      {
          key[i] = MAX;
          mstset[i] = false;
      }
    key[0] = 0;                 // Make key 0 for the source vertex

    parent[0] = -1;             //First node is always root of MST
    for (int count = 0; count < 5 - 1; count++)
      {
          int u = minkey (key, mstset);
          mstset[u] = true;
          for (int b = 0; b < 5; b++)
            {
                if (graph[u][b] && mstset[b] == false && graph[u][b] < key[b])
                  {
                      parent[b] = u;
                      key[b] = graph[u][b];
                  }
            }
      }
    printmst (parent, 5, graph);
}
int
main ()
{

    int graph[5][5] = { {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
    };

    primmst (graph);
    return 0;
}
