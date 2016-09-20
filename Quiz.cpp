#include <assert.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <typeinfo>

#include "Score.h"
#include "Quiz.h"

using namespace std;
int Quiz::qCont=0;
//construtor do quiz, inicializando obj score e o arquivo file(onde estamos armazenando as perguntas)
Quiz::Quiz () : file("perguntas.txt"), score() {}
//destrutor do nosso quiz
Quiz::~Quiz () {
		delete this;
}
//criancao de um valor randomico 
int myrandom (int i) { return rand() % i; }

//funcao inicializadora
void Quiz::iniciar() {
//um loop para varrer o array de objetos e escrever as perguntas ( cada pergunta e um obj)
for (int x=0; x<qCont; x++) {
		fazPerguntas(perguntas_[x]);
	}
	fim();
}
// fucano fim, que permite o usuario refazer as questoes erradas
void Quiz::fim () {
	if (erros_.size()!= 0) {
	string ans, cont;

	cout << "Pontos : " << getScore() << "." << endl;
	cout << endl << "Iremos refazer as quetoes erradas: " << endl << endl;

	perguntas_ = erros_;
	erros_.clear();
	score.reset();
	system("pause");
	

	// Refazendo as perguntas erradas
	for (int x=0; x<perguntas_.size(); x++) {
	
	fazPerguntas(perguntas_[x]);

	}
	cout << "Pontos: " << getScore() << endl;
	system("pause");

	if (erros_.size()!= 0) {
	fim();
	}
	
}
}

	

//funcao criadora dos objetos a partir das informacoes alocadas no arquivo "pergutas.txt" 
void Quiz::getPerguntas(){
	if (file.fail()) {
		cout << "Erro ao pegar perguntas" << endl;
	} else {
		string keyword, resposta, pergunta;

		while (getline(file, keyword)) {
			getline(file, pergunta);
			if (keyword == "Questao") {
				string a,b,c,d;
				getline(file, a);
				getline(file, b); 
				getline(file, c);
				getline(file, d);
				getline(file, resposta);

				Question * q = new Question(pergunta, a, b, c, d, resposta);
				//alocando objeto do vetor perguntas_
				perguntas_.push_back(q);
				qCont++;
			}
		}
	}			//misturando a ordem dos objetos criados 
				random_shuffle (perguntas_.begin(), perguntas_.end(), myrandom);
}
//fucano que esccreve as perguntas e aloca pontuacao nos objetos
void Quiz::fazPerguntas(Question * &q){
	system("cls");
	string ans, cont;

	q->print();
	cin >> ans;
	
	if (ans == "EXIT") {
		cout << endl;
		fim();
		} else if (ans == q->resposta_) {
		cout << "Resposta Correta!" << endl;
		++score;
	} else {
		cout << "Errou! \nResposta certa: " << q->resposta_ << "." << endl;
		erros_.push_back(q);
	} cout << endl;
	system("pause");
	
}
// fucao que retorna pontuacao
int Quiz::getScore(){
	return score.score1;
}
