// Job Sequencing Problem
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int id;
    float weight;
    float profit;
    float ratio;
};
int main()
{
    // job sequenceing problem
    int n = 5;
    int Bucket_Capacity = 50;
    int Profit = 0;

    Item items[n];
    items[0].id = 1;
    items[1].id = 2;
    items[2].id = 3;
    items[3].id = 4;
    items[4].id = 5;
    items[0].profit = 5;
    items[1].profit = 17;
    items[2].profit = 7;
    items[3].profit = 4;
    items[4].profit = 1;
    items[0].weight = 10;
    items[1].weight = 30;
    items[2].weight = 20;
    items[3].weight = 40;
    items[4].weight = 50;
    // sort the items according to profit

    for (int i = 0; i < n; i++)
    {
        items[i].ratio = items[i].profit / items[i].weight;
    }
    sort(items, items + n, [](Item a, Item b)
         { return a.ratio > b.ratio; });
    for (int i = 0; i < n; i++)
    {
        if (Bucket_Capacity > 0)
        {
            if (Bucket_Capacity - items[i].weight >= 0)
            {
                Bucket_Capacity -= items[i].weight;
                // cout << items[i].id << " ";
                Profit += items[i].profit;
            }
            else
            {
                // cout << items[i].id << " ";
                Profit += (items[i].weight / (items[i].weight - Bucket_Capacity)) * items[i].profit;
                Bucket_Capacity = 0;
            }
        }
    }
    cout << "\n"
         << Profit;
}
