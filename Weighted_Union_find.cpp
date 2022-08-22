#include<iostream>
using namespace std;
int parent[10];
/*
	parent배열에서 루트노드라면 -(집합의 크기)를 저장하고
	루트노드가 아니라면 부모 노드를 저장한다
	따라서 parent 배열의 초기화는 모두 -1이다 <= 처음엔 모두 루트노드니까
*/
int find(int x) { //루트노드를 찾는다
	if (parent[x] < 0) //음수가 될때까지 찾는다 -> 음수는 루트노드이다
		return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	int a = find(x); //루트노드 a
	int b = find(y); //루트노드 b
	if (a == b) //두 루트노드가 같다면 return
		return;

	if (parent[a] <= parent[b]) { //깊이가 b가 더 깊다면 ex) -3 < -2
		parent[a] = parent[a] + parent[b]; //더 깊은 곳에 더한다
		parent[b] = a; //a는 b의 루트노드가 된다
	}
	else { //깊이가 a가 더 깊다면 a(-2) > b(-3)
		parent[b] = parent[a] + parent[b]; //깊이가 더 깊은 b에 노드들을 더한 값을 넣는다
		parent[a] = b; //b는 a의 루트노드가 된다
	}
	return;
}
bool isUnion(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x == y)
		return true;
	else
		return false;
}
int main() {
	for (int i = 1; i <= 5; i++)
		parent[i] = -1;

	merge(1, 3);
	merge(1, 4);
	for (int i = 1; i <= 5; i++)
		cout << parent[i] << " ";
	return 0;
		
}