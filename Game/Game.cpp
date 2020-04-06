///Tim Kuelker
//Final Assignment
//May 8th, 2017

#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

using namespace std;

class Game{

	private:

		char ops[4];
		int points, upper, lower, num, a, b, range;
		char choice;
		string ans;
		double duration;

	public:

		Game(){
			ops[0]='+';
			ops[1]='-';
			ops[2]='x';
			ops[3]='/';
			points=0;
			choice='s';
			upper=-1;
			lower=-1;
			ans = '0';
			a=1;
			b=2;
		}

		int start(){
			chooseOp();
			inputBounds();
			mainLoop();
		}

		void chooseOp(){
			while(choice!='+'&&choice!='-'&&choice!='x'&&choice!='/'){
				cout<<"\tPlease choose a sign to practice('+','-','x','/')\n\t\tor 'q' to quit at anytime: ";
				cin>>choice;
			}
		}

		void inputBounds(){
			while(lower<0){
				cout<<"Input the lowest number you can (+,-,*,/): ";
				cin>>lower;
			}
			while(lower>(upper+1)){
				cout<<"Input the highest number you can (+,-,*,/): ";
				cin>>upper;
			}
			range = upper-lower;
		}

		void flash_red_add(){
			  points-=1;
			  system("COLOR 40");
			  cout << "\tCorrect answer is: " << a << " + " << b << " = " << a + b <<"\n\n";
			  Sleep (1200);
        	  system("CLS");
		}

		void flash_red_sub(){
			  points-=1;
			  system("COLOR 40");
			  cout << "\tCorrect answer is: " << a << " - " << b << " = " << a - b <<"\n\n";
			  Sleep (1200);
        	  system("CLS");
		}

		void flash_red_mul(){
			  points-=1;
			  system("COLOR 40");
			  cout << "\tCorrect answer is: " << a << " * " << b << " = " << a * b <<"\n\n";
			  Sleep (1200);
        	  system("CLS");
		}

		void flash_red_div(){
			  points-=1;
			  system("COLOR 40");
			  cout << "\tCorrect answer is: " << a << " / " << b << " = " << a / b <<"\n\n";
			  Sleep (1200);
        	  system("CLS");
		}

		void flash_green(){
			  points+=1;
			  system ("COLOR 20");
			  cout << "\t\tCORRECT!!";
			  Sleep (1000);
			  system("CLS");
		}
		void flash_back(){
		    system ("COLOR 07");
			system("CLS");
		}

		void pAddition(){
			while(ans!="q"){
				cout<<"\nPoints Accumulated: "<<points<<"\n"<<endl;
				a = rand()%range + lower;
				b = rand()%range + lower;
				cout<<" "<<a<<" + "<<b<<" = ";
				clock_t start = clock();
				cin>>ans;
				duration+=(clock()-start)/(double) CLOCKS_PER_SEC;
				stringstream ss(ans);
				ss>>num;
				if((a+b)!=num)
					flash_red_add();
				else
					flash_green();
				flash_back();
			}
		}
		void pMultiplication(){
			while(ans!="q"){
				cout<<"\nPoints Earned: "<<points<<"\n"<<endl;
				a = rand()%range + lower;
				b = rand()%range + lower;
				cout<<" "<<a<<" x "<<b<<" = ";
				clock_t start = clock();
				cin>>ans;
				duration+=(clock()-start)/(double) CLOCKS_PER_SEC;
				stringstream ss(ans);
				ss>>num;
				if((a*b)!=num)
					flash_red_mul();
				else
					flash_green();
				flash_back();
			}
		}
		void pSubtraction(){
			while(ans!="q"){
				cout<<"\nPoints Earned: "<<points<<"\n"<<endl;
				a = rand()%range + lower;
				b = rand()%range + lower;
				while((a-b)<=0){
					a = rand()%range + lower;
					b = rand()%range + lower;
				}
				cout<<" "<<a<<" - "<<b<<" = ";
				clock_t start = clock();
				cin>>ans;
				duration+=(clock()-start)/(double) CLOCKS_PER_SEC;
				stringstream ss(ans);
				ss>>num;
				if((a-b)!=num)
					flash_red_sub();
				else
					flash_green();
				flash_back();
			}
		}

		void pDivision(){
			while(ans!="q"){
				cout<<"\nPoints Earned: "<<points<<"\n"<<endl;
				a = rand()%range + lower;
				b = rand()%range + lower;
				while((a%b)!=0){
					a = rand()%range + lower;
					b = rand()%range + lower;
				}
				cout<<" "<<a<<" / "<<b<<" = ";
				clock_t start = clock();
				cin>>ans;
				duration+=(clock()-start)/(double) CLOCKS_PER_SEC;
				stringstream ss(ans);
				ss>>num;
				if((a/b)!=num)
					flash_red_div();
				else
					flash_green();
				flash_back();
			}
		}
		void checkRank(string fn){
			string line;
			string u_names[3];
			float scores[3];
			float final_score = points/duration;
			ifstream myFile(fn);
			if(myFile.is_open()){
				for(int i=0;i<3;i++){
				    getline(myFile,line);
					stringstream ss(line);
					ss>>u_names[i]>>scores[i];
				}
				myFile.close();
			}
			for(int i=0;i<3;i++){
				if(final_score>scores[i]){
					cout<<"Enter you name for possible High Score: ";
					cin>>u_names[i];
					scores[i]=final_score;
					break;
				}
			}
			cout<<"The top three on the leaderboard are: "<<endl;
			cout<<u_names[0]<<" "<<scores[0]<<endl;
			cout<<u_names[1]<<" "<<scores[1]<<endl;
			cout<<u_names[2]<<" "<<scores[2]<<endl;
			Sleep(5000);
			ofstream myfile(fn);
			if(myfile.is_open()){
				for(int i=0;i<3;i++)
					myfile<<u_names[i]<<" "<<scores[i]<<endl;
				myfile.close();
			}
		}
		void mainLoop()
		{
			if(choice=='+'){
				pAddition();
				checkRank("addHighScore.txt");
			}
			else if(choice=='x'){
				pMultiplication();
				checkRank("subHighScore.txt");
			}
			else if(choice=='-'){
				pSubtraction();
				checkRank("mulHighScore.txt");
			}
			else{
				pDivision();
				checkRank("divHighScore.txt");
			}
		}
};

int main(){
    string rerun;
do {
    system("CLS");
	Game g;
	g.start();
        cout << "\n\nWould you like to re run the program <Yes, No>\n\n";
        cin >> rerun;
    }
    while (rerun=="yes" || rerun=="Yes" || rerun=="YEs" || rerun=="YES");
	cout << "\n\nOne ring to rule them all, One ring to find them, One ring to bring them all and in the darkness bind them\n\nDon't let the darkness bind you.\n\nFor the night is dark and full of terrors.\n\nWait...thats not right.\n\n";

	return 0;
}

