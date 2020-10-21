#include "../../std_lib_facilities.h"

namespace unideb {

int my_find(vector<string>, string, int);
int my_find(vector<string>, string);

}

namespace bme {

int my_find(vector<string>, string, int);
int my_find(vector<string>, string);

}

int main()
{
	vector<string> words = {"apple", "pear", "grapes", "lemon", "orange"};
	string s = "grapes";
	int index = unideb::my_find (words, s);

	if (index > 0) 
		cout << "Found at index: " << index << endl;
	else 
		cout << "Not found\n";

	return 0;
}

namespace unideb {

int my_find(vector<string> vs, string s, int hint)
{
	cout << "unideb my_find\n";
	if (hint < 0 || vs.size() <= hint) hint = 0;
	for (int i = hint; i < vs.size(); ++i)
		if(vs[i]==s) return i;
	if (0<hint){
		for (int i = 0; i < hint; ++i)
			if (vs[i]==s) return i;
	}
	return -1;
}

int my_find(vector<string> vs, string s)
{
	cout << "unideb my_find\n";
	for (int i = 0; i < vs.size(); ++i)
		if (vs[i]==s) return i;
	return -1;
}

}

namespace bme {

int my_find(vector<string> vs, string s, int hint)
{
	cout << "bme my_find\n";
	if (hint < 0 || vs.size() <= hint) hint = 0;
	for (int i = hint; i < vs.size(); ++i)
		if(vs[i]==s) return i;
	if (0<hint){
		for (int i = 0; i < hint; ++i)
			if (vs[i]==s) return i;
	}
	return -1;
}

int my_find(vector<string> vs, string s)
{
	cout << "bme my_find\n";
	for (int i = 0; i < vs.size(); ++i)
		if (vs[i]==s) return i;
	return -1;
}

}