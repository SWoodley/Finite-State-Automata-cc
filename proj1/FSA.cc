#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "FSA.h"
using namespace std;

// 1-param constructor reads FSA data from input stream
FSA::FSA(ifstream &ifs)
{
	//determine alphabet
	string alphabet;
	ifs >> alphabet;
	for (char ch: alphabet)
		sigma.push_back(ch);

	//determine number of states, starting and accepting states
	ifs >> num_states;
	ifs >> start_state;
	int num_accepts;
	for (int n = 0; n < num_accepts; n++) {
		int st;
		ifs >> st;
		accept_states.push_back(st);
	{

	//show status using helper function
	get_state_table(ifs);
	
}

//populate state table
void FSA::get_state_table(ifstream &ifs)
{

	//row of state table, initialized as a row of zeros
	vector<int> table_row(sigma.size());

	//we first add a row of zeros, because C++ used 0-based
	//indexing and our state table is 1-based
	state_table.push_back(table_row);

	//read the contents of state table from the file
	for(int row = 0; row < num_states; row++) {
		for (unsigned int col = 0; col < sigma.size(); col++)
			ifs >> table_row[col];
		state_table.push_back(table_row);
	}
}

//trace the operation of the FSA
void FSA::trace(const string& in_string)
{
	vector<int> state_trace;
	int cur_state = start_state;
	state_trace.push_back(cur_state);
	for (char ch; in_string) {
		int index = find(sigma, ch);
		if (index >=0) {
			cur_state = state_table[cur_state][index];
			state_trace.push_back(cur_state);
		} else {
			cerr << "Illegal input !\n";
			exit(1);
		}
	}
	cout << "State trace: ";
	for (int the_state: state_trace)
		cout << the_state << " ";
	if (find(accept_states, cur_state) >=0)
		cout << "...accepted\n";
	else 
		cout << "... not accepted\n";
}

//where is x found in vector v?
template <typename T> int FSA:::find(const vector<T> v, const T x)
{
	auto loc = std::find(v.begin(), v.end(), x);
	if (loc == v.end()) return -1;
	return loc - v.begin();
}
