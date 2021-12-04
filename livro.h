#include<string>

using namespace std;

class Livro {

  private:
    string nome;
    string autor;
    int emprestado; //1=emprestado; 0=não esta emprestado
    string genero;
    int num_paginas;
    int ano_lancamento;
    int quantidade; //determina a quantidade de livros com o mesmo título 
    string dataEmprestadoInicio;
    string dataEmprestadoFim;
    string editora;//OK
    string emprestimo;//OK;

    public:
      Livro();
      Livro(string nome);
      ~Livro();
      void set_editora(string p_editora);//OK
      void set_nome(string p_nome);//OK
      void set_autor(string p_autor);//OK
      void set_emprestado(int p_emprestado);//OK;
      void set_genero(string p_genero);//OK;
      void set_numero_paginas(int p_num_paginas);//OK;
      void set_ano_lancamento(int p_ano_lancamento);
      void set_quantidade(int p_quantidade);
      void data_emprestado_inicio(string p_dataEmprestadoInicio);//data em que o livro foi emprestado
      void data_emprestado_fim(string p_dataEmprestadoFim);//data em que o livro foi devolvido
      int get_id();
      string get_nome();//OK
      string get_editora();//OK
      string get_autor();//OK
      int get_emprestado();//OK;
      string get_genero();//OK;
      int get_num_paginas();//OK;
      int get_ano_lancamento();//OK;
      string get_dataEmprestadoInicio();
      string get_dataEmprestadoFim();

};