#include <iostream>
using namespace std;

void blure_words(char str[], int begin, int end)
{
	for (begin; begin < end; begin++)
	{
		str[begin] = '*';
	}
}

const char* finde_bad_words(char str[])
{
	const char* to_find[] = { "","","","",""};//fill with bad words
	int i = 0;
	int j = 0;
	int c = 0;
	while (c != 5)//c = number of bad words
	{
		while (str[i] != '\0')
		{
			while ((str[i + j] == to_find[c][j] || str[i + j] == to_find[c][j] - 32) && str[i + j] != '\0')//ignore case
				j++;
			if (to_find[c][j] == '\0')
			{
				blure_words(str, i, i + j);
				break;
			}
			i++;
			j = 0;
		}
		c++;
		i = 0;
		j = 0;
	}
	return str;
}

int main()
{	
	char str[100];
	const char * ss;
	cin.get(str, 100);

	ss = finde_bad_words(str);
	cout << ss << endl;
	return 0;
}
