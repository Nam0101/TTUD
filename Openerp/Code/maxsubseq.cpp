#include <iostream>
using namespace std;

#define MAX 100000

int n, l, r;
int a[MAX];
long long b[MAX + 1];
long long Max = -99999;

int main(){
	FILE* f;
	f = fopen("maxsubseq.txt", "r");
	fscanf(f, "%d%d%d", &n, &l, &r);
	//cin >> n >> l >> r;
	b[0] = 0;
	for(int i = 0; i < n; i++){
		//cin >> a[i];
		fscanf(f, "%d", &a[i]);
		b[i + 1] = b[i] + a[i];
	}
	//
	int sid, eid, lr;
	sid = 0;
	eid = sid + l - 1;
	lr = r - l;
	do{
		while(eid < n && eid - sid + 1 < r){
			if(eid < n) Max = max(Max, b[eid + 1] - b[sid]);
			cout << sid << "-" << eid << ": " << Max << endl;
			eid++;
		}
		while(sid < n && eid < n && eid - sid + 1 > l){
			if(eid < n) Max = max(Max, b[eid + 1] - b[sid]);
			cout << sid << "-" << eid << ": " << Max << endl;
			sid++;
		}
	}
	while(eid < n);
	eid = n - 1;
	sid = eid - l + 1;
	while(eid - sid + 1 <= r){
		cout << sid << "-" << eid << ": " << Max << endl;
		sid--;
	}
	cout << Max;
}
