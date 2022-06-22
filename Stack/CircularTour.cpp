#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int i = 0;
    int j = 1;
    int balance = p[i].petrol - p[i].distance;
    cout << balance;
    while (i != j || balance < 0)
    {
        while (balance < 0 && i != j)
        {
            balance -= p[i].petrol - p[i].distance;
            i = (i + 1) % n;
            if (i == 0)
                return -1;
        }
        balance += p[j].petrol - p[j].distance;
        j = (j + 1) % n;
        cout << balance;
    }
    return i;
}