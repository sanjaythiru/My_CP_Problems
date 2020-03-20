#include<bits/stdc++.h>
using namespace std;
string to_string(int num, int dig)
{
	string s ="";
	for (int i=0;i<dig;i++)
	{
		s+=((num % 10)+'0');
		num/=10;
	}
	reverse(s.begin(), s.end());
	return s;
}
ifstream in;

const int max_test_files = 20;

//test_specific contents
void solve()
{
	int c=0;
	string ans;
	while (in>>ans) c++;
	assert(c==1);
	assert(ans=="YES"||ans=="NO");
}
//end of test_specific contents


int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++)
	{
		string file_name_op = "output/output" + to_string(i, 2) + ".txt";
		in.open(file_name_op.c_str(), std::ofstream::in);
		assert(in.is_open());
		solve();
		in.close();
		assert(!in.is_open());
	}
	return 0;
}
