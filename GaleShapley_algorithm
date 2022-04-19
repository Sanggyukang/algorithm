#include <iostream>

using namespace std;

void man_propose(int men[][4], int women[][4]);

void woman_propose(int men[][4], int women[][4]);

int main() {

	int men[4][4] = { {2,3,4,1},{1,4,2,3},{1,3,4,2},{2,1,3,4} };				// example data 
	int women[4][4] = { {1,3,2,4},{2,1,4,3},{1,3,2,4},{4,1,3,2} };

	//int men[5][5] = { {2,3,4,5,1},{1,4,5,2,3},{1,5,4,3,2},{2,1,3,4,5},{4,3,5,1,2} };		//example data from note 5
	//int women[5][5] = { {5,3,2,1,4},{2,1,4,5,3},{1,5,2,3,4},{4,1,3,2,5},{3,4,1,2,5} };

	//man_propose(men, women);
	woman_propose(men, women);

	return 0;
}

void man_propose(int men[][4], int women[][4]) {

	int new_women[4] = {};

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			new_women[women[i][j] - 1] = j + 1;
		}
		memcpy(women[i], new_women, sizeof(new_women));
	}

	int men_propose_index[5] = {};												// each man's proposal index. i.e. first round every man's proposal index = 0 , and if some man was rejected, increase one index for the next proposal

	int men_proposed_index[5] = {};												// whether each man succeeded in a proposal. i.e. 0 = need to propose, 1 = matched.

	int women_proposed_index[5] = {};											// the last three array's index is represented by each man or woman. This array for saving man's number that succeeds in the proposal. i.e. 1st man propose to 2nd woman and if they are matched then women_proposed_index[1]=1;    

	int round = 1;

	int end = 0;																// end count : when end = 4(all men succeeds to propose) then while loop will be ended.

	while (end < 4) //{5x5} end<5 , {4x4} end<4
	{
		cout << round << ". Round" << endl << endl;
		for (int i = 0; i < 4; ++i) {		//{5x5} i<5 , {4x4} i<4
			if (men_proposed_index[i] == 0) {														// if men_proposed_index[i] != 0 which means the man succeeds to propose
				int choose = men[i][men_propose_index[i]];
				cout << "m" << i + 1 << " proposes to w" << choose << endl;
				if (women_proposed_index[choose-1] != 0){
					if (women[choose - 1][i] <= women_proposed_index[choose - 1]) {
						int previous_proposed = women_proposed_index[choose - 1];
						men_propose_index[previous_proposed - 1]++;
						men_proposed_index[previous_proposed - 1]--;
						cout << "m" << previous_proposed << " is rejected by w" << choose << endl;
						cout << "m" << i + 1 << " is engaged with w" << choose << endl;
						men_proposed_index[i]++;
						women_proposed_index[choose - 1] = i + 1;
					}
					else {
						men_propose_index[i]++;
						cout << "m" << i + 1 << " is rejected by w" << choose << endl;
					}
				}
				else {
					cout << "m" << i + 1 << " is engaged with w" << choose << endl;
					men_proposed_index[i]++;
					women_proposed_index[choose - 1] = i + 1;
					end++;
				}

			}
		}
		round++;
		cout << endl;
	}

	for (int i = 0; i < 4; ++i)		//{5x5} i<5 , {4x4} i<4
		cout << "( " << "w" << i + 1 << " , " << "m" << women_proposed_index[i] << " )" << endl;

}
void woman_propose(int men[][4], int women[][4]) {

	int new_men[4] = {};

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			new_men[women[i][j] - 1] = j + 1;
		}
		memcpy(men[i], new_men, sizeof(new_men));
	}
	int women_propose_index[5] = {};

	int women_proposed_index[5] = {};

	int men_proposed_index[5] = {};

	int round = 1;

	int end = 0;

	while (end < 4) //{5x5} end<5 , {4x4} end<4
	{
		cout << round << ". Round" << endl << endl;
		for (int i = 0; i < 4; ++i) {		//{5x5} i<5 , {4x4} i<4
			if (women_proposed_index[i] == 0) {														
				int choose = women[i][women_propose_index[i]];
				cout << "m" << i + 1 << " proposes to w" << choose << endl;
				if (men_proposed_index[choose-1] != 0){
					if (men[choose - 1][i] <= men_proposed_index[choose - 1]) {
						int previous_proposed = men_proposed_index[choose - 1];
						women_proposed_index[previous_proposed - 1]++;
						women_proposed_index[previous_proposed - 1]--;
						cout << "m" << previous_proposed << " is rejected by w" << choose << endl;
						cout << "m" << i + 1 << " is engaged with w" << choose << endl;
						women_proposed_index[i]++;
						men_proposed_index[choose - 1] = i + 1;
					}
					else {
						women_propose_index[i]++;
						cout << "m" << i + 1 << " is rejected by w" << choose << endl;
					}
				}
				else {
					cout << "m" << i + 1 << " is engaged with w" << choose << endl;
					women_proposed_index[i]++;
					men_proposed_index[choose - 1] = i + 1;
					end++;
				}

			}
		}
		round++;
		cout << endl;
	}

	for (int i = 0; i < 4; ++i)		//{5x5} i<5 , {4x4} i<4
		cout << "( " << "m" << i + 1 << " , " << "w" << men_proposed_index[i] << " )" << endl;
