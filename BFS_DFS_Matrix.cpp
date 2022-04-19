#include <iostream>
#include <vector>

enum class element
{
	A, B, C, D, E, F, Last			//index represented (0, 1, 2, 3, 4, 5, 6)
};
typedef unsigned int UINT;			//index should be unsigned int so i just typedef unsigned int to UNIT;
/*
  a b c d e f	x					//input
a 1 1 0 0 0 1		
b 1 1 1 0 1 0
c 0 0 1 1 1 0
d 0 0 0 1 1 0
e 0 0 1 0 1 0
f 1 0 0 0 1 1

y
*/
int adj[(UINT)element::Last][(UINT)element::Last] = { {1,1,0,0,0,1},
										  {1,1,1,0,1,0},
										  {0,0,1,1,1,0},
										  {0,0,0,1,1,0},
										  {0,0,1,0,1,0},
										  {1,0,0,0,1,1}
};
std::vector<element> Tree;
bool explore[(UINT)element::Last] = { false, };
char text[(UINT)element::Last] = { 'A','B','C','D','E','F' };

void Print_output(const std::vector<element>& p1)  
{
	for (auto t : p1) {
		std::cout << text[(UINT)t] << ", ";
	}
	std::cout << "}" << std::endl;
}

//(x, y)
void BFS(element _first) {
	int layer[(UINT)element::Last+1] = {-1,-1,-1,-1,-1,-1,-1};			//I need some value to break the while loop 
	int layer_index = 0;
	int i = 0;
	layer[layer_index++] = (UINT)_first;
	explore[(UINT)_first] = true;

	while (layer[i]!=-1) {
		Tree.push_back((element)layer[i]);
		for (int k = 0; k < (UINT)element::Last; ++k) {
			if (adj[layer[i]][k] == 1) {
				if (!explore[k]) {
					explore[k] = true;
					layer[layer_index++] = k;
				}
			}
		}
		i++;
	}
	
}
void DFS(element _first) {											//I use recursive function instead of stack 
	if (!explore[(UINT)_first]) {
		explore[(UINT)_first] = true;
		Tree.push_back(_first);
		for (int i = 0; i < (UINT)element::Last; ++i) {
			if (adj[(UINT)_first][i] == 1)
				DFS((element)i);
		}
	}
}
//(y, x)
void BFS_reverse(element _first) {
	int layer[(UINT)element::Last + 1] = { -1,-1,-1,-1,-1,-1,-1 };
	int layer_index = 0;
	int i = 0;
	layer[layer_index++] = (UINT)_first;
	explore[(UINT)_first] = true;

	while (layer[i] != -1)
	{
		Tree.push_back((element)layer[i]);
		for (int k = 0; k < (UINT)element::Last; ++k) {
			if (adj[k][layer[i]] == 1) {
				if (!explore[k]) {
					explore[k] = true;
					layer[layer_index++] = k;
				}
			}
		}
		i++;
	}
}
void DFS_reverse(element _first) {
	if (!explore[(UINT)_first]) {
		explore[(UINT)_first] = true;
		Tree.push_back(_first);
		for (int i = 0; i < (UINT)element::Last; ++i) {
			if (adj[i][(UINT)_first] == 1) 
				DFS_reverse((element)i);
		}
	}
}

void Strong_Component(element _In_ input) {
	BFS(input);
	std::vector<element> P_To = Tree;
	Tree.clear();
	memset(explore, false, sizeof(explore[0]) * (UINT)element::Last);		// clear all previous information for next function
	std::cout << "BFS(" << text[(UINT)input] << ") : { ";					//output
	Print_output(P_To);
	/*DFS(input);
	std::vector<element> P_To = Tree;
	Tree.clear();
	memset(explore, false, sizeof(explore[0]) * (UINT)element::Last);
	std::cout << "DFS(" << text[(UINT)input] << ") : { ";
	Print_output(P_To);
	BFS_reverse(input);
	std::vector<element> P_From = Tree;
	Tree.clear();
	memset(explore, false, sizeof(explore[0]) * (UINT)element::Last);
	std::cout << "BFS_reverse(" << text[(UINT)input] << ") : { ";
	Print_output(P_From);*/
	DFS_reverse(input);
	std::vector<element> P_From = Tree;
	Tree.clear();
	memset(explore, false, sizeof(explore[0]) * (UINT)element::Last);
	std::cout << "DFS_reverse(" << text[(UINT)input] << ") : { ";
	Print_output(P_From);
	
	//find component
	int componenet_count[(UINT)element::Last] = {};
	std::vector<element> strongComponent;
	for (auto T : P_To) {
		componenet_count[(UINT)T]++;
	}
	for (auto T : P_From) {
		componenet_count[(UINT)T]++;
	}
	for (int i = 0; i < (UINT)element::Last; ++i) {
		if (componenet_count[i] == 2)
			strongComponent.push_back((element)i);
	}
	std::cout<<"Strong Component(" << text[(UINT)input] << ") : { ";
	Print_output(strongComponent);
}

int main() {

	Strong_Component(element::E);

	return 0;
}
