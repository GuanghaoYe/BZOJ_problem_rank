#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
struct Pro{
	int num,ac,submit;
	double ratio;
	Pro(int _num,int _ac,int _submit) {
		num=_num;
		ac=_ac;
		submit=_submit;
		ratio=1.0*ac/submit;
	}
	void print()
	{
		printf("P%d %f %d\n",num,ratio,ac);
	}
	bool operator < (const Pro &a) const {return ratio<a.ratio; }
};
bool cmp_num(Pro a,Pro b){
	return a<b;
}
using namespace std;
vector<Pro> rank;
#define R(x) scanf("%d",&x)
bool is_supporter;
bool is_freopen;
int main()
{
	puts("Are you the BZOJ supporter: [y]es,[n]o");
	char temp=0;
	while(temp!='y'&&temp!='n') {
		cin>>temp;
	}
	is_supporter= temp=='y';
	puts("Output the result to file rank.dat? [y]es,[n]o");
	temp=0;	
	while(temp!='y'&&temp!='n') {
		cin>>temp;
	}
	is_freopen= temp=='y';	
	int limit;
	puts("the lowest AC num:");	
	cin>>limit;
	ifstream dataFile,doneFile,blackFile;
	if(is_supporter){
		dataFile.open("data.dat");
	} else {
		dataFile.open("data_novip.dat");
	}
	doneFile.open("done.dat");
	if(is_freopen) freopen("rank.dat","w",stdout);
	register int a,b,c;
	while(dataFile>>a>>b>>c){
		rank.push_back(Pro(a,b,c));
	}
	while(doneFile>>a) {
		for(int i=0;i<rank.size();++i) {
			if(rank[i].num==a) {
//				cout<<(*(rank.begin()+i)).num<<endl;
				rank.erase(rank.begin()+i);
				i--;
				doneFile>>a;
			}
		}
	}
	dataFile.close();
	doneFile.close();
	blackFile.open("black.dat");
	while(blackFile>>a) {
		for(int i=0;i<rank.size();++i) {
			if(rank[i].num==a) {
//				cout<<(*(rank.begin()+i)).num<<endl;
				rank.erase(rank.begin()+i);
				i--;
				doneFile>>a;
			}
		}
	}
	blackFile.close();
	sort(rank.begin(),rank.end());
	for(int i=rank.size()-1;i>=0;--i) {
		if(rank[i].ac>=limit){
			rank[i].print();
		}
	}
}

