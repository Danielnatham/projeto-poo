#include<string>
#include<iostream>
#include<stdlib.h>

#include "livro.h"

using namespace std;

 
Livro::Livro(/* args */){
   
}
 
Livro::~Livro()
{
}

//Editora
    void Livro::set_editora(string p_editora){
        editora = p_editora;
    }
    string Livro::get_editora()
    {
    return editora;
    }
//

//Nome
  void Livro::set_nome(std::string p_nome){
    nome = p_nome;
  }

  string Livro::get_nome()
  {
    return nome;
  }
//

//Autor
  void Livro::set_autor(std::string p_autor)
  {
    autor = p_autor;
  }

  string Livro::get_autor()
  {
    return autor;
  }
//

//Emprestado
  void Livro::set_emprestado(int p_emprestado)
  {
    emprestado = p_emprestado;
  
  }

  int Livro::get_emprestado()
  {
    return emprestado;
  }
//

//Genero
 void Livro::set_genero(string p_genero)
 {
   genero = p_genero;
 }

 string Livro::get_genero()
 {
   return genero;
 }
//

//Numero De Paginas
  void Livro::set_numero_paginas(int p_num_paginas)
  {
    num_paginas = p_num_paginas;
  }

  int  Livro::get_num_paginas()
  {
    return num_paginas;
  }
//

//Ano Lançamento
  void Livro::set_ano_lancamento(int p_ano_lancamento)
  {
    ano_lancamento = p_ano_lancamento;
  }

  int Livro::get_ano_lancamento()
  {
   return ano_lancamento;
  }

//
