#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll M = 1e9 + 7;

void FIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<ll>> sparmx, sparmn;

ll mn(ll l, ll r)
{
    ll pw = log2(r - l + 1);
    return min(sparmn[pw][l], sparmn[pw][r - (1 << pw) + 1]);
}
ll mx(ll l, ll r)
{
    ll pw = log2(r - l + 1);
    return max(sparmx[pw][l], sparmx[pw][r - (1 << pw) + 1]);
}

void testcases()
{
    ll n;
    cin >> n;
    ll lg = log2(n) + 1;
    sparmx.resize(lg, vector<ll>(n));
    sparmn.resize(lg, vector<ll>(n));
    for (ll i = 0; i < n; i++)
        cin >> sparmx[0][i];
    for (ll pw = 1; pw < lg; pw++)
        for (ll i = 0; i + (1 << pw) <= n; i++)
            sparmx[pw][i] = max(sparmx[pw - 1][i], sparmx[pw - 1][i + (1 << (pw - 1))]);

    for (ll i = 0; i < n; i++)
        cin >> sparmn[0][i];
    for (ll pw = 1; pw < lg; pw++)
        for (ll i = 0; i + (1 << pw) <= n; i++)
            sparmn[pw][i] = min(sparmn[pw - 1][i], sparmn[pw - 1][i + (1 << (pw - 1))]);
// DONE creating the sparse tabels
    ll ans = 0;
    for (ll l = 0; l < n; l++) // for each possible number
    {
        ll start = l, end = n - 1, left = -1;
        while (start <= end) // binary search for the first left bound that has min = max
        {
            ll mid = (start + end) / 2;
            ll a = mx(l, mid); // Getting the answer from the sparse
            ll b = mn(l, mid); // Getting the answer from the sparse
            if (a == b)
            {
                end = mid - 1;
                left = mid;
            }
            else if (a > b)
                end = mid - 1;
            else if (b > a)
                start = mid + 1;
        }
        if (!(left + 1))
            continue;
        ll right = -1;
        start = left, end = n - 1;

        while (start <= end) // binary search for the right bound where the streak of min = max ends
        {
            ll mid = (start + end) / 2;
            ll a = mx(l, mid);
            ll b = mn(l, mid);
            if (a == b)
            {
                start = mid + 1;
                right = mid;
            }
            else if (a > b)
                end = mid - 1;
            else
                start = mid + 1;
        }
        if (left + 1 and right + 1)
            ans += right - left + 1; // add length if found right and left boundries
    }
    cout << ans << '\n';
}
// RUNTIME ERROR DUE TO INDEXING -> I've no clue which one is it or why

int main()
{
    FIO();
    ll tests = 1;
    cin >> tests;
    while (tests--)
        testcases();
    return 0;
}

