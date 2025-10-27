#include<iostream>
#include<cmath>
using namespace std;

int x[20];

bool place(int k,int n){

    for(int i=1;i<=k-1;i++){
        if(x[i]==n || abs(x[i]-n)==abs(i-k)){
            return false;
        }
    }
    return true;


}

void NQ(int k,int n){

    for(int i=1;i<=n;i++){ //Iterate through Each Column to check whether the queen is placable or not
        if(place(k,i)){
            x[k]=i;
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