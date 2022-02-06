#include <iostream>
#define MAX 100000+1
using namespace std;

int N;
int in[MAX], inidx[MAX], post[MAX], postidx[MAX];

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> in[i];
		inidx[in[i]] = i;
	}// left root right
	for(int i=0; i<N; i++){
		cin >> post[i];
		postidx[post[i]] = i;
	}// left right root
}

void pre(int in_s, int in_f, int post_s, int post_f){
	if(in_s > in_f || post_s > post_f)	return;
	int root = post[post_f];
	cout << root << ' ';
	int pos = inidx[root];
	int len = pos - in_s;
	pre(in_s , pos-1, post_s    , post_s + len -1);
	pre(pos+1, in_f , post_s+len, post_f-1);
}

int main(){
	getInput();
	pre(0, N-1, 0, N-1);	cout << '\n';
	return 0;
}
