#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;

void incrementer(int &a);
int stringTOint(char table []);
bool isAnumber(char x);
int count(int a, int b, char x);

int main(){
	vector <string> vector_with_equations;

	//string a="(2+2)*2";
	string b="3+3*3";
	fstream newFile;
	newFile.open("equations.txt", ios::out);
	//newFile<<a<<endl;
	newFile<<b<<endl;
	newFile.close();


	fstream file;
	file.open("equations.txt", ios::in);

	if(!file.good()) {
	cout << "Cannot find such .txt file" << endl;
	exit(0);
	}

	string tmp_string;
	int amount_of_equations=-1;	// -1  because: while(!file.eof()) -> runs once more than lines number...

	while(!file.eof()){
	getline(file, tmp_string);
	vector_with_equations.push_back(tmp_string);
	incrementer(amount_of_equations);
	}

	//now i have a vector with my equations

/*	for(int i =0; i<vector_with_equations.size(); i++){		
	cout<<vector_with_equations[i]<<endl;					//string with equation being showed
	}
*/	
	//note: ASCII for digits <48-57>
	//note2: ASCII code for "()*+-/": (40, )41, *42, +43, -45, /47 
	for(int i =0; i<amount_of_equations; i++){
		char single_equation_tmp [100];										//local char array
		strcpy(single_equation_tmp, vector_with_equations.at(i).c_str());	//converting string to local char array
		//cout <<(int)single_equation_tmp[j]<<endl;	//chars to ASCII conversion corectness TEST
		cout << stringTOint(single_equation_tmp)<<endl;		//KEY POINT - my function
	}
}

int stringTOint(char table []){
	int sum=0;
	list<char> outsideBRACKETSlist;
	list<char> insideBRACKETSlist;
	stack<char> outsideBRACKETSstack;
	stack<char> insideBRACKETSstack;

	for (int i=0; table[i]!=NULL; i++){


		if(table[i]=='('){
			for(int j=i;table[j]!=')';j++){
				if(isAnumber(table[j])){
				insideBRACKETSlist.push_front(table[j]);
				}
				else if(table[j]=='+' || table[j]=='-' || table[j]=='*' || table[j]=='/'){
				insideBRACKETSstack.push(table[j]);
				}
				//......to be continued
			}
		}

		else if(isAnumber(table[i])){
			outsideBRACKETSlist.push_front(table[i]);
		}
		else if(table[i]=='+' || table[i]=='-' || table[i]=='*' || table[i]=='/'){
			outsideBRACKETSstack.push(table[i]);
		}
	}
	//counting what's outside of the brackets
		do {
				char x = outsideBRACKETSlist.front();
				int a = (int)x - 48;						//conversion from ASCII
				outsideBRACKETSlist.pop_front();
				char y = outsideBRACKETSlist.front();
				int b = (int)y - 48;						//conversion from ASCII
				outsideBRACKETSlist.pop_front();
				char operation = outsideBRACKETSstack.top();
				outsideBRACKETSstack.pop();
				if(outsideBRACKETSstack.top()=='/' || outsideBRACKETSstack.top()=='*'){
					char operation2 = outsideBRACKETSstack.top();
					outsideBRACKETSstack.pop();
					char z = outsideBRACKETSlist.front();
					int c = (int)z - 48;					//conversion from ASCII
					outsideBRACKETSlist.pop_front();
					b = count(c, b, operation2);
				}
				sum = count(b, a, operation);
		} while(false);


	return sum;
}

bool isAnumber(char x){
	if((int)x>=48 && (int)x<=57){return true;} 		//48 and 57 ASCII code of digits
	else {return false;}
}

void incrementer(int &a){
		a++;
};

int count(int a, int b, char x){
	switch(x){
	case '-': return a-b; break;
	case '+': return a+b; break;
	case '*': return a*b; break;
	case '/': return a/b; break;
	}

}
