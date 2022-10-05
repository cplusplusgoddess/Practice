#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Meta Problem: The Rabbit Hole

You're having a grand old time clicking through the rabbit hole 
that is your favorite online encyclopedia.
The encyclopedia consists of N different web pages, numbered 
from 1 to N. Each page i contains nothing but a single 
link to a different page L[i]
A session spent on this website involves beginning on one of 
the N pages, and then navigating around using the links until 
you decide to stop. That is, while on page i, you may either 
move to page L[i] or stop your browsing session.
Assuming you can choose which page you begin the session on, 
what's the maximum number of different pages you can visit 
in a single session? Note that a page only counts once even 
if visited multiple times during the session.
Constraints:
		2 <= N <= 500,000
		1 ≤ L[i] ≤ N 
		L[i] ≠ i
*/

#define MAX(a, b)((a>b)?a:b)
struct Node{
  int id;
  int depth;
  int link;
};
typedef Node * Nodeptr;
typedef vector<Node> Graph;
typedef stack<int> MyStack;

//
// Recursive DFS to find the depth of a path starting from my_id
//
int explore_link(int my_id, Graph & graph, MyStack &s ){
  Nodeptr me = &graph[my_id];

  if(me->depth == 0){ // this is the first visit of this node
    Nodeptr linkNode = &(graph[me->link]);
    me->depth++;
    s.push(me->id);
#ifdef DEBUG
  	cout << " Pushing Node pre explore: " << me->id << endl ;
#endif
	 // Lets take advantage that we know only 1 link per node
	 if(linkNode->depth == 1){ // this is the end/start pt of a cycle
		linkNode->depth = 0;
	 	while(!s.empty()){
			int plink = s.top();
			s.pop();
#ifdef DEBUG
  		    cout << " Popping Node: " << plink ;
#endif
			linkNode->depth++;
			if(plink == linkNode->id)
			     	break;
		}
#ifdef DEBUG
  	    cout << endl ;
#endif
		me->depth = linkNode->depth;
        return(me->depth);
	}
    if(linkNode->depth == 0){
		me->depth = explore_link(me->link, graph, s);
    } else // link->depth > 1 this node already calculated add it to me and done
		me->depth = linkNode->depth;
    if(!s.empty() && (s.top() == me->id)){
		me->depth++;
		s.pop();
#ifdef DEBUG
  		cout << " Popping & Adding Node: " << me->id << endl;
#endif
	}
  } // end if me first time visit
  return(me->depth);
	
}



int getMaxVisitableWebpages(int N, vector<int> L) {
  Graph graph(N,{0, 0,-1});
  MyStack s;
  int max_depth = 0;
  for(int i = 0; i < L.size(); i++){   // Construct the Graph
    graph[i].id = i;
    graph[i].link = L[i] - 1;
    
  }
  for(int i = 0; i < N; i++ )
    max_depth = MAX(max_depth, explore_link(i, graph, s));
#ifdef DEBUG
  for(int i = 0 ; i < N; i++){
    if(max_depth == (graph[i]).depth )
    	cout << "Starting Node: " << i << " **depth: " << (graph[i]).depth ;
	else
    	cout << "Starting Node: " << i << "   depth: " << (graph[i]).depth ;
	cout << " link: " << (graph[i]).link << endl;
  }
#endif
  return (max_depth);
}

int main(){
    int max_depth;
	int N = 4; 
	vector<int> L = {4, 1, 2, 1}; // expected 4 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 2; 
	L = {2,1}; // expected 2 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 5; 
	L = {4, 4, 4, 1, 4}; // expected 3 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 5; 
	L = {2, 1, 1, 3, 4}; // expected 5 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 5; 
	L = {2, 3, 4, 5, 1}; // expected 5 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 5; 
	L = {2, 3, 4, 5, 3}; // expected 5 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 5; 
	L = {5, 1, 5, 3, 1}; // expected 4 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 5; 
	L = {2, 1, 1, 3, 3}; // expected 4 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 5; 
	L = {2, 3, 5, 5, 3}; // expected 4 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 6; 
	L = {2, 4, 5, 5, 3, 2}; // expected 4 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 6; 
	L = {2, 3, 4, 2, 2, 5}; // expected 5 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	N = 6; 
	L = {3, 3, 2, 5, 6, 1}; // expected 5 
	max_depth = getMaxVisitableWebpages(N, L);
    cout << "------- Max number of links reached: " << max_depth << "\n\n";
	return(0);
}
