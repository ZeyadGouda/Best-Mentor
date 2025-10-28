#include <iostream>
using namespace std;
int main()
{
	long long id; cin >> id;
	bool pal = false;
	long long rev = 0,checkpoint = id, digits = 0;
	while (id != 0)
	{
		digits +=1;
		id /= 10;
	}
	id = checkpoint;
	for (int j = 1; j <= digits; j++)
	{
		if (j == 1)	rev = rev + (id % 10);
		else rev = rev*10 + (id % 10);
		id = id / 10;
		if (id == rev)
		{
			pal = true;
			break;
		}
	}
	id = checkpoint;
	long long sum = 0;
	for (long long i = 1; i <= digits; i++)
	{
		if (id != 0)
		{
			long long x = id % 10;
			id /= 10;
			sum = sum + x;
		}
	}
	cout << sum << endl;
	cout << pal << endl;
	if (id % sum == 0 && pal == true)
		cout << "Best mentor.";
	else if (id % sum != 0 && pal == true)
		cout << "He's good.";
	else if (id % sum == 0 && pal == false)
		cout << "He's good.";
	else
		cout << "He'll be fired.";
		return 0;
}