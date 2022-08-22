#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int parent[10],sum=0;
vector<tuple<int, int, int>> graph;
bool cmp(tuple<int, int, int>& v1, tuple<int, int, int>& v2) {
	return get<2>(v1) < get<2>(v2);
}
int find(int x) { // 루트 노트 찾기
	if (parent[x] < 0)
		return x;
	return parent[x] = find(parent[x]);
}
bool isUnion(int a, int b) { // Discrimination Union
	int x = find(a);
	int y = find(b);
	if (x == y)
		return true;
	else
		return false;
}
void Union(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return;
	if (parent[x] <= parent[y]) {
		parent[x] += parent[y];
		parent[y] = x;
	}
	else {
		parent[y] += parent[x];
		parent[x] = y;
	}
	return;
}
int main() {
	for (int i = 1; i <= 7; i++)
		parent[i] = -1;
	
	//노드는 총 7개 간선 11개
	graph.push_back(make_tuple(1,7,10));
	graph.push_back(make_tuple(4, 7, 11));
	graph.push_back(make_tuple(1, 5, 15));
	graph.push_back(make_tuple(3, 5, 18));
	graph.push_back(make_tuple(2, 4, 22));
	graph.push_back(make_tuple(1, 4, 26));
	graph.push_back(make_tuple(3, 6, 35));
	graph.push_back(make_tuple(5, 6, 43));
	graph.push_back(make_tuple(2, 5, 60));
	graph.push_back(make_tuple(1, 2, 65));
	graph.push_back(make_tuple(5, 7, 71));

	sort(graph.begin(), graph.end(),cmp); //가중치 정렬
	
	for (int i = 0; i < graph.size(); i++) {
		if (!isUnion(get<0>(graph[i]), get<1>(graph[i]))) {
			sum += get<2>(graph[i]);
			Union(get<0>(graph[i]), get<1>(graph[i]));
		}
	}
	cout << sum << endl;
	return 0;
}
