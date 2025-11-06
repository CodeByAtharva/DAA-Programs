/*#include<iostream>
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
    if(weight[i]<=u){
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

*/

#include<iostream>
#include<cmath>

void merge(float p[],float w[],int low,int mid,int high){

  int l=low;
  int r=mid+1;
  int k=0;
  float resP[high-low+1];
  float resW[high-low+1];

  while(l<=mid && r<=high){
    if((p[l]/w[l]) > (p[r]/w[r])){
        resP[k]=p[l];
        resW[k]=w[l];
        l++;
    }else{
       resP[k]=p[r];
        resW[k]=w[r];
        r++;
    }
    k++;
  }

  while(l<=mid){
        resP[k]=p[l];
        resW[k]=w[l];
        l++;
        k++;
  }

  while(r<=high){
        resP[k]=p[r];
        resW[k]=w[r];
        r++;
        k++;
  }

  for(int i=0;i<k;i++){
    p[low+i]=resP[i];
    w[low+i]=resW[i];
  }

}

void mergeSort(float p[],float w[],int low,int high){

  int mid=(low+high)/2;
  if(low>=high) return;
  mergeSort(p,w,low,mid);
  mergeSort(p,w,mid+1,high);

  merge(p,w,low,mid,high);

}


using namespace std;

int main(){

  int n;
  cout<<"\nEnter the no of Products:";
  cin>>n;

  float profit[n];
  float weight[n];

  float x[n];
  int m;
  cout<<"Enter capacity of the Knapsack:";
  cin>>m;


  cout<<"\nEnter the Profit for Each Item:";
  for(int i=0;i<n;i++){
    cout<<"\nProfit of Item"<<i+1<<":";
    cin>>profit[i];
  }

  cout<<"\nEnter the Weight for Each Item:";
  for(int i=0;i<n;i++){
    cout<<"\nWeight of Item"<<i+1<<":";
    cin>>weight[i];
  }


  mergeSort(profit,weight,0,n-1);

  cout<<"\n\nProfit";
  for(int i=0;i<n;i++){
    cout<<profit[i]<<" ";
  }
  cout<<"\n\nWeight";
  for(int i=0;i<n;i++){
    cout<<weight[i]<<" ";
  }

/*
    int n = 3;
    float weight[] = {10, 20, 30};
    float profit[] = {60, 100, 120};
    float m = 50;  // Capacity
    float x[10];
    
    for(int i=0;i<n;i++){
      x[i]=0;
      }*/
     int i=0;
     int u=m;
     float maxP=0;

     for(int i=0;i<n;i++){
      x[i]=0;
     }
  for(i=0;i<n;i++){
    if(weight[i]<=u){
      u=u-weight[i];
      x[i]=1;
      maxP+=profit[i];
    }else{
      break;
    }
  }

  if(i<n){
    x[i]=u/(float)weight[i];
    maxP+=x[i]*profit[i];
  }

  cout<<"\n\n\nMax Profit is:"<<maxP<<"\n\n\n";

  for(int i=0;i<n;i++){
    cout<<x[i]<<" ";
  }


}