#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
string s;

bool checkPar(string s){
	stack<char> st;
	for(int i = 0; i < s.size(); i++){
      if(s[i] == '(' || s[i] == '[' || s[i] == '{')
         st.push(s[i]);
      else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
         if(!st.empty()){
            char x = st.top(); st.pop();
            if(x == '(' && s[i] != ')' || x == '[' && s[i] != ']' || x == '{' && s[i] != '}')
            	return false;
			}
			else{
				return false;
			}
		}
   }
   return st.empty();
}

int main(){
    cin >> N;
    for(int _i = 0; _i < N; _i++){
        cin >> s;
        cout << checkPar(s) << endl;
    }
}
