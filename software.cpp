//Controle e Gerenciamento de uma Biblioteca.
#include<vector>
#include<string>

#include "Livro.h"
 
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
   void Create();//poe livro(s) na biblioteca
   void Read();//consulta um livro ou um usuario
   void ShowALL();//mostra todos os livros ou todos os usuarios da biblioteca
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
   Usuario(string p_cpf, string p_nome, string p_datanascimento);
   ~Usuario();
   void livrosemprestadosUsuario();//determina quais livros estao com o usuario
   string get_cpf();
   string get_nome();
   string get_datanascimento();
};
 
Usuario::Usuario(string p_cpf, string p_nome, string p_datanascimento){
 
}
 
Usuario::~Usuario()
{
}

class Emprestimo
{
private:
   /* data */
public:
   Emprestimo(/* args */);
   ~Emprestimo();
};

Emprestimo::Emprestimo(/* args */)
{
}

Emprestimo::~Emprestimo()
{
}

class Reserva
{
private:
   /* data */
public:
   Reserva(/* args */);
   ~Reserva();
};

Reserva::Reserva(/* args */)
{
}

Reserva::~Reserva()
{
}


class Periodico
{
private:
   /* data */
public:
   Periodico(/* args */);
   ~Periodico();
};

Periodico::Periodico(/* args */)
{
}

Periodico::~Periodico()
{
}

class Monografia
{
private:
   /* data */
public:
   Monografia(/* args */);
   ~Monografia();
};

Monografia::Monografia(/* args */)
{
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
   return 0;
}

