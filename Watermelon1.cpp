#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
ll M = 1e9 + 7;
#define oset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define omset tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

void FIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void testcases()
{
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> v(m);
	for (ll i = 0; i < m; i++)
		cin >> v[i].first >> v[i].second;

	vector<ll> ans, points(n + 1, 0);

	// Set 1st input as Default Leading Team
	ll LeadingTeam = v[0].first;
	points[LeadingTeam] = v[0].second;
	ans.push_back(LeadingTeam);

	set<pair<ll, ll>> st;
	st.insert({-v[0].second, v[0].first}); // Sorting Dessinding according to points, Realiesed now that there was no need for it to be Dessinding

	for (ll i = 1; i < m; i++)
	{
		ll curTeam = v[i].first, curPoints = v[i].second;
		pair<ll, ll> add = {-points[curTeam], curTeam};
		if (st.count(add)) // if the team exists remove it -> edit the points and re insert it
		{
			st.erase(add);
			points[curTeam] += curPoints;
			add.first = (-curPoints);
			st.insert(add);
		}
		else // else just insert it
			st.insert({-curPoints, curTeam});

		bool isLeadingTeamUpdated = 0;

		if (points[curTeam] + curPoints > points[LeadingTeam]) // added +ve points and exceeded the Leading team -> update it
			LeadingTeam = curTeam;

		else if (points[curTeam] + curPoints == points[LeadingTeam]) // added points and 2 teams are Leading -> take the min(IDs)
			LeadingTeam = min(LeadingTeam, curTeam);

		else if (curTeam == LeadingTeam and curPoints < 0) // added -ve points and the Leading team dropped in rank -> second Leading becomes Leading
		{
			pair<ll, ll> y = {-points[LeadingTeam], LeadingTeam};
			st.erase(y);
			points[LeadingTeam] += curPoints;
			st.insert({-points[LeadingTeam], LeadingTeam});
			auto it = st.begin(); // st.begin() after removing Leading : AKA Second Leading -> becomes Leading
			pair<ll, ll> z = (*it);
			LeadingTeam = z.second;
			isLeadingTeamUpdated = true; // To Avoid updating it twice
		}

		pair<ll, ll> x = {-points[curTeam], curTeam};

		if (st.count(x) != 0) // if curTeam already in set -> remove it
			st.erase(x);

		if (!isLeadingTeamUpdated) // for all exept Leading -> Update points and re insert the team with new points
		{
			points[curTeam] += curPoints;
			st.insert({-points[curTeam], curTeam});
		}
		ans.push_back(LeadingTeam); // Pushing the leading Team -> (idx + 1 ,1-based) is the round number that has (LeadingTeam) as 1st Team
	}

	reverse(ans.begin(), ans.end());

	ll i = 1;
	for (; i < m; i++)
	{
		if (ans[i] != ans[i - 1])
			break;
	}
	// Checking last run where did it start
	ll f = m - i + 1;

	if (f == 1) // if it started on the 1st day and it is the only Leading Team for all Days cout << 0
		cout << 0 << '\n';
	else // else cout The Day the last streak Started
		cout << m - i + 1 << '\n';
}

int main()
{
	FIO();
	ll tests = 1;
	cin >> tests;
	while (tests--)
		testcases();
	return 0;
}
