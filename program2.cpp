#include <bits/stdc++.h> 
using namespace std;
void solve(string s1, string s2)
{
    
	int size1=s1.length(), size2=s2.length();
	//we are using unordered_multiset as it allowes duplicates
	unordered_multiset<char>set1;
	for(int i=0;i<size2;i++)
	{
		set1.insert(s1[i]);
	}
	unordered_multiset<char>set2;

	for (int i = 0; i < size2; i++)
		set2.insert(s2[i]);

	for (int i = size2; i < size1; i++)
	{

			if (set1 == set2)
			{
				cout << "substring '" << s1.substr(i - size2, size2) <<"' present at index " << i - size2 << '\n';
			}
			if(set1.find(s1[i - size2])!=set1.end())
				set1.erase(set1.find(s1[i - size2]));

			
			set1.insert(s1[i]);
	}
	
			if (set1 == set2)
			{
				cout << "substring '" << s1.substr(size1 - size2, size2) <<"' present at index " << size1 - size2 << '\n';
			}
}

int main()
{
	string s1="XYYZXZYZXXYZ",s2="XYZ";
    //if you want to takr=e input
    /*getline(cin,s1);
    getline(cin,s2);*/

	solve(s1, s2);

	return 0;
}
