#ifndef QUIZ_H
#define QUIZ_H
#include <fstream>
#include <vector>

#include "Score.h"
#include "Question.h"
// classe quiz
class Quiz {
	// Private section
	public:
		Quiz();
		~Quiz();
		
		//metoodos void de quiz
		
		void iniciar();
		void fim();
		void getPerguntas();
		void fazPerguntas(Question * &q);
		int getScore();
		
		// Public Declarations
	private:
		std::ifstream file;
		Score score;
		//vetor de perguntas e de erros, para permitir que o usuario refazer as erraas
		std::vector<Question *> perguntas_;
		std::vector<Question *> erros_;
	static int qCont;
};

#endif
