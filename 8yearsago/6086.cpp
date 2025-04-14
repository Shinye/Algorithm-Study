<iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, f;
string u, v;


struct MaximumFlow {
   struct Edge
   {
       int to;
       int capacity;
       Edge *reverse;
       Edge(int to, int capacity) :to(to), capacity(capacity) {};
   };

   int n;
   int source;
   int sink;
   vector<vector<Edge*>> graph;
   MaximumFlow(int n, int source, int sink) :n(n), source(source), sink(sink)
   { graph.resize(n); };

   void add_Edge(int u, int v, int capacity)
   {
       Edge *ori = new Edge(v, capacity);
       Edge *reverse = new Edge(u, 0);
       ori->reverse = reverse;
       reverse->reverse = ori;
       graph[u].push_back(ori);
       graph[v].push_back(reverse);
   }
   int bfs()
   {
       vector <bool> check(n, false);
       vector <pair<int, int>> from(n, make_pair(-1, -1));
       queue <int> q;
       q.push(source);
       check[source] = true;
       while (!q.empty())
       {
           int x = q.front();
           q.pop();
           for (int i = 0; i < graph[x].size(); i++)
           {
               int y = graph[x][i]->to;
               if (graph[x][i]->capacity > 0 && check[y] == 0)
               {
                   q.push(y);
                   check[y] = true;
                   from[y] = make_pair(x, i);
               }
           }
       }

       if (check[sink] == 0)
       {
           return 0;
       }
       int s = sink;
       int c = graph[from[s].first][from[s].second]->capacity;
       while (from[s].first != -1)
       {
           if (c > graph[from[s].first][from[s].second]->capacity)
           {
               c = graph[from[s].first][from[s].second]->capacity;
           }
           s = from[s].first;
       }
       s = sink;
       while (from[s].first != -1)
       {
           Edge *e = graph[from[s].first][from[s].second];
           e->capacity -= c;
           e->reverse->capacity += c;
           s = from[s].first;
       }
       return c;
   }
   int flow()
   {
       int ans = 0;
       while (1)
       {
           int f = bfs();

           if (f == 0) { break; }
           ans += f;
       }
       return ans;
   }
};

int node(string s)
{
   if (s[0] >= 'A'&&s[0] <= 'Z')
       return s[0] - 'A';
   else
       return s[0] - 'a' + 26;
}
int main() {
   cin >> n;
   MaximumFlow mf(52, 0, 'Z' - 'A');
   for (int i = 0; i < n; i++)
   {
       cin >> u >> v >> f;
       int p1, p2;
       p1 = node(u);
       p2 = node(v);
       mf.add_Edge(p1, p2, f);
       mf.add_Edge(p2, p1, f);
   }
   cout << mf.flow() << endl;
}
