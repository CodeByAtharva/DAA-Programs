#include<iostream>
#include<cmath>
#include<limits.h>
#include<vector>
// #define INF INT_MAX
// #define n 5
// using namespace std;
// struct node{
//   int val;
//   int cost;
//   int matrix[n][n];
// };

// void printMatrix(int matrix[][n]){
//   for(int row=0;row<n;row++){
//     for(int col=0;col<n;col++){
//       if(matrix[row][col]==INF){
//         cout<<"INF ";
//       }
//       else{       
//         cout<<matrix[row][col]<<" ";
//       }
//     }
//     cout<<endl;
//   }
// }
// int findReducedMatrix(int orignalMatrix[][n],int reducedMatrix[][n]){
//   int reductionCost=0;
//   //row reduction
//   for(int row=0;row<n;row++){
//     int rowMin=INF;
//     for(int col=0;col<n;col++){
//       if(orignalMatrix[row][col]<rowMin){
//         rowMin=orignalMatrix[row][col];
//       }
//     }
//     if(rowMin!=INF && rowMin>0){
//       reductionCost+=rowMin;
//       for(int col=0;col<n;col++){
//         if(orignalMatrix[row][col]!=INF){
//           reducedMatrix[row][col]=orignalMatrix[row][col]-rowMin;
//         }
//         else{
//           reducedMatrix[row][col]=orignalMatrix[row][col];
//         }       
//       }
//     }
//   }
//   //column reduction
//   for(int col=0;col<n;col++){
//     int colMin=INF;
//     for(int row=0;row<n;row++){
//       if(reducedMatrix[row][col]<colMin){
//         colMin=reducedMatrix[row][col];
//       }
//     }
//     if(colMin!=INF && colMin>0){
//       reductionCost+=colMin;
//       for(int row=0;row<n;row++){
//         if(reducedMatrix[row][col]!=INF){
//           reducedMatrix[row][col]=reducedMatrix[row][col]-colMin;
//         }
//       }
//     }
//   }
//   return reductionCost;
// }
// int findCost(int matrix[][n]){
//   int reductionCost=0;
//   for(int row=0;row<n;row++){
//     int rowMin=INF;
//     for(int col=0;col<n;col++){
//       if(matrix[row][col]<rowMin){
//         rowMin=matrix[row][col];
//       }
//     }
//     if(rowMin!=INF && rowMin>0){
//       reductionCost+=rowMin;
//     }
//   }
//   for(int col=0;col<n;col++){
//     int colMin=INF;
//     for(int row=0;row<n;row++){
//       if(matrix[row][col]<colMin){
//         colMin=matrix[row][col];
//       }
//     }
//     if(colMin!=INF && colMin>0){
//       reductionCost+=colMin;
//     }
//   }
//   return reductionCost;
// }
// void printPath(vector<int>& path){
//   for(int i=0;i<n;i++){
//     cout<<path[i]<<" ";
//   }
//   cout<<endl;
// }
// void TSP(node curr,int reducedMatrix[][n],vector<int>& path,int visited[100]){
//   if(path.size()>=n){
//     printPath(path);
//   }

//   visited[curr.val]=1;
//   path.push_back(curr.val);
//   node leastCostNode;
//   int leastCost=INF;
//   for(int i=0;i<n;i++){
//     if(visited[i]==0){
//       node newNode;
//       newNode.val=i;
//       for(int row=0;row<n;row++){
//         for(int col=0;col<n;col++){
//           if((row==i && visited[col]==1) || row==curr.val || col==i){
//             newNode.matrix[row][col]=INF;
//           }
//           else{
//             newNode.matrix[row][col]=curr.matrix[row][col];
//           }
//         }
//       }
//       newNode.cost=findCost(newNode.matrix)+curr.cost+reducedMatrix[curr.val][i];

//       if(newNode.cost!=INF && newNode.cost<leastCost){
//         leastCost=newNode.cost;
//         leastCostNode=newNode;
//       }
//     }
//   }
//   if(leastCost!=INF){
//     cout<<"node :"<<leastCostNode.val<<"  cost :"<<leastCost<<endl;
//     TSP(leastCostNode,reducedMatrix,path,visited);
//   }
// }
// int main(){
//   int matrix[n][n] = {
//         {INF, 20,30,10,11},
//         {15, INF, 16, 4, 2},
//         {3, 5, INF, 2, 4},
//         {19, 6, 18, INF, 3},
//         {16, 4, 7, 16, INF}
//     };
//     printMatrix(matrix);
//     cout<<endl<<endl;
//     int reducedMatrix[n][n]={0};
//     int initialCost=findReducedMatrix(matrix,reducedMatrix);
//     printMatrix(reducedMatrix);
//     cout<<initialCost<<endl<<endl;

//     node root;
//     root.val=0;
//     for(int row=0;row<n;row++){
//       for(int col=0;col<n;col++){
//         root.matrix[row][col]=reducedMatrix[row][col];
//       }
//     }
//     root.cost=initialCost;


//     vector<int> path;
//     int visited[n];
//     for(int i=0;i<n;i++){
//       visited[i]=0;
//     }

//     TSP(root,reducedMatrix,path,visited);
//     printPath(path);
//   return 0;
// }
#define n 4
#define INF INT_MAX
using namespace std;
struct node{
  int val;
  int cost;
  int matrix[n][n];
};
void printMatrix(int matrix[n][n]){
  for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
      if(matrix[row][col]!=INF){
        cout<<matrix[row][col]<<" ";
      }
      else{
        cout<<"INF ";
      }
    }
    cout<<endl;
  }
}
void printPath(vector<int> path){
  for(int i=0;i<path.size();i++){
    cout<<path[i]<<"->";
  }
  cout<<path[0]<<endl;
}
int findCost(int matrix[n][n]){
  int reductioncost=0;
  for(int row=0;row<n;row++){
    int rowMin=INF;
    for(int col=0;col<n;col++){
      if(matrix[row][col]<rowMin){
        rowMin=matrix[row][col];
      }
    }
    if(rowMin!=INF && rowMin>0){
      reductioncost+=rowMin;
    }
  }
  for(int col=0;col<n;col++){
    int colMin=0;
    for(int row=0;row<n;row++){
      if(matrix[row][col]<colMin){
        colMin=matrix[row][col];
      }
    }
    if(colMin!=INF && colMin>0){
      reductioncost+=colMin;
    }
  }
  return reductioncost;
}
int findReducedMatrix(int matrix[n][n],int reduced[n][n]){
  int reductioncost=0;
  for(int row=0;row<n;row++){
    int rowMin=INF;
    for(int col=0;col<n;col++){
      if(matrix[row][col]<rowMin){
        rowMin=matrix[row][col];
      }
    }
    if(rowMin!=INF && rowMin>0){
      reductioncost+=rowMin;
      for(int col=0;col<n;col++){
        if(matrix[row][col]==INF){
          reduced[row][col]=INF;
        }
        else{
          reduced[row][col]=matrix[row][col]-rowMin;
        }
      }
    }
  }
  for(int col=0;col<n;col++){
    int colMin=INF;
    for(int row=0;row<n;row++){
      if(reduced[row][col]<colMin){
        colMin=reduced[row][col];
      }
    }
    if(colMin!=INF && colMin>0){
      reductioncost+=colMin;
      for(int row=0;row<n;row++){
        if(reduced[row][col]!=INF){
          reduced[row][col]=reduced[row][col]-colMin;
        }
      }
    }
  }
  return reductioncost;
}
void TSP(node curr,int reduced[n][n],int visited[n],vector<int>& path){
  if(path.size()>=n){
    printPath(path);
  }

  visited[curr.val]=1;
  path.push_back(curr.val);
  int leastCost=INF;
  node leastCostNode;
  for(int i=0;i<n;i++){
    if(visited[i]==0){
      node newNode;
      newNode.val=i;
      
      for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
          if((row==i && visited[col]==1) || row==curr.val || i==col){
            newNode.matrix[row][col]=INF;
          }
          else{
            newNode.matrix[row][col]=curr.matrix[row][col];
          }
        }
      }

      newNode.cost=curr.cost+findCost(newNode.matrix)+reduced[curr.val][i];

      if(newNode.cost!=INF && newNode.cost<leastCost){
        leastCost=newNode.cost;
        leastCostNode=newNode;
      }
    }
  }
  if(leastCost!=INF){
    cout<<"current node :"<<leastCostNode.val<<endl;
    cout<<"currrent cost "<<leastCostNode.cost<<endl;
    cout<<endl;
    TSP(leastCostNode,reduced,visited,path);
  }
}
int main(){
  int matrix[n][n] = {
        {INF,16,11,6},
        {8, INF,13,16},
        {4,7, INF, 9},
        {5,12,2, INF},
    };
    int reduced[n][n]={0};
    cout<<"orignal matrix :"<<endl;
    printMatrix(matrix);

    int initialcost=findReducedMatrix(matrix,reduced);
    cout<<"reduced Matrix :"<<endl;
    printMatrix(reduced);
    cout<<initialcost;

    node root;
    root.val=0;
    for(int row=0;row<n;row++){
      for(int col=0;col<n;col++){
        root.matrix[row][col]=reduced[row][col];
      }
    }
    root.cost=initialcost;


    int visited[n];
    for(int i=0;i<n;i++){
      visited[i]=0;
    }
    vector<int> path;
    
    TSP(root,reduced,visited,path);
    printPath(path);
  return 0;
}
