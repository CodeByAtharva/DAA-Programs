#include<iostream>
#include<cmath>
using namespace std;
void printMatrix(int matrix[],int n){
  for(int i=0;i<n;i++){
    cout<<matrix[i]<<" ";
  }
  cout<<endl;
}
void merge(int profit[],int weight[],int left,int mid,int right){
  int m=mid-left+1;
  int n=right-mid;
  int profitleft[m];
  int profitright[n];
  int weightleft[m];
  int weightright[n];
  int index=left;
  for(int i=0;i<m;i++){
    profitleft[i]=profit[index];
    weightleft[i]=weight[index];
    index++;
  }
  for(int i=0;i<n;i++){
    profitright[i]=profit[index];
    weightright[i]=weight[index];
    index++;
  }
  int i=0,j=0,k=left;
  while(i<m && j<n){
    float price1=profitleft[i]/weightleft[i];
    float price2=profitright[j]/weightright[j];
    if(price1>price2){
      profit[k]=profitleft[i];
      weight[k]=weightleft[i];
      i++;
    }
    else{
      profit[k]=profitright[j];
      weight[k]=weightright[j];
      j++;
    }
    k++;
  }
  while(i<m){
    profit[k]=profitleft[i];
      weight[k]=weightleft[i];
      i++;
      k++;
  }
  while(j<n){
    profit[k]=profitright[j];
    weight[k]=weightright[j];
    j++;
    k++;
  }
  
}
void mergeSort(int profit[],int weight[],int left,int right){
  if(left<right){
    int mid=(left+right)/2;
    mergeSort(profit,weight,left,mid);
    mergeSort(profit,weight,mid+1,right);
    merge(profit,weight,left,mid,right);
  }
}
int main(){
  int n;
  cout<<"Enter the no. of products :";
  cin>>n;
  int profit[n];
  int weight[n];
  int capacity;
  for(int i=0;i<n;i++){
    cout<<"Product No. :"<<i+1<<endl;
    cout<<"Enter the profit:";
    cin>>profit[i];
    cout<<"Enter the weight :";
    cin>>weight[i];
  }
  mergeSort(profit,weight,0,n-1);
  cout<<"sorted Profit Matrix :"<<endl;
  printMatrix(profit,n);
  cout<<"sorted weight Matrix :"<<endl;
  printMatrix(weight,n);




  cout<<"Enter the knapsack capacity :";
  cin>>capacity;

  int u=capacity;
  float x[n];
  for(int i=0;i<n;i++){
    x[i]=0;
  }
  int maxprofit=0;
  int i=0;
  for(i=0;i<n;i++){
    if(u>=weight[i]){
      u-=weight[i];
      x[i]=1;
      maxprofit+=profit[i];
    }
    else{
      break;
    }
  }
  if(i<n){
    x[i]=u/(float)weight[i];
    maxprofit+=profit[i]*x[i];
  }
  cout<<"Maximum Profit :"<<maxprofit<<endl;
  cout<<"Resultant array :"<<endl;
  for(int i=0;i<n;i++){
    cout<<x[i]<<" ";
  }
  return 0;
}