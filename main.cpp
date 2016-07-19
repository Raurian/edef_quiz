//
//  main.cpp
//  Quiz
//
//  Created by Samuel Silva on 14/06/16.
//  Copyright (c) 2016 Samuel Silva. All rights reserved.
//

#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;

class Quiz{
public:
    std::string comando;
    std::string alternativa_correta;

};

int main() {
    // Instanciações
    Quiz questao1;
    Quiz questao2;
    
    questao1.comando = "Como é possivel comparar numeros inteiros em C++?\na - compare()\nb - ==\nc - !=\nd - strcmp()\ne - >=";
    questao1.alternativa_correta = "b";

    questao2.comando = "Pra que serve o std::cin?\na - Entrada de Dados\nb - Saída de dados\nc - Comparação\nd -Construtor\ne - Exibir erros";
    questao2.alternativa_correta = "a";
    
    // Fim das Instanciações
    
    Quiz perguntas[2] = {questao1, questao2};
    
    int i;
    for (i=0; i<=2; i++) {

        cout << perguntas[i].comando << endl;
        
        std::string resposta;
        cin >> resposta;
        
        if (perguntas[i].alternativa_correta.compare(resposta) == 0){
            cout << "Certo" << endl;
        }else{
            cout << "errado" << endl;
        }
    }

    return 0;
}
