#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

char str[101];
int res = 0, tmp = 0, cur = 0;

int main(){
	stack<int> mSt;
	cin >> str;
	for(int i = 0; i < strlen(str); i++){
		char c = str[i];
		if(c == '('){
			mSt.push(0);
		}
		else if(c == 'C' || c == 'H' || c == 'O'){
			mSt.push(c == 'C' ? 12 : c == 'H' ? 1 : 16);
		}
		else if('2' <= c && c <= '9'){
			mSt.push(-c + 48);
		}
		else if(c == ')'){
			tmp = 0;
			while(mSt.top() != 0 && !mSt.empty()){
				int val = mSt.top();
				mSt.pop();
				if(val <= -2){
					tmp += mSt.top() * (-val);
					mSt.pop();
				}
				else{
					tmp += val;
				}
			}
			if(mSt.top() == 0) mSt.pop();
			mSt.push(tmp);
		}
	}
	while(!mSt.empty()){
		int val = mSt.top();
		mSt.pop();
		if(val <= -2){
			res += mSt.top() * (-val);
			mSt.pop();
		}
		else{
			res += val;
		}
	}
	cout << res;
}
