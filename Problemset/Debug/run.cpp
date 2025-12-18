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
			cout << "------------------" << '\n';
			cout << "data :" <<'\n';
			system("cat data.in");
			cout << "------------------" << '\n';
			cout << "answer :" << '\n';
			system("cat answer.out");
			cout << "------------------" << '\n';
			cout << "solve :" << '\n';
			system("cat solve.out");
			cout << "------------------" << '\n';
			break;
		}
		cout << "AC" << '\n';
	}
}