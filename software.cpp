//Controle e Gerenciamento de uma Biblioteca.
#include<vector>
#include<string>
#include<iostream>

#include "livro.h"
 
using namespace std;

class Usuario;


class Biblioteca
{
private:
   vector<Livro> livros;
   vector<Usuario> usuarios;
public:
   Biblioteca(/* args */);
   ~Biblioteca();
   //CRUD
   void Create(Livro livro){
      livros.push_back(livro);
   };//poe livro(s) na biblioteca

   void Read(int op){

   };//consulta um livro ou um usuario

   void ShowALL(int op){

      if (op == 1){
         for (int i = 0; i <= livros.size() - 1; i++ ){
            string nome = livros.at(i).get_nome();
            cout << "Livro " << i <<" "<< nome << endl;
         }   
      }

      // else if (op == 0){
      //    for (int i = 0; i < usuarios.size() - 1; i++ ){
      //       string nome = usuarios.at(i).get_nome();
      //       cout << "Usuario: " << nome << endl;
      //    }
      // }

      else {
         cout << "Operação Invalida" << endl;
      }

   };//mostra todos os livros ou todos os usuarios da biblioteca
   void Update();//atualiza dados do livro ou do usuario
   void Delete();//deleta livro(s) ou usuario(s)
   void Emprestar();//empresta livro(s). O(s) livro(s) emprestado(s) passa/passam para status de emprestado e o usuario passa a ter o(s) livro(s) em seu historico de livros adquiridos da biblioteca. 
   void Devolucao();//Status do(s) livro(s) deixa/ deixam de ser emprestado e o usuario deixa de ter aquele(s) livro(s) em seu historico
   void Adimplencia();//ver se o usuario possui algum livro em que ja se passou o prazo para entregar. Se sim, nao podera pegar outro livro emprestado
   void relatorio_estatistico();
};
 
Biblioteca::Biblioteca(/* args */)
{
}
 
Biblioteca::~Biblioteca()
{
}

 
class Usuario
{
   private:
      string cpf;
      string nome;
      string datanascimento;
      vector<Livro> livrosemprestados;
   
   public:

      Usuario();

      Usuario(string p_cpf, string p_nome, string p_datanascimento);

      ~Usuario();
      void livrosemprestadosUsuario();//determina quais livros estao com o usuario

      string get_cpf(){
         return cpf;
      };

      string get_nome();

      string get_datanascimento(){
         return datanascimento;
      };
};

Usuario::Usuario(){

}
 
Usuario::Usuario(string p_cpf, string p_nome, string p_datanascimento){
      cpf = p_cpf;
      nome = p_nome;
      datanascimento = p_datanascimento;
}
 
Usuario::~Usuario()
{
}

string Usuario::get_nome(){
   return nome;
}

class Emprestimo
{
   private:
      Usuario usuarioNome;
      string dataEmprestimo;
      Livro livro; 
      
   public:

      Emprestimo(string p_dataemprestimo,Usuario userName , Livro p_livro);
      ~Emprestimo();

      string emprestimo_toString(){
         return "Livro " + livro.get_nome() + " emprestado a " + usuarioNome.get_nome() + " Até dia " + dataEmprestimo;
      }
};

Emprestimo::Emprestimo(string p_dataemprestimo,Usuario usuarioNome, Livro p_livro){
   dataEmprestimo = p_dataemprestimo;
   usuarioNome = usuarioNome;
   livro = p_livro;
}

Emprestimo::~Emprestimo()
{
}

class Reserva
{
private:
   string dataEmprestimo;
   Usuario usuarioNome;
   Livro livroReservado; 
public:
   Reserva(string p_dataemprestimo,Usuario userName , Livro p_livro);
   ~Reserva();

    string reserva_toString(){
         return "Livro " + livroReservado.get_nome() + " reservado a " + usuarioNome.get_nome() + " Até dia " + dataEmprestimo;
      }
};

Reserva::Reserva(string p_dataemprestimo,Usuario userName , Livro p_livro)
{
   dataEmprestimo = p_dataemprestimo;
   usuarioNome = userName;
   livroReservado = p_livro;
}

Reserva::~Reserva()
{
}


class Periodico
{
private:
   string titulo;
   Usuario autor;
   string data_publicacao;

public:

   Periodico(string titulo);
   ~Periodico();

   string get_titulo(){
      return titulo;
   }

   
};

Periodico::Periodico(string titulo)
{
   titulo = titulo;
}

Periodico::~Periodico()
{
}

class Monografia
{
private:
   string titulo;
   Usuario autor;
   string data_publicacao;
public:
   Monografia(string titulo);
   ~Monografia();
};

Monografia::Monografia(string titulo)
{
   titulo = titulo;
}

Monografia::~Monografia()
{
}

class Item
{
private:
   /* data */
public:
   Item(/* args */);
   ~Item();
};

Item::Item(/* args */)
{
}

Item::~Item()
{
}

int main(int argc, char const *argv[])
{
   Biblioteca a;
   Livro primeiro, segundo ;

   primeiro.set_nome("Manual");
   segundo.set_nome("Xadrez");


   a.Create(primeiro);
   a.Create(segundo);
   a.ShowALL(1);

   return 0;
}

