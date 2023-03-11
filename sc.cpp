#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 505;
int nrows, ncols;
int val[MAXN][MAXN], weight[MAXN][MAXN];

struct State {
	int x,y,weight;
	State(int x, int y, int weight) : x(x), y(y), weight(weight) {}
	bool operator< (const State& rhs) const {
		return weight > rhs.weight;
	}
};

int x_dir[4] = {-1,+1, 0, 0};
int y_dir[4] = { 0, 0,-1,+1};
bool is_valid(int x, int y) { return 0 < min(x,y) and x <= nrows and y <= ncols; }

int dist[MAXN][MAXN];
int dijkstra(int base) {
	for (int r = 1; r <= nrows; r++)
		for (int c = 1; c <= ncols; c++) {
			int tmp = val[r][c];
			weight[r][c] = 0;
			for (;tmp % base == 0; tmp /= base) ++weight[r][c];
			dist[r][c] = INF;
		}
	priority_queue<State> heap;
	heap.push(State(1,1, dist[1][1] = weight[1][1]));
	while (!heap.empty()) {
		State cur = heap.top(); heap.pop();
		if (cur.weight != dist[cur.x][cur.y]) continue;
		for (int d = 0; d < 4; d++) {
			int u = cur.x + x_dir[d], v = cur.y + y_dir[d];
			if (!is_valid(u,v)) continue;
			int relax = cur.weight + weight[u][v];
			if (relax < dist[u][v])
				dist[u][v] = relax,
				heap.push(State(u,v,relax));
		}
	}
	return dist[nrows][ncols];
}

int main()
{
	scanf("%d %d", &nrows, &ncols);
	for (int r = 1; r <= nrows; r++)
		for (int c = 1; c <= ncols; c++) scanf("%d", &val[r][c]);	
	printf("%d", min(dijkstra(2), dijkstra(5)));
}