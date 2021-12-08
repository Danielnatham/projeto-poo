//Controle e Gerenciamento de uma Biblioteca.
#include<vector>
#include<string>
#include<iostream>

#include "livro.h"
 
using namespace std;

class Usuario
{
   private:
      string cpf;
      string nome;
      string datanascimento;
      vector<Livro> livrosemprestados;
      int adimplencia; //Se 0 esta ok, se 1 esta inadimplente

   public:

      Usuario();

      Usuario(string p_nome, string p_cpf, string p_data_nascimento);

      ~Usuario();

      vector<Livro> livrosemprestadosUsuario();//determina quais livros estao com o usuario

      string get_cpf(){
         return cpf;
      };

      string get_nome();

      void set_livro(Livro livro);

      void unset_livro(Livro livro);

      string get_datanascimento(){
         return datanascimento;
      };
};

Usuario::Usuario(){

}

Usuario::Usuario(string p_nome, string p_cpf, string p_data_nascimento){
   nome = p_nome;
   cpf = cpf;
   datanascimento = p_data_nascimento;
}
 
Usuario::~Usuario()
{
}

string Usuario::get_nome(){
   return nome;
}

vector<Livro> Usuario::livrosemprestadosUsuario(){
	return livrosemprestados;
}

void Usuario::set_livro(Livro livro){
   livrosemprestados.push_back(livro);
}

void Usuario::unset_livro(Livro livro){
    auto index = livrosemprestados.begin();
    for(auto & li : livrosemprestados){
        if(li.get_nome() == livro.get_nome()){
	    livrosemprestados.erase(index);
	}
	++index;
    }
}

class Biblioteca
{
private:
   vector<Livro> livros;
   vector<Usuario> usuarios;
public:
   Biblioteca(/* args */);
   ~Biblioteca();
   //CRUD
   void Create_Livro(Livro livro){
      livros.push_back(livro);
   };//poe livro(s) na biblioteca

   void Create_Usuario(Usuario user){
      usuarios.push_back(user);
   }

   void Read(int op, string nome){
      
      if(op == 1){
         int contador = 0;
         for (int i = 0; i <= livros.size() - 1; i++ ){
            string nome_objeto = livros.at(i).get_nome();
            if(nome == nome_objeto){
               contador++;
               cout << "Livro - ID: " << i <<" | Nome:"<< nome_objeto << endl;
            }
            
         }
         if (contador == 0){
            cout << "Livro " << nome << " não encontrado nessa biblioteca." << endl;
         }   
      }

      if(op == 0){
         int contador = 0;
         for (int i = 0; i <= usuarios.size() - 1; i++ ){
            string nome_objeto = usuarios.at(i).get_nome();
            if(nome == nome_objeto){
               contador++;
               cout << "Usuario - ID: " << i <<" | Nome:"<< nome_objeto << endl;
            }
            
         }
         if (contador == 0){
            cout << "Usuario " << nome << " não encontrado nessa biblioteca." << endl;
         }   
      }


   };//consulta um livro ou um usuario

   void ShowALL(int op){

      if (op == 1){
         for (int i = 0; i <= livros.size() - 1; i++ ){
            string nome = livros.at(i).get_nome();
            cout << "Livro - ID: " << i <<" | Nome: "<< nome << endl;
         }   
      }

       else if (op == 0){
          for (int i = 0; i <= usuarios.size() - 1; i++ ){
             string nome = usuarios.at(i).get_nome();
             cout << "Usuario - ID: " << i <<" | Nome: "<< nome << endl;
         }
      }

      else {
         cout << "Operação Invalida" << endl;
      }

   };//mostra todos os livros ou todos os usuarios da biblioteca
   
   void Update(int id){

   };//atualiza dados do livro ou do usuario
   
   void Delete(int op,int id){
      int novo_id = id;
      if(op == 1){
         Livro livro = livros.at(id);
         livros.erase(livros.begin()+novo_id);
         cout << "Livro " << livro.get_nome() << " removido com sucesso" << endl;
      }
      if(op == 0){
         Usuario user = usuarios.at(id);
         usuarios.erase(usuarios.begin()+novo_id);
         cout << "Usuario " << user.get_nome() << " removido com sucesso" << endl;

      }
      else{
         cout << "Operação Invalida" << endl;
      }
   };//deleta livro(s) ou usuario(s)
   
   
   void Emprestar(int id_usr, int id_lvr){
      usuarios.at(id_usr).set_livro(livros.at(id_lvr));
      livros.at(id_lvr).set_emprestado(1);
      cout << "Livro : " << livros.at(id_lvr).get_nome() << " Emprestado para: " << usuarios.at(id_usr).get_nome() << endl;
   };//empresta livro(s). O(s) livro(s) emprestado(s) passa/passam para status de emprestado e o usuario passa a ter o(s) livro(s) em seu historico de livros adquiridos da biblioteca. 
   
   
   void Devolucao(int id_usr, int id_lvr){
	   usuarios.at(id_usr).unset_livro(livros.at(id_lvr));
	   livros.at(id_lvr).set_emprestado(0);
   };//Status do(s) livro(s) deixa/ deixam de ser emprestado e o usuario deixa de ter aquele(s) livro(s) em seu historico
   
   
   void Adimplencia(int id_usr){
	   
   };//ver se o usuario possui algum livro em que ja se passou o prazo para entregar. Se sim, nao podera pegar outro livro emprestado
   
   void relatorio_estatistico(){
      cout << "------LISTA DE LIVROS--------" << endl;
      ShowALL(1);
      cout << "-------LISTA DE USUARIOS-------" << endl;
      ShowALL(0);
   };
};
 
Biblioteca::Biblioteca(/* args */)
{
}
 
Biblioteca::~Biblioteca()
{
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

class Item 
{
private:
    string titulo;
    string autor;
    string data_publicacao;
public:
    Item();

    ~Item();

    string get_titulo();

    string get_autor();

    string get_data_publicacao();

};

Item::Item(){}

Item::~Item(){}

string Item::get_titulo(){
	return titulo;
}

string Item::get_autor(){
	return autor;
}

string Item::get_data_publicacao(){
	return data_publicacao;
}

class Periodico: public Item
{
public:

   Periodico(string titulo);
  
   ~Periodico();

};

Periodico::Periodico(string titulo)
{
   titulo = titulo;
}

Periodico::~Periodico()
{
}

class Monografia: public Item
{ 
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

int main(int argc, char const *argv[])
{
   Biblioteca a;

   Livro primeiro, segundo ;
   Usuario jose("Jose", "123", "22031998"), mario("Mario", "123", "22031998"), carlos("Carlos", "123", "22031998");
   Monografia mono("Primeira Monografia");

   primeiro.set_nome("Manual");
   segundo.set_nome("Xadrez");

   cout << "Minha monografia: " << mono.get_titulo() << endl;	

   a.Create_Livro(primeiro);
   a.Create_Livro(segundo);
   a.ShowALL(1);

   a.Create_Usuario(jose);
   a.Create_Usuario(mario);
   a.Create_Usuario(carlos);
   a.ShowALL(0);

   a.Read(1, "Xadrez");
   a.Read(1, "Magnos");

   a.Read(0, "Jose");
   a.Read(0, "Mario");
   a.Read(0, "Carlos");

   a.Delete(0,2);
   a.Read(0,"Carlos");

   a.Emprestar(0,0);
   a.Emprestar(0,1);	

   a.relatorio_estatistico();

   return 0;
}

