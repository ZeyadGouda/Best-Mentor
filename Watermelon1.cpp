#include <bits/stdc++.h>
using namespace std;

void FIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

using ll = long long;
#define M 1000000007

bool prime(int n)
{
	bool x = 1;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			x = 0;
			break;
		}
	}
	return x;
}

void testcases(set<int> &primes)
{
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	// vector<pair<int, int>> primecnt;

	for (int i = 0; i < v.size(); i++)
		cin >> v[i];

	vector<pair<int, int>> pref(v.size());
	pref[0].first = 0;
	pref[0].second = (primes.count(v[0]));
	for (int i = 1; i < v.size(); i++)
	{
		if (primes.count(v[i]))
		{
			pref[i].second = pref[i - 1].second + 1;
			pref[i].first = i;
		}
		else
		{
			pref[i].second = pref[i - 1].second;
			pref[i].first = i;
		}
	}

	// pref{index of prime,prefix}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		int x = 0, y = pref[r].second;
		if (l - 1 >= 0)
			x = pref[l - 1].second;
		auto h = primes.upper_bound(y - x);
		if (y - x > 0)
			if (h == primes.begin())
				cout << -1 << '\n';
			else
			{
				h--;
				cout << *h << '\n';
			}
		else
			cout << -1 << '\n';

		// if (((pref[r].second - ((l - 1 > 0) ? pref[l - 1].second : 0)) > 0)
		// 	cout << pref[r].second - ((l - 1 > 0) ? pref[l - 1].second : 0);
		// else
		// 	cout << -1 << '\n';
	}
	/*
	1
	4 1
	2 3 7 5
	1 4
	*/
	// l = 2,r = 7 -> ans = 4

	// for (int i = 0; i < pref.size(); i++)
	// 	cout << pref[i].second << ' ';
	// cout << '\n';
	// for (int i = 0; i < pref.size(); i++)
	// 	cout << pref[i].first << ' ';
	// cout << '\n';

	// pref[0].first = 0;
	// pref[0].second = primecnt[0].second;
	// for (int i = 1; i < v.size(); i++)
	// {
	// 	pref[i].second = pref[i - 1].second + primecnt[i].second;
	// 	pref[i].first = primecnt[i].first;
	// 	while (primecnt[i + 1].first != primecnt[i].first + 1)
	// 	{
	// 		pref[i].second = pref[i - 1].second;
	// 		pref[i].first = i;
	// 		i++;
	// 	}
	// }

	// while (q--)
	// {
	// 	int l, r;
	// 	cin >> l >> r;
	// 	// r = (lower_bound(v.begin(), v.end(), r) != v.begin() - 1) ? *lower_bound(v.begin(), v.end(), r) : *(v.begin());
	// 	// l = (lower_bound(v.begin(), v.end(), l) != v.begin() - 1) ? *lower_bound(v.begin(), v.end(), l) : *(v.begin());
	// 	// cout << ((pref[r] - ((l - 1 > 0) ? pref[l - 1] : 0)) > 0) ? pref[r] - ((l - 1 > 0) ? pref[l - 1] : 0) : -1 << '\n';
	// 	if ((pref[pref[r].first].second - ((l - 1 > 0) ? pref[pref[l - 1].first].second : 0)) > 0)
	// 		cout << pref[pref[r].first].second - ((l - 1 > 0) ? pref[pref[l - 1].first].second : 0) << '\n';
	// 	else
	// 		cout << -1 << '\n';
	// }

	/*
	2
1
4 1
2 3 7 5
1 4
	4 2
	5 2 1 3
	*/
}
int main()
{
	FIO();
	int tests = 1;
	cin >> tests;
	set<int> primes;
	for (int i = 2; i <= 1e5; i++)
		if (prime(i))
			primes.insert(i);

	while (tests--)
		testcases(primes);
	return 0;
}
// it's already O(t*q) -> 1e10 -> not by choice
// will it work? Let's see :)
