/*
# The Prim-Jarnik Algorithm #
In the Prim-Jarnik algorithm, we grow a MST from a single cluster starting from
some "root" vertex v. The main idea is similar to that of Dijkstra's algorithm.
We begin with som vertex v, defining the initial "cloud" of vertices C. Then,
in each iteration, we choose a minimum-weight edge e = (v, u), connecting a
vertex v in the cloud C to a vertex u outside of C. The vertex u is then brought
into the cloud C and the process is repeated until a ST is formed. Again, the
crucial fact about MST comes to play, because by always choosing the smallest-
weight edge joining a vertex inside C to one outside C, we are assured of always
adding a valid edge to the MST.

Algorithm PrimJarnik(G):
Pick any vertex v of G
D[v] <- 0
for each vertex u != v do
    D[u] <- +inf
Initialize T <- {/empty set/}
Initialize a priority queue Q (heap) with an entry ((u, null) D[u]) for each vertex u,
where (u, null) is the element and D[u] is the key.
while Q is not empty do
    (u, e) <- Q.removeMin()
    Add vertex u and edge e to T
    for each vertex z adjacent to u such that z is in Q do
        {perform the relaxation procedure on edge (u, z)}
        if w((u, z)) < D[z] then
            D[z] <- w((u, z))
            Change to (z, (u, z)) the element of vertex z in Q
            Change to D[z] the key of vertex z in Q
return the tree T
*/

// Reference: https://blog.csdn.net/qq_38279908/article/details/83473010

#include<iostream>
#include<vector>

using namespace std;

void prim(vector<vector<int>> &VGraph, vector<int> &lowcost, vector<int> &closest, vector<bool> &visited)  //思路类似于迪杰斯特拉算法
{
	int size = lowcost.size();
	visited[0] = true;
	for (int i = 1; i < size; i++)
	{
		lowcost[i] = VGraph[0][i];
		closest[i] = 0;
		visited[i] = false;
	}
	cout << "0";
	int weight = 0;
	for (int i = 0; i < size; i++)
	{
		int min = 99999;
		int index = 1;
		for (int j = 0; j < size; j++)
		{
			if (lowcost[j] < min&&!visited[j])
			{
				min = lowcost[j];
				index = j;
			}
		}
		if (index == 1 && min == 99999)
		{
			cout << "\n最小生成树权值为:" << weight<<endl;
			return;
		}
		else
		{
			weight += min;
		}
		cout << " -> " << index;
		visited[index] = true;
		for (int j = 1; j <size; j++)  //因为新加入了j点,所以要查找新加入的j点到未在S中的点K中的权值是不是可以因此更小
		{
			if ((VGraph[index][j]<lowcost[j]) && (!visited[j]))  //lowcost表示从已知树到某一点所需付出的最小权值
			{ 
				lowcost[j] = VGraph[index][j];
				closest[j] = index;
			}
		}
	}
}
int main()
{
	int M, N;
	cin >>M>>N;
	vector<vector<int>> VGraph(M);
	vector<int> lowcost(M);
	vector<int> closest(M);
	vector<bool> visited(M);
	for (int i = 0; i < M; i++)
	{
		VGraph[i].resize(M);
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			VGraph[i][j] = 99999;
		}
	}
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		int length;
		cin >> length;
		VGraph[a][b] = VGraph[b][a] = length;
	}
	prim(VGraph, lowcost, closest, visited);
}