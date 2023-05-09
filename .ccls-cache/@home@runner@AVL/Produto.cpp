#include <string>
#include <sstream>
#include "Produto.h"

Produto::Produto(int cod_prod,std::string name,int quantity,float price)
  : codigoProduto(cod_prod)
  , nome(name)
  , qntd(quantity)
  , valorUnitario(price)
{}

Produto::~Produto(){}

void Produto::SetCodigoProduto(int a){
  Produto::codigoProduto = a;
}

int Produto::GetCodigoProduto(){
  return Produto::codigoProduto;
}

void Produto::SetNome(std::string a){
  Produto::nome = a;
}

std::string Produto::GetNome(){
  return Produto::nome;
}

void Produto::SetQntd(int a){
  Produto::qntd = a;
}

int Produto::GetQntd(){
  return Produto::qntd;
}

void Produto::SetValorUnitario(float a){
  Produto::valorUnitario = a;
}

float Produto::GetValorUnitario(){
  return Produto::valorUnitario;
}
