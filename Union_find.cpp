#include<iostream>
using namespace std;
int parent[9];

int find(int x){ // <-- 트리가 한쪽으로 치우친 경우 비효율적으로 작동
    if(parent[x]==x) //배열 인덱스와 값이 같다면 해당 값 리턴
      return x;
    return parent[x]=find(parent[x]); //배열의 값을 인덱스로 갖는 값 리턴
}
int find2(int x) { // <--루트노드에 직접적으로 연결하기에 효율적으로 작동
    if (parent[x] == x)
        return x;
    else {
        int y = find(parent[x]); // 루트노드를 찾는다
        parent[x] = y;
        return y;
    }
}
void Union(int x, int y){
    x=find(x);
    y=find(y); //각각 find연산을 통해 루트 노드를 가짐
    if(x==y)
      return; //x와 y가 같다면 이미 연결되어 있음
    parent[y]=x; //배열의 y인덱스에 x값 저장
}// 이는 높이가 더 높은 트리가 높이가 낮은 트리 밑으로 들어가게 되면 트리가 깊어질
//위험이 있다. 따라서 트리의 높이가 낮은 트리가 높은 트리의 밑으로 들어가야 하는데
//이를 위해 트리의 높이를 기록해야한다.
bool isUnion(int x, int y){ //두 노드가 연결되어있는지 판별
    x=find(x);
    y=find(y);
    if(x==y)
        return true;
    return false;
}
int main(){
    for(int i=0;i<9;i++) //배열 초기화 과정
        parent[i]=i;

    Union(1,2);
    Union(4,5);
    Union(5,6);
    cout<<"2와 4는 같은 집합인가?\n"<<isUnion(2,4)<<"\n";
    Union(1,5);
    cout<<"2와 4는 같은 집합인가?\n"<<isUnion(2,4)<<"\n";
    return 0;
}