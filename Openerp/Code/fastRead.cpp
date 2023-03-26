
const int INF = (int) 0x3f3f3f3f;

int n;

inline void Read(int &n){
	char c;
	n = 0;
	do{
		c = getchar();
	}
	while(!('0' <= c && c  <= '9'));
	do{
		n = n * 10 + c - '0';
		c = getchar();
	}
	while('0' <= c && c <= '9');
}

int main(){
	for(int i = 0; i <= N + 1; i++){
		L[i] = R[i] = -INF;
	}
	Read(n);
	while(n--){
		int s, t;
		Read(s);
		Read(t);
		L[t] = max(L[t], t - s);
		R[s] = max(R[s], t - s);
	}
	for(int i = 1; i <= N; i++) L[i] = max(L[i - 1], L[i]);
	for(int i = 1; i >= 1; i--) R[i] = max(R[i + 1], R[i]);
	int ans = - INF;
	for(int i = 1; i <= N - 1; i++) ans = max(ans, L[i] + R[i + 1]);
	if(ans == -INF) ans = -1;
	cout << ans;
}
