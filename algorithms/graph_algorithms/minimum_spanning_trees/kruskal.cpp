/*
# Kruskal's Algorithm #
Proposition 13.24:
Let G be a weighted connected graph, and let V1 and V2 be a partition of 
the vertices of G into two disjoint nonempty sets. Furthermore, let e be
an edge in G with minimum weight from among those with one endpoint in V1
and the other in V2. There is a minimum spanning tree T that has e as one
of its edges.

In Kruskal's algorithm, it is used to build the MST in clusters. Initially,
each vertex is in its own cluster all by itself. The algorithm then considers
each edge in turn, ordered by increasing weight. If an edge e connects two
different clusters, then e is added to the set of edges of the MST, and the
two clusters connected by e are merged into a single cluster. If, on the other
hand, e connects two vertices that are already in the same cluster, then e
is discarded. Once the algorithm has added enough edges to form a ST, it
terminates and outputs the tree as the MST.

Algorithm Kruskal(G):
for each vertex v in G do
    Define an elementary cluster C(v) <- {v}
Initialize a priority queue Q (heap) to contain all edges in G,
using the weights as keys.
T <- {/empty set/} {T will ultimately contain the edges of the MST}
while T has fewer than n-1 edges do
    (u, v) <- Q.removeMin()
    Let C(v) be the cluster containing v, and let C(u) be the cluster containing u.
    if C(v) != C(u) then
        Add edge(v, u) to T.
        Merge C(v) and C(u) into one cluster, that is, union C(v) and C(u).
return tree T
*/

// Reference: https://blog.csdn.net/qq_38279908/article/details/83473589

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node { // 作为数据结构存储图
	int start;
	int end;
	int length;
};

bool compare(Node a, Node b) {
	return a.length < b.length;
}

void Kruskal(vector<Node> &arr, vector<bool> &visited) {
	int M, N;
	M = visited.size();
	N = arr.size();
	for (int i = 0; i < N; i++) {
		cin >> arr[i].start >> arr[i].end >> arr[i].length;
	}
	sort(arr.begin(), arr.end(), compare);
	int weight = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[arr[i].start] || !visited[arr[i].end]) {
			weight += arr[i].length;
			visited[arr[i].start] = true;
			visited[arr[i].end] = true;
		}
	}
	cout << "最小生成树权值为:";
	cout << weight << endl;
}
int main()
{
	int M, N;
	cin >> M >> N;
	vector<Node> arr(N);
	vector<bool> visited(M);
	Kruskal(arr, visited);
}

/*
测试用例
6 8
0 1 2
0 2 1
1 3 5
2 3 4
1 2 3
2 4 1
4 5 2
3 5 3
最小生成树权值为9
*/