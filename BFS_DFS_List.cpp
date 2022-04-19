#include <iostream>
#include <list>
#include <queue>
#include <stack>

enum class element
{
	A, B, C, D, E, F, LAST
};
typedef unsigned int UINT;
char text[(UINT)element::LAST] = { 'A','B','C','D','E','F' };
struct Node {
	std::list<element>  OutArrow;
	std::list<element>   InArrow;
};
void  set_up_Outedge(Node* s ,element _e1,element _e2) {

	s[(UINT)_e1].OutArrow.push_back(_e2);
}
void  set_up_Inedge(Node* s, element _e1, element _e2) {
	s[(UINT)_e1].InArrow.push_back(_e2);
}

std::queue<element> BFS_To(Node* n,element _first) {
	bool Discovered[(UINT)element::LAST] = { false, };
	Discovered[(UINT)_first] = true;				//Set Discovered[s] = true and Discovered[v] = false for all other v

	std::queue<element> layer;				
	layer.push(_first);							//Initialize L[0] to consist of the single element s

	std::queue<element> BFS_to;	//Set the current BFS tree T = ∅
	BFS_to.push(_first);

	while (!layer.empty())					//While L[i] is not empty
	{
		element curElement = layer.front();
		layer.pop();						//Initialize an empty list L[i + 1]

		std::list<element>::iterator iter = n[(UINT)curElement].OutArrow.begin();
		std::list<element>::iterator iterEnd = n[(UINT)curElement].OutArrow.end();
		for (; iter != iterEnd; ++iter)		//For each node u ∈ L[i]
		{		
			if (!Discovered[(UINT)*iter])		//If Discovered[v] = false then
			{
				Discovered[(UINT)*iter] = true;	//Set Discovered[v] = true
				BFS_to.push(*iter);				//Add edge (u, v) to the tree T
				layer.push(*iter);				//Add v to the list L[i + 1]
			}
		}
	}
	return BFS_to;
}
std::queue<element> BFS_From(Node* n, element _first) {
	bool Discovered[(UINT)element::LAST] = { false, };
	Discovered[(UINT)_first] = true;

	std::queue<element> layer;
	layer.push(_first);

	std::queue<element> BFS_from;
	BFS_from.push(_first);

	while (!layer.empty())
	{
		element curElement = layer.front();
		layer.pop();

		std::list<element>::iterator iter = n[(UINT)curElement].InArrow.begin();
		std::list<element>::iterator iterEnd = n[(UINT)curElement].InArrow.end();
		for (; iter != iterEnd; ++iter) {
			if (!Discovered[(UINT)*iter]) {
				Discovered[(UINT)*iter] = true;
				BFS_from.push(*iter);
				layer.push(*iter);
			}
		}
	}
	return BFS_from;
}
std::queue<element> DFS_To(Node* n, element _first) {
	bool Explore[(UINT)element::LAST] = { false, };
	Explore[(UINT)_first] = true;

	std::queue<element> dfs_to;

	std::stack<element> S;
	S.push(_first);				//Initialize S to be a stack with one element s
	
	
	while (!S.empty())			//While S is not empty
	{
		element curElement = S.top();	//Take a node u from S
		S.pop();
		dfs_to.push(curElement);
		
		std::list<element>::iterator iter = n[(UINT)curElement].OutArrow.begin();
		std::list<element>::iterator iterEnd = n[(UINT)curElement].OutArrow.end();
		for (; iter != iterEnd; ++iter) {
			if (!Explore[(UINT)*iter]) {				//For each edge (u, v) incident to u
				Explore[(UINT)*iter] = true;			//Set Explored[u] = true
				S.push(*iter);							//Add v to the stack S
			}
		}
	}
	return dfs_to;
}
std::queue<element> DFS_From(Node* n, element _first) {
	bool Explore[(UINT)element::LAST] = { false, };
	Explore[(UINT)_first] = true;

	std::queue<element> dfs_to;

	std::stack<element> S;
	S.push(_first);				//Initialize S to be a stack with one element s


	while (!S.empty())			//While S is not empty
	{
		element curElement = S.top();	//Take a node u from S
		S.pop();
		dfs_to.push(curElement);

		std::list<element>::iterator iter = n[(UINT)curElement].InArrow.begin();
		std::list<element>::iterator iterEnd = n[(UINT)curElement].InArrow.end();
		for (; iter != iterEnd; ++iter) {
			if (!Explore[(UINT)*iter]) {				//For each edge (u, v) incident to u
				Explore[(UINT)*iter] = true;			//Set Explored[u] = true
				S.push(*iter);							//Add v to the stack S
			}
		}
	}
	return dfs_to;
}

void printf(std::queue<element> q) {
	int size = q.size();
	std::cout << "{ ";
	for (int i = 0; i < size; ++i) {
		std::cout << text[(UINT)q.front()] << ", ";
		q.pop();
	}
	std::cout << "} " << std::endl;
}


std::queue<element> Find_StrongComponent(std::queue<element> q1, std::queue<element> q2) {
	std::queue<element> strongComponent;
	int component[(UINT)element::LAST] = {};
	int q1_size = q1.size();
	for (int i = 0; i < q1_size; ++i) {
		element curValue = q1.front();
		q1.pop();
		component[(UINT)curValue]++;
	}
	int q2_size = q2.size();
	for (int i = 0; i < q2_size; ++i) {
		element curValue = q2.front();
		q2.pop();
		component[(UINT)curValue]++;
	}
	for (int i = 0; i < (UINT)element::LAST; ++i) {
		if (component[i] == 2) 
			strongComponent.push((element)i);
	}

	return strongComponent;
}

int main() {

	Node* s = new Node[(UINT)element::LAST];
	{
		set_up_Outedge(s, element::A, element::B);			set_up_Inedge(s, element::A, element::B);
		set_up_Outedge(s, element::A, element::F);			set_up_Inedge(s, element::A, element::F);
		set_up_Outedge(s, element::B, element::A);			set_up_Inedge(s, element::B, element::A);
		set_up_Outedge(s, element::B, element::C);			set_up_Inedge(s, element::C, element::B);
		set_up_Outedge(s, element::B, element::E);			set_up_Inedge(s, element::C, element::F);
		set_up_Outedge(s, element::C, element::D);			set_up_Inedge(s, element::D, element::C);
		set_up_Outedge(s, element::C, element::E);			set_up_Inedge(s, element::E, element::B);
		set_up_Outedge(s, element::D, element::E);			set_up_Inedge(s, element::E, element::C);
		set_up_Outedge(s, element::E, element::C);			set_up_Inedge(s, element::E, element::D);
		set_up_Outedge(s, element::F, element::E);			set_up_Inedge(s, element::E, element::F);
		set_up_Outedge(s, element::F, element::A);			set_up_Inedge(s, element::F, element::A);
	}
	std::queue<element> bfs_to = BFS_To(s, element::B);
	std::cout << "BFS(A) : "; printf(bfs_to); std::cout << std::endl;
	std::queue<element> bfs_from = BFS_From(s, element::B);
	std::cout << "BFS(A)_reverse : "; printf(bfs_from); std::cout << std::endl;
	std::queue<element> dfs_to = DFS_To(s, element::B);
	std::cout << "DFS(A) : "; printf(dfs_to); std::cout << std::endl;
	std::queue<element> dfs_from = DFS_From(s, element::B);
	std::cout << "DFS(A)_reverse : "; printf(dfs_from); std::cout << std::endl;

	std::queue<element> strongComponent = Find_StrongComponent(bfs_to, dfs_from);
	std::cout << "Strong Component(A) : "; printf(strongComponent);
	delete[] s;

	return 0;
}
