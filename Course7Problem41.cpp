#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

string ReadString()
{
	string UserString = "";
	cout << "Enter your string:\n";
	getline(cin , UserString);
	return UserString;
}

vector <string> SplitString(string UserString , string Delem)
{

	short Pos = 0;
	string Word = "";
	vector<string> vWords;

	while ((Pos = UserString.find(Delem)) != std :: string :: npos)
	{

		Word = UserString.substr(0, Pos);

		if (Word != " ")
		{
			vWords.push_back(Word);
		}

		UserString.erase(0, Pos + Delem.length());

	}

	if (UserString != "")
	{
		vWords.push_back(UserString);
	}

	return vWords;
}

string ReverseString(string UserString)
{

	vector <string> vWords;

	string ReversedString = "";

	vWords = SplitString(UserString , " ");

	vector <string>::iterator iter = vWords.end();

	while (iter != vWords.begin())
	{
		iter--;
		ReversedString += *iter + " ";
		
	}
	
	return ReversedString.substr(0 , ReversedString.length() - 1);

}

int main()
{
	string UserString = ReadString();

	cout << "Reversed string:\n";
	cout << ReverseString(UserString);
	
	return 0;
}

