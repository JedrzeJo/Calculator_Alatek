#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
void incrementer(int &a);

int main(){
	vector <string> vector_with_equations;
	
	fstream file;
	file.open("calc.txt", ios::in);

	if(!file.good()) {
	cout << "Cannot find such .txt file" << endl;
	exit(0);
	}

	string tmp_string;
	int amount_of_equations=0;

	while(!file.eof()){
	getline(file, tmp_string);
	vector_with_equations.push_back(tmp_string);
	incrementer(amount_of_equations);
	}

	//now i have a vector with my equations

/*	for(int i =0; i<vector_with_equations.size(); i++){		
	cout<<vector_with_equations[i]<<endl;					//wypluwa stringa z równaniem
	}
*/	
	//note: ASCII for digits <48-57>
	//ASCII code for "()*+-/": (40, )41, *42, +43, -45, /47
	for(int i =0; i<amount_of_equations; i++){
		char single_equation_tmp [100];											//local char array
		strcpy(single_equation_tmp, vector_with_equations.at(i).c_str());		//converting string to local char array
			for(int j=0; j<strlen(single_equation_tmp); j++){						//strlen returns charArray length
				cout<<single_equation_tmp[j];
			}
		cout<<endl;
	}
	
}

void incrementer(int &a){
		a++;
};
	



