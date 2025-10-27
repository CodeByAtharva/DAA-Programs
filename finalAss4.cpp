#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int n;

void printMat(int **mat){
  cout<<"Matrix : "<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(mat[i][j]==INF){
        cout<<"INF"<<"  ";
      }
      else cout<<mat[i][j]<<"   ";
    }
    cout<<endl;
  }
}

void printMatStatic(int mat[][100]){
  cout<<"Matrix : "<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(mat[i][j]==INF){
        cout<<"INF"<<"  ";
      }
      else cout<<mat[i][j]<<"   ";
    }
    cout<<endl;
  }
}

void printPath(vector<int>& path){
  cout << "path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

class Node{
  public:
  int node;
  int matrix[100][100];
  int cost;
};

int findCost(int mat[100][100]){
  int reductionCost=0;
  for (int i = 0; i < n; i++) {
        int rowMin = INF;
        for (int j = 0; j < n; j++)
            if (mat[i][j] < rowMin)
                rowMin = mat[i][j];

        if (rowMin != INF && rowMin > 0) {
            reductionCost += rowMin;
        }
    }

    for (int j = 0; j < n; j++) {
        int colMin = INF;
        for (int i = 0; i < n; i++)
            if (mat[i][j] < colMin)
                colMin = mat[i][j];

        if (colMin != INF && colMin > 0) {
            reductionCost += colMin;
        }
    }

    return reductionCost;
}

int findReducedMatrix(int matrix[][100],int reduced[][100]){
  int reductionCost = 0;
  for (int i = 0; i < n; i++) {
        int rowMin = INF;
        for (int j = 0; j < n; j++)
            if (matrix[i][j] < rowMin)
                rowMin = matrix[i][j];

        if (rowMin != INF && rowMin > 0) {
            reductionCost += rowMin;
            for (int j = 0; j < n; j++)
                if (matrix[i][j] != INF)
                    reduced[i][j] =matrix[i][j]-rowMin;
                else{
                  reduced[i][j]=matrix[i][j];
                }
        }
    }

    // Column reduction
    for (int j = 0; j < n; j++) {
        int colMin = INF;
        for (int i = 0; i < n; i++)
            if (reduced[i][j] < colMin)
                colMin = reduced[i][j];

        if (colMin != INF && colMin > 0) {
            reductionCost += colMin;
            for (int i = 0; i < n; i++)
                if (reduced[i][j] != INF)
                    reduced[i][j] -= colMin;
        }
    }
    return reductionCost;

} 

void TCP(Node curr,int visited[],int reducedCost[][100],vector<int>& path){
  if(path.size() >= n){
    path.push_back(0); // return to starting node
    printPath(path);
    return;
}
  path.push_back(curr.node);
  visited[curr.node]=1;
  int leastCost=INF;
  Node leastCostNode;
  for(int i=0;i<n;i++){
    if(visited[i]==0){

      Node newNode;
      newNode.node=i;
      
      for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
          if(row==curr.node || col== i || (row==i && visited[col]==1)){
            newNode.matrix[row][col]=INF;
          }
          else{
            newNode.matrix[row][col]=curr.matrix[row][col];
          }
        }
      }

      newNode.cost=curr.cost+findCost(newNode.matrix)+reducedCost[curr.node][i];

      if(newNode.cost<leastCost && newNode.cost!=INF){
        leastCost=newNode.cost;
        leastCostNode=newNode;
      }
    }
  }

  if (leastCost != INF){
    cout<<"node :"<<leastCostNode.node<<" , ";
    cout<<"cost :"<<leastCostNode.cost<<endl;
    TCP(leastCostNode,visited,reducedCost,path);
  }
}

int main(){
    cout<<"Enter number of nodes: ";
    cin>>n;

    int matrix[100][100];
    cout<<"Enter adjacency matrix ("<<n<<"x"<<n<<") [use -1 for INF]:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            if(val==-1) matrix[i][j]=INF;
            else matrix[i][j]=val;
        }
    }

    int reduced[100][100] = {0};

    printMatStatic(matrix);
    int initialCost=findReducedMatrix(matrix,reduced);
    cout<<"Initial reduction cost: "<<initialCost<<endl;
    printMatStatic(reduced);

    Node root;
    root.node=0;
    for(int row=0;row<n;row++){
      for(int col=0;col<n;col++){
        root.matrix[row][col]=reduced[row][col];
      }
    }
    root.cost=initialCost;
    

    vector<int> path;
    int visited[100]={0};

    TCP(root,visited,reduced,path);
    printPath(path);
    
  return 0;
}
