#include <stdio.h>
#include <new>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>
#include <cstring>

#include "CString.h"

using namespace std;

CString::~CString()
{
	delete[] word;
}

CString::CString(const char *w)
{
	int l = strlen(w);
	word = new char[l];
	strcpy(word, w);
}

CString::CString(const CString &c)
{
	int l = strlen(c.word);
	word = new char[l];
	strcpy(word, c.word);
}

CString::CString()
{
	int l = strlen("");
	word = new char[l];
	strcpy(word, "");
}

void CString::operator=(CString &c)
{
	word = c.word;
}

bool CString::operator==(const CString &c)
{
	if (c.word == word)
	{
		cout << "equal" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool CString::operator!=(const CString &c)
{
	if (c.word != word)
	{
		cout << "not equal" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

const char *CString::operator+=(const char c)
{
	char *temp;
	int l = strlen(word);
	temp = new char[l];
	strcpy(temp, word);
	word = new char[l + 1];
	strcpy(word, temp);
	word[l] = c;
	return word;
}

const char *CString::getWord()
{
	return word;
}

void CString::print()
{
	cout << getWord() << endl;
}

vector<CString *> *CString::split(const char *delimiters)
{
	vector<CString *> *v = new vector<CString *>();

	char *temp = new char[strlen(word)];
		
	strcpy(temp, word);
	
	char *piece = strtok(temp, delimiters);

	strcpy(temp, piece);
	v->push_back(new CString(temp));

	piece = strtok(NULL, delimiters);
	while (piece != NULL)
	{
		strcpy(temp, piece);
		v->push_back(new CString(temp));
		piece = strtok(NULL, delimiters);
	}

	return v;
}
