#ifndef __PRODUTO_H__
#define __PRODUTO_H__

#include <string>

class Produto{
public:
  Produto(int codigoProduto,std::string nome,int qntd,float valorUnitario);
  ~Produto();

  void SetCodigoProduto(int a);
  int GetCodigoProduto();

  void SetNome(std::string a);
  std::string GetNome();

  void SetQntd(int a);
  int GetQntd();

  void SetValorUnitario(float a);
  float GetValorUnitario();

private:
  int codigoProduto;
  std::string nome;
  int qntd;
  float valorUnitario;
};

#endif