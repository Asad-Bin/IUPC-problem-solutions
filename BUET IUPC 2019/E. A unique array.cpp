// Problem link: https://toph.co/p/a-unique-array


// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int MX = 1e5;

int n;
int ara[MX+5], tree[4*MX+5], on[4*MX+5];

void build(int at, int l, int r)
{
	if(l == r){
		tree[at] = ara[l-1];
		on[at] = 1;
		
		return;
	}
	
	int mid = (l+r)/2;
	
	build(at*2, l, mid);
	build(at*2+1, mid+1, r);
	
	on[at] = on[at*2] + on[at*2+1];
}
pair<int, int> check(int at, int l, int r, int idx)
{
	if(idx < 1 || idx > n) return {-1, -1};
	
	if(l == r){
		return {tree[at], at};
	}
	
	int mid = (l+r)/2;
	
	if(idx <= on[at*2]) return check(at*2, l, mid, idx);
	else return check(at*2+1, mid+1, r, idx-on[at*2]);
}
void update(int at, int l, int r, int x, int y, int idx)
{
	if(x > r-l+1) return;
	
	if(l == r){
		tree[at] = ara[l-1] = y;
		
		pair<int, int> a = check(1, 1, n, idx-1);
		pair<int, int> b = check(1, 1, n, idx+1);
		
		if(b.first == tree[at]) update(1, 1, n, idx+1, y, idx+1);
		if(a.first == tree[at]) on[at] = 0;
		
		return;
	}
	
	
	int mid = (l+r)/2;
	
	if(x <= on[at*2]) update(at*2, l, mid, x, y, idx);
	else update(at*2+1, mid+1, r, x-on[at*2], y, idx);
	
	on[at] = on[at*2] + on[at*2+1];
}
int main()
{
	int t, cs = 0, q, x, y;
	
	cin >> t;
	while(++cs <= t){
		cin >> n >> q;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		build(1, 1, n);
		
		cout << "Case " << cs << ":\n";
		while(q--){
			cin >> x >> y;
			
			update(1, 1, n, x+1, y, x+1);
			
			cout << on[1] << "\n";
		}
	}
	
	return 0;
}




















































