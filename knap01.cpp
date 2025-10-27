#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

struct PW {
    double p;
    double w; 
};


int Largest(vector<PW>& pair, vector<double>& w, int t, int h, int i, double m) {
    int u = h;
    while (u >= t && pair[u].w + w[i] > m) {
        u--;
    }
    return u;
}
void TraceBack(vector<double>& p, vector<double>& w, vector<PW>& pair, 
               vector<int>& x, double m, int n, vector<int>& b) {
    double currentProfit = pair[b[n] - 1].p;
    double currentWeight = pair[b[n] - 1].w;
    
    for (int i = n - 1; i >= 0; i--) {
        x[i] = 0;
        
        for (int j = b[i]; j < b[i + 1]; j++) {
            if (abs(pair[j].p - currentProfit) < 1e-9 && 
                abs(pair[j].w - currentWeight) < 1e-9) {
           
                break;
            }
            if (abs(pair[j].p + p[i] - currentProfit) < 1e-9 && 
                abs(pair[j].w + w[i] - currentWeight) < 1e-9) {
         
                x[i] = 1;
                currentProfit = pair[j].p;
                currentWeight = pair[j].w;
                break;
            }
        }
    }
}

double DKnap(vector<double>& p, vector<double>& w, vector<int>& x, int n, double m) {
    vector<PW> pair(1000); 
    vector<int> b(n + 2);
    
    b[0] = 1;
    pair[1].p = 0.0;
    pair[1].w = 0.0;
    
    int t = 1, h = 1;
    int next = 2;
    b[1] = next;
    
    for (int i = 0; i < n; i++) {
  
        int k = t;
        int u = Largest(pair, w, t, h, i, m);
        
        for (int j = t; j <= u; j++) {
           
            double pp = pair[j].p + p[i];
            double ww = pair[j].w + w[i];
            
            while ((k <= h) && (pair[k].w < ww)) {
                pair[next].p = pair[k].p;
                pair[next].w = pair[k].w;
                next++;
                k++;
            }
            
            if (k <= h && pair[k].w == ww) {
                pp = max(pp, pair[k].p);
                k++;
            }
            
            if (pp > pair[next - 1].p) {
                pair[next].p = pp;
                pair[next].w = ww;
                next++;
            }
            
            while ((k <= h) && (pair[k].p <= pair[next - 1].p)) {
                k++;
            }
        }
        
        while (k <= h) {
            pair[next].p = pair[k].p;
            pair[next].w = pair[k].w;
            next++;
            k++;
        }
        
        t = h + 1;
        h = next - 1;
        b[i + 1] = next;
    }
    
    TraceBack(p, w, pair, x, m, n, b);
    
    return pair[b[n] - 1].p;
}


void printSolution(vector<double>& p, vector<double>& w, vector<int>& x, 
                  double maxProfit, int n, double capacity) {
    cout << "DKnap Algorithm Solution" << endl;
    cout << "========================" << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Number of items: " << n << endl << endl;
    
    cout << "Items:" << endl;
    cout << "Index\tProfit\tWeight\tSelected" << endl;
    cout << "-----\t------\t------\t--------" << endl;
    
    double totalWeight = 0.0;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << p[i] << "\t" << w[i] << "\t";
        if (x[i] == 1) {
            cout << "1";
            totalWeight += w[i];
        } else {
            cout << "0";
        }
        cout << endl;
    }
    
    cout << endl << "Results:" << endl;
    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Total Weight: " << totalWeight << endl;
    cout << "Capacity Used: " << (totalWeight / capacity) * 100 << "%" << endl;
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
    printSolution(p, w, x, maxProfit, n, capacity);

    return 0;
}