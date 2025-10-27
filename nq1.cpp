#include<iostream>
#include<cmath>
using namespace std;

int x[20];

//i is the current column, Used to compare the new queen’s position (k, i) with every previously placed queen (j, x[j])
//k is the current row number
//n is the current column number
bool place(int k,int n){

    for(int i=1;i<=k-1;i++){
        if(x[i]==n || abs(x[i]-n)==abs(i-k)){ //same column or same diagonal
            return false;
        }
    }
    return true;
}

void NQ(int k,int n){

    for(int i=1;i<=n;i++){ //Iterate through Each Column to check whether the queen is placable or not
        if(place(k,i)){
            x[k]=i; // if it is placable then add that inside the solution array i.e. x[]
            if(k==n){
                cout<<"\n";
                for(int i=1;i<=n;i++){
                    cout<<x[i]<<",";
                }
            }else{
                NQ(k+1,n);
            }

        }


    }

}

int main(){
int n;

cout<<"Enter the no of Queens:";
cin>>n;

NQ(1,n);
return 0;

}