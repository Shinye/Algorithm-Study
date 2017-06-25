#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_V = 52;
const int INF = 1000000000;

// 정점 문자를 0~51 사이의 번호로 바꿔주는 간단한 함수
inline int CtoI(char c){
    if(c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main(){
    int N; // 간선 개수
    int c[MAX_V][MAX_V] = {0}; // c[i][j]: i에서 j로 가는 간선의 용량
    int f[MAX_V][MAX_V] = {0}; // f[i][j]: i에서 j로 현재 흐르는 유량
    vector<int> adj[MAX_V]; // 인접 리스트

    // 간선 정보 입력받기
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        char u, v;
        int w;
        scanf(" %c %c %d", &u, &v, &w);
        u = CtoI(u); v = CtoI(v);
        c[u][v] += w; // 같은 간선이 여러 번 들어올 수 있으므로 +=
        adj[u].push_back(v);
        adj[v].push_back(u); // 역방향 간선도 추가해줘야 함
    }

    // total: 총 유량, S: 소스, E: 싱크
    int total = 0, S = CtoI('A'), E = CtoI('Z');
    // 증가 경로를 못 찾을 때까지 루프
    while(1){
        // 증가 경로를 BFS로 찾음
        int prev[MAX_V];
        fill(prev, prev+MAX_V, -1);
        queue<int> Q;
        Q.push(S);

        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();
            for(int next: adj[curr]){
                // c[i][j]-f[i][j] > 0: i에서 j로 유량을 흘릴 여유가 남았는가?
                // prev[next] == -1: next 정점을 아직 방문하지 않았는가?
                if(c[curr][next]-f[curr][next] > 0 && prev[next] == -1){
                    Q.push(next);
                    prev[next] = curr; // 경로를 기억하기 위해 prev 배열 사용
                    if(next == E) break; // 싱크에 도달하면 나옴
                }
            }
        }
        // 싱크로 가는 경로가 더 없으면 루프 탈출
        if(prev[E] == -1) break;

        // 경로상에서 가장 허용치가 낮은 곳을 찾음
        int flow = INF;
        for(int i=E; i!=S; i=prev[i])
            flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
        // 찾은 flow만큼 해당 경로에 유량 흘려줌
        for(int i=E; i!=S; i=prev[i]){
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        // 총 유량 값 증가
        total += flow;
    }
    // 결과 출력
    printf("%d\n", total);
}
