#include <bits/stdc++.h>
using namespace std;

void printSet(const vector<pair<int, int>>& s, int i)
{
    cout << "S^" << i << " = { ";
    for (const auto& p : s)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << "}" << endl;
}

void solveKnapsack(const vector<int>& profits, const vector<int>& weights, int capacity)
{
    int n = profits.size();
    vector<vector<pair<int, int>>> all_states(n + 1);

    all_states[0].push_back({0, 0});
    printSet(all_states[0], 0);

    for (int i = 0; i < n; ++i)
    {
        int current_profit = profits[i];
        int current_weight = weights[i];
       
        vector<pair<int, int>> new_states;

        for (const auto& state : all_states[i])
        {
            if(state.second + current_weight <= capacity) new_states.push_back({state.first + current_profit, state.second + current_weight});
        }

        all_states[i+1] = all_states[i];
        all_states[i+1].insert(all_states[i+1].end(), new_states.begin(), new_states.end());

        sort(all_states[i+1].begin(), all_states[i+1].end());

        vector<pair<int, int>> purged_states;
        if (!all_states[i+1].empty())
        {
            purged_states.push_back(all_states[i+1][0]);
            for (size_t j = 1; j < all_states[i+1].size(); ++j)
            {
                if(all_states[i+1][j].first > purged_states.back().first) purged_states.push_back(all_states[i+1][j]);
            }
        }
        all_states[i+1] = purged_states;
        printSet(all_states[i+1], i + 1);
    }
   
    cout << "\n--- Knapsack Solution ---\n";

    auto best_solution = all_states[n].back();
    int max_profit = best_solution.first;
    int total_weight = best_solution.second;

    cout << "Max Profit: " << max_profit << endl;
    cout << "Total Weight: " << total_weight << endl;

    vector<int> items_taken(n, 0);
    int current_profit = max_profit;
    int current_weight = total_weight;

    for (int i = n - 1; i >= 0; --i)
    {
        int prev_profit = current_profit - profits[i];
        int prev_weight = current_weight - weights[i];

        bool predecessor_exists = false;
        for(const auto& state : all_states[i])
        {
            if(state.first == prev_profit && state.second == prev_weight)
            {
                predecessor_exists = true;
                break;
            }
        }
       
        if(predecessor_exists)
        {
            items_taken[i] = 1;
            current_profit = prev_profit;
            current_weight = prev_weight;
        }
    }
   
    cout << "Items taken (1 = yes, 0 = no): { ";
    for(int i = 0; i < n; ++i) cout << items_taken[i] << (i == n - 1 ? "" : ", ");
    cout << " }" << endl;
}

int main()
{
    int i,capacity,n,temp;
    cout<<"Enter Capacity = ";
    cin>>capacity;
    cout<<"n = ";
    cin>>n;
    vector<int> profits,weights;
    cout<<"Enter Profits:"<<endl;
    for(i=0;i<n;i++)
    {
    cin>>temp;
    profits.push_back(temp);
    }
    cout<<"Enter Weights:"<<endl;
    for(i=0;i<n;i++)
    {
    cin>>temp;
    weights.push_back(temp);
    }
   
    cout<<"Knapsack Capacity:"<<capacity<<endl;
    cout<<"Items (profit, weight):"<<endl;
    for(i=0;i<n;i++) cout<<"{"<<profits[i]<<","<<weights[i]<<"}"<<endl;
   
    solveKnapsack(profits, weights, capacity);
    return 0;
}