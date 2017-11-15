#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//disjoint sets data structure
int fathers[100];

int find(int x)
{
	if(fathers[x]==x){
		return x;
	}
	else{
		return find(fathers[x]);
	}
}
void unite(int x,int y){
	int fx=find(x);
	int fy=find(y);
	fathers[fx]=fy;
}

int main(){
	//initialize fathers for the disjoint sets
	for (int i=0;i<100;i++){
		fathers[i]=i;
	}
	//declaring the variables to load input
	int n=7,m=9;
	int a,b,w;
	vector < pair <int , pair < int , int > > > edges;
	//loading the input

	cout<<"1 2 4\n";
	cout<<"7 2 2\n";
	cout<<"6 2 3\n";
	cout<<"6 5 1\n";
	cout<<"5 3 20\n";
	cout<<"4 3 6\n";
	cout<<"1 4 7\n";
	cout<<"2 5 2\n";
	cout<<"2 3 1\n";

	edges.push_back(make_pair(4,make_pair(1,2)));
	edges.push_back(make_pair(2,make_pair(7,2)));
	edges.push_back(make_pair(3,make_pair(6,2)));
	edges.push_back(make_pair(1,make_pair(6,5)));
	edges.push_back(make_pair(20,make_pair(5,3)));
	edges.push_back(make_pair(6,make_pair(4,3)));
	edges.push_back(make_pair(7,make_pair(1,4)));
	edges.push_back(make_pair(2,make_pair(2,5)));
	edges.push_back(make_pair(1,make_pair(2,3)));

	// we print a line to seperate input from output
	cout<<endl;

	// Now for kruskal's algorithm
	//We firstly declare the variables for the MST
	int mst_weight = 0,mst_edges =0;
	int mst_ni=0;

	//Step 1:sort the list of edges by using sort function
	sort(edges.begin(),edges.end());

	//Step 2-3:
	while((mst_edges<n-1)||(mst_ni<m)){
		//we broke the edge into the three integers they describe it
		a=edges[mst_ni].second.first;
		b=edges[mst_ni].second.second;
		w=edges[mst_ni].first;
		//we check if the edge is ok to be included in the MST
		//if a and b are in different trees(if they are on the same we will create a cycle

		if(find(a)!=find(b)){
			//we unite the two trees the edge connects
			unite(a,b);
			//we add the weight of the edge
			mst_weight+=w;
			//we print the edge
			cout<<a<<" "<<b<<" "<<w<<endl;
			//and count it
			mst_edges++;
		}
		//increasing the index of the edge we will be increasing
		mst_ni++;
	}
	// displaying weight
	cout<<"Weight of MST is "<<mst_weight<<endl;
	return 0;
}
