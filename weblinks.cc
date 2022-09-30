#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX(a, b)((a>b)?a:b)
struct Node{
  int depth;
  int link;
};
typedef Node * Nodeptr;
typedef vector<Node> Graph;
typedef stack<int> MyStack;

int explore_link(int my_id, Graph & graph, MyStack &s ){
  Nodeptr me = &graph[my_id];

	// Lets take advantage that we know only 1 link per node
  if(me->depth == 1){ // this is the end/start pt of a cycle
	 while(!s.empty()){
		me->depth++;
		int plink = s.top();
		s.pop();
  		cout << " Popping Node: " << plink ;
		if(plink == my_id)
			break;
	 }
     return(me->depth-1);
  }
  if(me->depth > 1)
  	return(me->depth-1);

  // My depth == 0  New node
  cout << "\npushing  Node: " << my_id ;
  me->depth ++;
  s.push(my_id);
  me->depth += explore_link(me->link, graph, s );
  return(me->depth-1);
}


int getMaxVisitableWebpages(int N, vector<int> L) {
  Graph graph(N,{0,-1});
  MyStack s;
  int max_depth = 0;
  for(int i = 0; i < L.size(); i++){
    graph[i].link = L[i] - 1;
    
  }
  for(int i = 0; i < N; i++ ){
    //(graph[i]).depth = 0;
    max_depth = MAX(max_depth, explore_link(i, graph, s));
    
  }
  cout << "\nMax number of links reached: " << max_depth << endl;
  for(int i = 0 ; i < N; i++){
    if(max_depth == (graph[i]).depth )
    	cout << "Starting Node: " << i << " **depth: " << (graph[i]).depth ;
	else
    	cout << "Starting Node: " << i << "   depth: " << (graph[i]).depth ;
	cout << " link: " << (graph[i]).link << endl;
  }
  return (max_depth);
}

int main(){
	int N = 4; 
	vector<int> L = {4, 1, 2, 1}; // expected 4 
	getMaxVisitableWebpages(N, L);
	N = 2; 
	L = {2,1}; // expected 2 
	getMaxVisitableWebpages(N, L);
	N = 5; 
	L = {4, 4, 4, 1, 4}; // expected 2 
	getMaxVisitableWebpages(N, L);
	N = 5; 
	L = {2, 1, 1, 3, 4}; // expected 5 
	getMaxVisitableWebpages(N, L);
	N = 5; 
	L = {2, 3, 4, 5, 1}; // expected 5 
	getMaxVisitableWebpages(N, L);
	N = 5; 
	L = {2, 3, 4, 5, 3}; // expected 5 
	getMaxVisitableWebpages(N, L);
	return(0);
}
