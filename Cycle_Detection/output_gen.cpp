#include<bits/stdc++.h>
using namespace std;
string to_string(int num,int dig)
{
	string s="";
	for(int i=0;i<dig;i++)
	{
		s+=(num%10)+'0';
		num/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

ofstream out;
ifstream in;

const int max_test_files=20;

const int maxn=1e5;
vector<int> adj_list[maxn+1];
bool visited[maxn+1];
bool cycle;
void dfs(int s,int p)
{
	visited[s]=true;
	for(auto it:adj_list[s])
	{
		if(!visited[it])
		{
			dfs(it,s);
		}
		else
		{
			if(it!=p)
				cycle=true;
		}
	}
}
void solve()
{
	int n,m;
	in>>n>>m;
	cycle=false;
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=m;i++)
	{
		int u,v;
		in>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			dfs(i,i);
		}
	}
	if(cycle) out<<"YES"<<endl;
	else out<<"NO"<<endl;
	for(int i=1;i<=n;i++)
	{
		adj_list[i].clear();
	}
}

int main()
{
	srand(time(NULL));
	for(int i=0;i<max_test_files;i++)
	{
		string file_name_ip="input/input"+to_string(i,2)+".txt";
		string file_name_op="output/output"+to_string(i,2)+".txt";
		in.open(file_name_ip.c_str(),std::ifstream::in);
		out.open(file_name_op.c_str(),std::ofstream::out|std::ofstream::trunc);
		assert(out.is_open());
		assert(in.is_open());
		solve();
		out.close();
		in.close();
		assert(!in.is_open());
		assert(!out.is_open());
	}
	return 0;
}