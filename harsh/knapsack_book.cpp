#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

// struct PW {
//     double p;
//     double w; 
// };


// int Largest(vector<PW>& pair, vector<double>& w, int t, int h, int i, double m) {
//     int u = h;
//     while (u >= t && pair[u].w + w[i] > m) {
//         u--;
//     }
//     return u;
// }
// void TraceBack(vector<double>& p, vector<double>& w, vector<PW>& pair, 
//                vector<int>& x, double m, int n, vector<int>& b) {
//     double currentProfit = pair[b[n] - 1].p;
//     double currentWeight = pair[b[n] - 1].w;
    
//     for (int i = n - 1; i >= 0; i--) {
//         x[i] = 0;
        
//         for (int j = b[i]; j < b[i + 1]; j++) {
//             if (abs(pair[j].p - currentProfit) < 1e-9 && 
//                 abs(pair[j].w - currentWeight) < 1e-9) {
           
//                 break;
//             }
//             if (abs(pair[j].p + p[i] - currentProfit) < 1e-9 && 
//                 abs(pair[j].w + w[i] - currentWeight) < 1e-9) {
         
//                 x[i] = 1;
//                 currentProfit = pair[j].p;
//                 currentWeight = pair[j].w;
//                 break;
//             }
//         }
//     }
// }

// double DKnap(vector<double>& p, vector<double>& w, vector<int>& x, int n, double m) {
//     vector<PW> pair(1000); 
//     vector<int> b(n + 2);
    
//     b[0] = 1;
//     pair[1].p = 0.0;
//     pair[1].w = 0.0;
    
//     int t = 1, h = 1;
//     int next = 2;
//     b[1] = next;

    
//     for (int i = 0; i < n; i++) {
  
//         int k = t;
//         int u = Largest(pair, w, t, h, i, m);
        
//         for (int j = t; j <= u; j++) {
           
//             double pp = pair[j].p + p[i];
//             double ww = pair[j].w + w[i];
            
//             while ((k <= h) && (pair[k].w < ww)) {
//                 pair[next].p = pair[k].p;
//                 pair[next].w = pair[k].w;
//                 next++;
//                 k++;
//             }
            
//             if (k <= h && pair[k].w == ww) {
//                 pp = max(pp, pair[k].p);
//                 k++;
//             }
            
//             if (pp > pair[next - 1].p) {
//                 pair[next].p = pp;
//                 pair[next].w = ww;
//                 next++;
//             }
            
//             while ((k <= h) && (pair[k].p <= pair[next - 1].p)) {
//                 k++;
//             }
//         }
        
//         while (k <= h) {
//             pair[next].p = pair[k].p;
//             pair[next].w = pair[k].w;
//             next++;
//             k++;
//         }
        
//         t = h + 1;
//         h = next - 1;
//         b[i + 1] = next;
//     }
    
//     TraceBack(p, w, pair, x, m, n, b);
    
//     return pair[b[n] - 1].p;
// }


// void printSolution(vector<double>& p, vector<double>& w, vector<int>& x, 
//                   double maxProfit, int n, double capacity) {
//     cout << "DKnap Algorithm Solution" << endl;
//     cout << "========================" << endl;
//     cout << "Capacity: " << capacity << endl;
//     cout << "Number of items: " << n << endl << endl;
    
//     cout << "Items:" << endl;
//     cout << "Index\tProfit\tWeight\tSelected" << endl;
//     cout << "-----\t------\t------\t--------" << endl;
    
//     double totalWeight = 0.0;
//     for (int i = 0; i < n; i++) {
//         cout << i + 1 << "\t" << p[i] << "\t" << w[i] << "\t";
//         if (x[i] == 1) {
//             cout << "1";
//             totalWeight += w[i];
//         } else {
//             cout << "0";
//         }
//         cout << endl;
//     }
    
//     cout << endl << "Results:" << endl;
//     cout << "Maximum Profit: " << maxProfit << endl;
//     cout << "Total Weight: " << totalWeight << endl;
//     cout << "Capacity Used: " << (totalWeight / capacity) * 100 << "%" << endl;
// }

/*
struct pw{
    double p;
    double w;
};
int largest(vector<pw>& pair,vector<double>& w,int h,int t,int i,int m){
    int u=h;
    while(u>=t && pair[u].w+w[i]>m){
        u--;
    }
    return u;
}
void TraceBack(vector<pw>& pair,vector<double>& p,vector<double>& w,vector<int>& x,vector<int> b,int n,int m){
    double currentProfit=pair[b[n]-1].p;
    double currentWeight=pair[b[n]-1].w;

    for(int i=n-1;i>=0;i--){
        x[i]=0;
        for(int j=b[i];j<b[i+1];j++){
            if(abs(pair[j].p-currentProfit)<1e-9 && 
                abs(pair[j].w-currentWeight)<1e-9){
                    break;
            }
            if(abs(pair[j].p+p[i]-currentProfit)<1e-9 && 
                abs(pair[j].w+w[i]-currentWeight)<1e-9){
                    x[i]=1;
                    currentProfit = pair[j].p;
       currentWeight = pair[j].w;
                    break;
                }
        }
    }
}
double DKnap(vector<double>& p,vector<double>& w,vector<int>& x,int n,int m){
    vector<pw> pair(1000); //storees all the possible states
                            //pair stores all possible states (weight, profit) as the algorithm progresses.
                            //It is declared with 1000 elements to hold multiple states.
    vector<int> b(n+2);
    //b is a boundary index array.
    //It marks where the states of each iteration start and end.
    pair[1].p=0.0;
    pair[1].w=0.0;
    b[0]=1;

    int t=1,h=1;
    int next=2;
    b[1]=next;

    for(int i=0;i<n;i++){
        int k=t;
        int u=largest(pair,w,h,t,i,m);

        for(int j=t;j<=u;j++){
            double pp=p[i]+pair[j].p;
            double ww=w[i]+pair[j].w;

            while(k<=h && pair[k].w<ww){
                pair[next].p=pair[k].p;
                pair[next].w=pair[k].w;
                next++;
                k++;
            }
            if(k<=h && ww==pair[k].w){
                pp=max(pp,pair[k].p);
                k++;
            }
            if(pp>pair[next-1].p){
                pair[next].p=pp;
                pair[next].w=ww;
                next++;
            }
            while(k<=h && pair[k].p<=pair[next-1].p){
                k++;
            }
        }
        while(k<=h){
            pair[next].p=pair[k].p;
            pair[next].w=pair[k].w;
            k++;
            next++;
        }
        t=h+1;
        h=next-1;
        b[i+1]=next;

    }
    TraceBack(pair,p,w,x,b,n,m);
    return pair[b[n]-1].p;
}
int main() {
    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<double> p(n), w(n);
    cout << "Enter profits of items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Profit of item " << i + 1 << ": ";
        cin >> p[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> w[i];
    }

    vector<int> x(n, 0); 
    
    double maxProfit = DKnap(p, w, x, n, capacity);
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        cout<<x[i]<<"  ";
    }

    return 0;
}*/















// int Largest(vector<PW>& pair, vector<double>& w, int t, int h, int i, double m) {
//     int u = h;
//     while (u >= t && pair[u].w + w[i] > m) {
//         u--;
//     }
//     return u;
// }

/*


 while(k<=h && pair[k].w<ww){
                pair[next].p=pair[k].p;
                pair[next].w=pair[k].w;
                next++;
                k++;
            }
            if(k<=h && ww==pair[k].w){
                pp=max(pp,pair[k].p);
                k++;
            }
            if(pp>pair[next-1].p){
                pair[next].p=pp;
                pair[next].w=ww;
                next++;
            }
            while(k<=h && pair[k].p<=pair[next-1].p){
                k++;
            }
*/

struct pw{
    int p;
    int w;
};

int largest(vector<pw>pair,vector<int>w,int start,int end,int i,int m){
    int u=start;

    while(u>=start && pair[u].w +w[i]>m){
        u--;
    }

    return u;
}

int Dknap(vector<int>p,vector<int>w,vector<int>res,int n,int m){

    vector<pw> pair(1000);
    vector<int> b(n+2);

    pair[1].p=0;
    pair[1].w=0;

    int start,end,next;
    start=1;
    end=1;
    next=2;
    
    b[0]=1; //mark the start of the first stage
    b[1]=next; 
    //Item 0 states start at 1
    //The next available index (for future states) is 2


    for(int i=0;i<n;i++){


        int k=start;
        int u=largest(pair,w,start,end,i,m);

        for(int j=start;j<=u;j++){
            int pp=pair[i].p+pair[j].p;
            int ww=pair[i].w+pair[j].w;

            while(k<=end && pair[k].w>=ww){
                pp=max(pp,pair[k].p);
                k++;
            }

        }



    }



    
}

int main(){
    int n;
    int capacity;

    cout<<"Enter the number of Items:";
    cin>>n;

    cout<<"Enter the capacity of the Knapsack:";
    cin>>capacity;

    vector<int> p(n),w(n);

    cout<<"Enter the Profit of an Items";
    for(int i=0;i<n;i++){
        cout<<"\nItem"<<i+1<<":";
        cin>>p[i];
    }

    cout<<"Enter the Weight of an Items";
    for(int i=0;i<n;i++){
        cout<<"\nItem"<<i+1<<":";
        cin>>w[i];
    }

    vector<int> res(n,0);

    int profit=Dknap(p,w,res,n,capacity);


    return 0;
}
