// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	int t, cs = 0, n, d;
	string s;
	
	cin >> t;
	getchar();
	while(t--){
		getline(cin, s);
		
		reverse(s.begin(), s.end());
		
		cout << s << "\n";
	}
	
	return 0;
}


