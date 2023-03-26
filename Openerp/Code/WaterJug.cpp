#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000000

typedef struct{
	int x, y, t;
} wat;

bool tx[MAX + 1], ty[MAX + 1];

int T;
int a, b, c;
wat cur;
int cnt;

void init_t(){
	int max_v = a > b ? a : b;
	for(int i = 0; i <= max_v; i++){
		if(i <= a) tx[i] = false;
		if(i <= b) ty[i] = false;
	}
}

int main(){
	cin >> T;
	for(int _t = 0; _t < T; _t++){
		cin >> a >> b >> c;
		init_t();
		cur.x = cur.y = cur.t = 0;
		queue<wat> Q;
		Q.push(cur);
		cnt = -1;
		bool flag = false;
		while(!Q.empty()){
			wat cur = Q.front();
			Q.pop();
			cout << cur.x << " " << cur.y << endl;
			if(cur.x == c || cur.y == c) {
				cnt = cur.t;
			}
			tx[cur.x] = true; ty[cur.y] = true;
			wat t1, t2, t3, t4, t5, t6;
			//
			t1.x = cur.x;
			t1.y = b;
			t1.t = cur.t + 1;
			if(!tx[t1.x] || !ty[t1.y]) Q.push(t1);
			//
			t2.x = a;
			t2.y = cur.y;
			t2.t = cur.t + 1;
			if(!tx[t2.x] || !ty[t2.y]) Q.push(t2);
			//
			if(cur.x > b - cur.y){
				t3.x = cur.x + cur.y - b;
				t3.y = b;
			}
			else{
				t3.x = 0;
				t3.y = cur.y + cur.x;
			}
			t3.t = cur.t + 1;
			if(!tx[t3.x] || !ty[t3.y]) Q.push(t3);
			//
			if(cur.y > a - cur.x){
				t4.y = cur.x + cur.y - a;
				t4.x = a;
			}
			else{
				t4.y = 0;
				t4.x= cur.y + cur.x;
			}
			t4.t = cur.t + 1;
			if(!tx[t4.x] || !ty[t4.y]) Q.push(t4);
			//
			t5.x = 0;
			t5.y = cur.y;
			t5.t = cur.t + 1;
			if(!tx[t5.x] || !ty[t5.y]) Q.push(t5);
			//
			t6.y = 0;
			t6.x = cur.x;
			t6.t = cur.t + 1;
			if(!tx[t6.x] || !ty[t6.y]) Q.push(t6);
		}
		cout << cnt << endl;
	}
}
