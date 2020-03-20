#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
const int maxval=1e5;
string to_string(int num, int dig) {
	string s = "";
	for (int i = 0; i < dig; i++) {
		s += ((num % 10) + '0');
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

ifstream in;
vector<int> adj_list[maxn+1];
const int max_test_files = 20;

//test_specific contents
void check()
{
	int n,m;
	in>>n;
	assert(n>=1);
	assert(n<=maxn);
	int maxedges=min(100000,n);
	in>>m;
	assert(m>=1);
	assert(m<=maxedges);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		in>>u>>v;
		assert(u!=v);	// to ensure that there are no self loops
		bool found=false;
		for(int j=0;j<adj_list[u].size();j++)
		{
			if(adj_list[u][j]==v)
			{
				found=true;
				break;
			}
		}
		assert(found==false);	// to ensure there are no multiple edges
	}
	for(int i=0;i<=n;i++)
	{
		adj_list[i].clear();
	}
}
//end of test_specific contents


int main()
{
	srand(time(NULL));
	for (int i=0;i<max_test_files;i++)
	{
		string file_name = "input/input" + to_string(i, 2) + ".txt";
		in.open(file_name.c_str(), std::ifstream::in);
		assert(in.is_open());
		check();
		in.close();
		assert(!in.is_open());
	}
	return 0;
}
