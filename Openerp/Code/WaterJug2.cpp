#include <iostream>
#include <queue>
using namespace std;

#define MAX 10000

int a, b, c;

bool m[MAX+1][MAX+1];

struct State{
	int x; // jug 1
	int y; // jug 2
	State* p; // tro den trang thai cha
};

queue<State*> Q;

State* initState(){
	State* s = new State;
	s->x = 0; s->y=0; s->p = NULL;
	return s;
}

void clearQ(){
	while(!Q.empty()){
		Q.pop();
	}
}

void init_m(){
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			m[i][j] = false;
		}
	}
}

void print_s(State* s){
	cout << "(" << s->x << ";" << s->y << ")" << endl;
}

bool checkTarget(State* s){
	return s->x == c || s->y == c;
}

bool genStateEmpty1(State* s){
	// sinh ra trang thai moi tu s bang cach do het nuoc coc 1 ra ngoai
	if(m[0][s->y]) return false;
	State* newS = new State;
	newS->x = 0; newS->y = s->y; newS->p = s;
	m[newS->x][newS->y] = true;
	Q.push(newS);
	return checkTarget(newS);
}

bool genStateEmpty2(State* s){
	// sinh ra trang thai moi tu s bang cach do het nuoc coc 1 ra ngoai
	if(m[s->x][0]) return false;
	State* newS = new State;
	newS->x = s->x; newS->y = 0; newS->p = s;
	m[newS->x][newS->y] = true;
	Q.push(newS);
	return checkTarget(newS);
}

bool genStateFill1(State* s){
	if(m[a][s->y]) return false;
	State* newS = new State;
	newS->x = a; newS->y = s->y; newS->p = s;
	m[newS->x][newS->y] = true;
	Q.push(newS);
	return checkTarget(newS);
}

bool genStateFill2(State* s){
	if(m[s->x][b]) return false;
	State* newS = new State;
	newS->x = s->x; newS->y = b; newS->p = s;
	m[newS->x][newS->y] = true;
	Q.push(newS);
	return checkTarget(newS);
}

bool genState1To2(State* s){
	if(s->x + s->y > b){
		if(m[s->x + s->y - b][b]) return false;
		State* newS = new State;
		newS->x = s->x + s->y - b; newS->y = b; newS->p = s;
		m[newS->x][newS->y] = true;
		Q.push(newS);
		return checkTarget(newS);
	}
	else{
		if(m[0][s->x + s->y]) return false;
		State* newS = new State;
		newS->x = 0; newS->y = s->x + s->y; newS->p = s;
		m[newS->x][newS->y] = true;
		Q.push(newS);
		return checkTarget(newS);
	}
}

bool genState2To1(State* s){
	if(s->x + s->y > a){
		if(m[a][s->x + s->y - a]) return false;
		State* newS = new State;
		newS->x = a; newS->y = s->x + s->y - a; newS->p = s;
		m[newS->x][newS->y] = true;
		Q.push(newS);
		return checkTarget(newS);
	}
	else{
		if(m[s->x + s->y][0]) return false;
		State* newS = new State;
		newS->x = s->x + s->y; newS->y = 0; newS->p = s;
		m[newS->x][newS->y] = true;
		Q.push(newS);
		return checkTarget(newS);
	}
}

void solve(){
	init_m();
	State* s0 = initState();
	m[0][0] = true;
	clearQ();
	Q.push(s0);
	while(!Q.empty()){
		State *s = Q.front(); Q.pop();
		if(genStateEmpty1(s)) break;
		if(genStateEmpty2(s)) break;
		if(genStateFill1(s)) break;
		if(genStateFill2(s)) break;
		if(genState1To2(s)) break;
		if(genState2To1(s)) break;
	}
	if(Q.empty()){
		cout << "-1" << endl;
	}
	else{
		int cnt = 0;
		State *e = Q.back();
		while(e != s0){
			cnt++;
			e = e->p;
		}
		cout << cnt << endl;
	}
}

int main(){
	int T;
	cin >> T;
	for(int _t = 0; _t < T; _t++){
		cin >> a >> b >> c;
		solve();	
	}
}
