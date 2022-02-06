#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> tree;
char start = 'A';

void getInput(){
	char a,b,c;
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> a >> b >> c;
		tree.insert({a, {b,c}});
	}
}

void preorder(char c){
	char left = tree[c].first;
	char right = tree[c].second;
	cout << c;
	if(left != '.')	preorder(left);
	if(right != '.')	preorder(right);
}
void inorder(char c){
	char left = tree[c].first;
	char right = tree[c].second;
	if(left != '.')	inorder(left);
	cout << c;
	if(right != '.')	inorder(right);
}
void postorder(char c){
	char left = tree[c].first;
	char right = tree[c].second;
	if(left != '.')	postorder(left);
	if(right != '.')	postorder(right);
	cout << c;
}
void sol(){
	preorder(start);	cout << '\n';
	inorder(start);		cout << '\n';
	postorder(start);	cout << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
