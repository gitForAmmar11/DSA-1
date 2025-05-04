#include<bits/stdc++.h>
using namespace std;

int graph[4][4] = {0,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0};

void bfs(int start){
    int color [4]={0};   ////color = 0 means white
    color [start]=1;    //color = 1 means gray

    queue<int> Q;
    Q.push(start);

    while(!Q.empty()){

        int u= Q.front();
    Q.pop();

    for(int i=0; i<4; i++){
        if(graph[u][i]==1 && color[i]==0){
            Q.push(i);
        }
    }

    color[u]=2;
    cout << u <<"  ";
    }
    cout << endl;
}

int main(){

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout <<graph[i][j] <<"  ";
        }
        cout << endl <<endl;
    }
    cout << endl;

    bfs(0);

    return 0;
}
