#include "BSTTemplate.h"
int main(void)
{
	BST<string, char> MorseTree;
	MorseTree.print();

	fstream toConvert("Convert.txt", std::ios::in);

	while (!toConvert.eof())
	{
		char FromFile[100] = { '\0' };
		toConvert.getline(FromFile, 100);
		int count = 0;
		while (FromFile[count] != '\0')
		{
			if (FromFile[count] == ' ')
			{
				cout << "   ";
			}
			else if (FromFile[count] == '\n')
			{
				cout << endl;
			}
			else if(isalpha(FromFile[count]))
			{
				cout << MorseTree.search(toupper(FromFile[count]));
			}
			++count;
		}
		cout << '\n';
	}

	toConvert.close();

	return 0;
}