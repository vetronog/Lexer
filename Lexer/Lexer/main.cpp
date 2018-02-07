#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Lexer.h"
using namespace std;

void Print(vector<string> & tokens, vector<string> & tokenTypes)
{
	for (size_t it = 0; it < tokens.size(); ++it)
	{
		cout << "Token type is \"" << tokenTypes[it] << "\"" << endl;
		cout << "Token value is \"" << tokens[it] << "\"" << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
}

int main(int argc, char * argv[])
{
	try
	{ 
		if (argc < 2)
		{
			throw logic_error("Invalid arguments count");
		}
		ifstream input(argv[1]);
		string str;
		CLexer lexer;
		while (getline(input, str))
		{
			lexer.FindTokens(str);
			Print(lexer.GetTokens(), lexer.GetTokenTypes());
		}
		cout << "Token type is \"" << EOF_TOKEN << "\"" << endl;
		cout << "Token value is \"" << "" << "\"" << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
	catch (exception & err)
	{
		cout << err.what() << endl;
	}

	return 0;
}
