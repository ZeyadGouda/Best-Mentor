#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void FIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void testcases()
{
	double n;
	cin >> n;
	int r, p, s;
	cin >> r >> p >> s;
	string play;
	cin >> play;
	ll points = 0;
	int r1 = r, p1 = p, s1 = s;
	for (int i = 0; i < play.size(); i++)
	{
		if (play[i] == 'R')
		{
			if (p1 > 0)
			{
				points++;
				p1--;
			}
			else if (r1 > 0)
			{
				r1--;
			}
			else if (s1 > 0)
				s1--;
		}
		if (play[i] == 'P')
		{
			if (s1 > 0)
			{
				points++;
				s1--;
			}
			else if (p1 > 0)
			{
				p1--;
			}
			else if (r1 > 0)
				r1--;
		}
		if (play[i] == 'S')
		{
			if (r1 > 0)
			{
				points++;
				r1--;
			}
			else if (s1 > 0)
			{
				s1--;
			}
			else if (p1 > 0)
				p1--;
		}
	}

	p1 = p, r1 = r, s1 = s;

	if (points >= ceil(n / 2))
	{
		cout << "YES\n";
		for (int i = 0; i < play.size(); i++)
		{
			if (play[i] == 'R')
			{
				if (p1 > 0)
				{
					cout << 'P';
					p1--;
				}
				else if (r1 > 0)
				{
					cout << 'R';
					r1--;
				}
				else if (s1 > 0)
				{
					s1--;
					cout << 'S';
				}
			}
			if (play[i] == 'P')
			{
				if (s1 > 0)
				{
					cout << 'S';
					s1--;
				}
				else if (p1 > 0)
				{
					cout << 'P';
					p1--;
				}
				else if (r1 > 0)
				{
					cout << 'R';
					r1--;
				}
			}
			if (play[i] == 'S')
			{
				if (r1 > 0)
				{
					cout << 'R';
					r1--;
				}
				else if (s1 > 0)
				{
					cout << "S";
					s1--;
				}
				else if (p1 > 0)
				{
					cout << 'P';
					p1--;
				}
			}
		}
		cout << '\n';
	}
	else
		cout << "NO\n";
}

int main()
{
	FIO();
	int tests = 1;
	cin >> tests;
	while (tests--)
		testcases();
	return 0;
}
