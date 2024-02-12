#include <iostream>
#include <vector>
#define n 4

using namespace std;

int main()
{
    int p[n] = {0}, bt[n] = {0}, dl[n] = {0}, res[n] = {0};
    cout << "Enter process, its burst time and deadline: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> bt[i] >> dl[i];
    }
    cout << "The processes are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " " << bt[i] << " " << dl[i] << endl;
    }
    cout << "Processes that can be completed are: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (bt[i] >= dl[j])
                // break;
                cout << "hello\n";
            res[i - 1] = p[i];
        }
        cout << "hello1\n";
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}