#include<string>

using namespace std;

class Livro
{
private: string nome; string autor;
   int emprestado; //1=emprestado; 0=não esta emprestado
   string genero;
   int num_paginas;
   int ano_lancamento;
   int quantidade; //determina a quantidade de livros com o mesmo título 
   string dataEmprestadoInicio;
   string dataEmprestadoFim;
   string editora;
public:
   Livro(/* args */);
   ~Livro();
   void set_editora(string p_editora);
   void set_nome(string p_nome);
   void set_autor(string p_autor);
   void set_emprestado(int p_emprestado);
   void set_genero(string p_genero);
   void set_numero_paginas(int p_num_paginas);
   void set_ano_lancamento(int p_ano_lancamento);
   void set_quantidade(int p_quantidade);
   void data_emprestado_inicio(string p_dataEmprestadoInicio);//data em que o livro foi emprestado
   void data_emprestado_fim(string p_dataEmprestadoFim);//data em que o livro foi devolvido
   string get_nome();
   string get_autor();
   int get_emprestado();
   string get_genero();
   int get_num_paginas();
   int get_ano_lancamento();
   string get_dataEmprestadoInicio();
   string get_dataEmprestadoFim();
 
 
};
