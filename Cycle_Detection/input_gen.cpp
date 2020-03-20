#include<bits/stdc++.h>
using namespace std;
const int max_test_files=20;
mt19937_64 rng(time(NULL));
const int maxn=1e5;
const int maxval=1e5;
ofstream out;
vector<int> adj_list[maxn+1];
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

void generate()
{
	int n=rand()%maxn+1;
	int m=rand()%maxn+1;
	out<<n<<" "<<m<<endl;
	for(int i=1;i<=m;i++)
	{
		while(true)
		{
			int u=rand()%n+1;
			int v=rand()%n+1;
			if(u==v) continue;
			bool found=false;
			for(int i=0;i<adj_list[u].size();i++)
			{
				if(adj_list[u][i]==v)
				{
					found=true;
				}
			}
			if(found==true) continue;
			out<<u<<" "<<v<<endl;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
			break;
		}
	}
	for(int i=0;i<=n;i++)
	{
		adj_list[i].clear();
	}
}

void strong0()
{
	out<<3<<" "<<3<<endl;	// A Graph with 3 vertices and 3 edges
	out<<1<<" "<<2<<endl;	// 1 - 2
	out<<2<<" "<<3<<endl;	// 2 - 3
	out<<3<<" "<<1<<endl;	// 3 - 1
	// A cycle 1 - 2 - 3 - 1
}

void strong1()
{
	out<<3<<" "<<2<<endl;	// A Graph with 3 vertices and 2 edges
	out<<1<<" "<<2<<endl;	// 1 - 2
	out<<2<<" "<<3<<endl;	// 2 - 3
	// No cycle
}

void strong2()
{
	out<<100000<<" "<<100000<<endl;
	for(int i=1;i<=99999;i++)
	{
		out<<i<<" "<<i+1<<endl;
	}
	out<<100000<<" "<<1<<endl;
	// A big cycle to ensure that the solution passes in O(N+M)
}

int main()
{
	srand(time(NULL));
	for(int i=0;i<max_test_files;i++)
	{
		string file_name="input/input"+to_string(i,2)+".txt";
		out.open(file_name.c_str(),std::ofstream::out|std::ofstream::trunc);
		assert(out.is_open());
		if(i==0)
		{
			strong0();
		}
		else if(i==1)
		{
			strong1();
		}
		else if(i==2)
		{
			strong2();
		}
		else
		{
			generate();
		}
		out.close();
		assert(!out.is_open());
	}
	return 0;
}