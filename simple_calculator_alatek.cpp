#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
void incrementer(int &a);
int countString(char table []);

int main(){
	vector <string> vector_with_equations;

/*	string a="(2+2)*2";
	string b="3+3*3";
	fstream newFile;
	newFile.open("equations.txt", ios::out);
	newFile<<a<<endl;
	newFile<<b<<endl;
	newFile.close();
*/

	fstream file;
	file.open("equations.txt", ios::in);

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
		char single_equation_tmp [100];										//local char array
		strcpy(single_equation_tmp, vector_with_equations.at(i).c_str());	//converting string to local char array
			for(int j=0; j<strlen(single_equation_tmp); j++){				//strlen returns charArray length
				//cout<<single_equation_tmp[j]; //tutaj mam równania w charze teraz nasza funkcja wjezdza
				//cout << countString(single_equation_tmp)<<endl;
				//cout <<(int)single_equation_tmp[j]<<endl;	//chars to ASCII conversion corectness TEST
			}
		cout<<endl;
	}
	
}

int countString(char table []){
	int result=0;
	vector <char> operation;
	vector <int> number;
	vector <char> brackets;

	for (int i=0; table[i]!=NULL; i++){

	}


	return result;
}

void incrementer(int &a){
		a++;
};
