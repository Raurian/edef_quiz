#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
using namespace std;
// classe question, classe de cada pergunta criada no quiz

class Question {

public:
	Question (string q, string a, string b,string c,string d, string ans)
	: a_(a), b_(b), c_(c), d_(d) ,pergunta_(q), resposta_(ans) {}

	// Accessors
	std::string a() const {return a_;}
	std::string b() const {return b_;}
	std::string c() const {return c_;}
	std::string d() const {return d_;}
	std::string q() const {return pergunta_;}
	std::string ans() const {return resposta_;}
	std::string pergunta_;
	std::string resposta_;
	
		void print () const {
		cout << "Pergunta: " << pergunta_ << std::endl;
		cout << a_ << std::endl << b_ << std::endl;
		cout << c_ << std::endl << d_ << std::endl;
		cout << "Resposta: ";
	}

private:
	string a_;
	string b_;
	string c_;
	string d_;
	

};

#endif

