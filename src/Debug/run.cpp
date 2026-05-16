#include <bits/stdc++.h>
using namespace std;

int main(){
	int t = 0;
	while(true){
		cout << "test: " << t ++ << endl;
		system("./data.o > data.in");
		system("./answer.o < data.in > answer.out");
		system("./solve.o < data.in > solve.out");
		if(system("diff answer.out solve.out > diff.log")){
			cout << "WA" <<'\n';
			break;
		}
		cout << "AC" << '\n';
	}
}