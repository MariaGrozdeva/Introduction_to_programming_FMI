

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int length = n * 2 + n / 2;
    int middle = n - 2;


    for (int i = 0; i < length; i++)
    {
        if ((i >= n) && (i < n + n / 2))
            cout << "  ";
        else
            cout << "* ";
    }
    cout << endl;
    
    for (int i = 0; i < middle; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (((j > 0) && (j < n - 1)) || ((j > n + n / 2) && (j < length - 1)))
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }

    for (int i = 0; i < length; i++)
    {
        if ((i >= n) && (i < n + n / 2))
            cout << "  ";
        else
            cout << "* ";
    }
}

