#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> data;
	int i = 0;

	while (1)
	{
		int num;
		cin >> num;

		data.push_back(num);

		if (data[i] == -1)
		{
			break;
		}
		i++;
	}

	sort(data.begin(), data.end());

	copy(data.begin(), data.end(), ostream_iterator<char>(cout, " "));

	return 0;
}