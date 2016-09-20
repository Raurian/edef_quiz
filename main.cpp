#include <iostream>
#include <string>
#include <fstream>

#include "Quiz.h"

using namespace std;
std::ofstream myfile("perguntas.txt",ios::app );


void iniciarQuiz(Quiz * &c){
				c->getPerguntas();
				c->iniciar();
				
	
}

main(){                               
	Quiz * q = new Quiz();
	string text, a1,b1,c1,d1,re;
	int continua=0;
	while (continua ==0 ) {
		cout << "1)Jogar"<< endl;
		cout << "2)Acrescentar pergunta" <<endl;
		cout << "3)Sair" << endl;
		int op;
		cin>>op;
		switch(op){
			case 1:
				iniciarQuiz(q);
				break;
			case 2:
				myfile << "Questao\n";
						   		cin.ignore();
								cout << "Digite comando da questao: "<<endl;
								getline (cin,text);
			   					myfile << text <<"\n";
							    cout << "Digite a alternativa A " << endl;
			   			  		getline (cin,a1) ;
								myfile << "a)" <<a1<<"\n";
								cout << "Digite a alternativa B " << endl;
			   			  		getline (cin,b1) ;
								myfile << "b)" <<b1<<"\n";
								cout << "Digite a alternativa C " << endl;
			   			  		getline (cin,c1) ;
								myfile << "c)" <<c1<<"\n";
								cout << "Digite a alternativa D " << endl;
			   			  		getline (cin,d1) ;
								myfile << "d)" <<d1<<"\n";
								cout << "Digite a letra da alternatica correta ( em maiusculo) " << endl;
			   			  		getline (cin,re) ;
								myfile <<re<<"\n";

								break;
			case 3:
			continua=1;
			break;
				
		}

system("cls");	
}
delete q;
return 0;
}
