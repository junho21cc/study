#include <iostream>

using namespace std;

int main()
{
	int str[26] = { 0, }, i = 0;

	char in[10];
	cin >> in;

	while (1)
	{
		if (i > 10)
		{
			break;
		}
		if (in[i] <= 'Z' && in[i] >= 'A')
		{
			str[in[i] - 'A']++;
		}
		else if (in[i] <= 'z' && in[i] >= 'a')
		{
			str[in[i] - 'a']++;
		}
		i++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << (char)(i + 65) << ": " << str[i] << endl;
	}

	return 0;
}