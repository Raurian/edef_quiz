#ifndef SCORE_H
#define SCORE_H
// classe escore onde e feita a pontuacao do usuario
class Score {
	//sobrecarga de operando para fazer o incremento da pontuacao
	friend Score& operator++(Score& s) {
	s.score1 += 1;
	return s;
}	
	public:
		Score() : score1(0){
		}
		void reset(){
			score1=0;
		}
		int score1;

		// Public Declarations
	private:
		// Protected Declarations
};

#endif
