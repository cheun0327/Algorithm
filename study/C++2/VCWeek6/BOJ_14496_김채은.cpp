
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

struct Node {
	int nodenum;
	int dist;
  Node(): nodenum(0), dist(0) {}
	Node(int n, int d): nodenum(n), dist(d) {}
};

struct cmp {
    bool operator()(Node n, Node m){
        return n.dist > m.dist;
    }
};

int a, b;
int N, M;
vector<vector<int> > edge;
priority_queue<Node, vector<Node>, cmp> pq;

vector<int> dist;
vector<bool> visit;

void find_shortest_path(int start) {
  Node n;
  pq.push(Node(start, 0));
  dist[start] = 0;

  while(!pq.empty()) {
    n = pq.top();
    pq.pop();
    visit[n.nodenum] = true;

    for(int i = 0; i < edge[n.nodenum].size(); i++) {
      if(!visit[edge[n.nodenum][i]]) {
        if(dist[edge[n.nodenum][i]] > n.dist + 1) {
          dist[edge[n.nodenum][i]] = n.dist + 1;
          pq.push(Node(edge[n.nodenum][i], n.dist + 1));
        }
      }
    }
  }
}

int main() {
  int tmp1, tmp2;

  scanf("%d %d", &a, &b);
  scanf("%d %d", &N, &M);
  edge.resize(N + 1);
  dist.assign(N + 1, INF);
  visit.assign(N + 1, false);

  for(int i = 0; i < M; i++) {
    scanf("%d %d", &tmp1, &tmp2);
    edge[tmp1].push_back(tmp2);
    edge[tmp2].push_back(tmp1);
  }

  find_shortest_path(a);

  if(dist[b] == INF)
    printf("-1\n");
  else
    printf("%d\n", dist[b]);
}
