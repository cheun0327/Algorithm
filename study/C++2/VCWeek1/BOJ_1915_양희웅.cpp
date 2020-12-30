#include <iostream>

#define MIN(x, y)   ( (x)<(y)?(x):(y) )

using namespace std;

int arr[1010][1010] {};
int n, m;

void input(void)
{
    char line[1010];

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++) {
            arr[i][j + 1] = line[j] - 48;
        }
    }
}

void solve(void)
{
    int max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] != 0) {
                arr[i][j] = MIN(arr[i - 1][j - 1], MIN(arr[i - 1][j], arr[i][j - 1])) + 1;
                if (max < arr[i][j]) {
                    max = arr[i][j];
                }
            }
        }
    }
 
    cout << max * max << endl;
}

int main(void)
{
    input();
    solve();

    return 0;
}