#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(vector<vector<int>> &allocation, vector<vector<int>> &max, vector<int> &available, int n, int m)
{
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    vector<bool> finish(n, false);
    vector<int> work = available;
    vector<int> safeSequence;

    while (safeSequence.size() < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; i < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    safeSequence.push_back(i);
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "The system is not in a safe state." << endl;
            return false;
        }
    }

    cout << "The system is in a safe state." << endl;
    cout << "Safe sequence is: ";
    for (auto &pid : safeSequence)
    {
        cout << pid + 1 << " ";
    }
    cout << endl;
    return true;
}

int main()
{
    int n, m;
    cout << "Enter the number of processes and resources: ";
    cin >> n >> m;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<int> available(m);

    cout << "Enter the allocation matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the allocation for process " << i + 1 << ": ";
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
        }
        cout << endl;
    }

    cout << "Enter the max matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the max for process " << i + 1 << ": ";
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
        cout << endl;
    }
    cout << "Enter the available resources for available matrix: ";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }
    cout << endl;
}