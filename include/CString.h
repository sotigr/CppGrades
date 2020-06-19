#pragma once

#include <stdio.h>
#include <new>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>

using namespace std;

class CString
{
private:
	char *word;

public:
	CString(const char *);
	CString(const CString &);
	CString();
	~CString();

	void operator=(CString &);
	bool operator==(const CString &);
	bool operator!=(const CString &);

	const char *operator+=(const char);
	void print();
	const char *getWord();
};