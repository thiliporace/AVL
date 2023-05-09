#include "NodeAVL.h"
#include "Utils.h"
#include <sstream>
#include "Produto.h"
#include "AVL.h"
#include <iostream>
#include <string>
#include <algorithm>

void PrintStockValue(AVL *avl){
  float total_value = 0;
  NodeAVL *m_Root = avl->GetRoot();
  Produto produto(0,"",0,0);
  PrintStockValueInternal(produto,m_Root,total_value);
  std::cout << "Products stock value:" << total_value << "R$\n";
}

void PrintStockValueInternal(Produto produto,NodeAVL *node,float &total_value){
  if (node != nullptr){
    PrintStockValueInternal(produto,node->GetLeft(),total_value);
    produto = node->GetProduto();
    total_value = total_value + produto.GetValorUnitario()*produto.GetQntd();
    PrintStockValueInternal(produto,node->GetRight(),total_value);
  }
}

void PrintProductsBelow(AVL *avl){
  int qntdEntry;
  NodeAVL *m_Root = avl->GetRoot();
  Produto produto(0,"",0,0);
  std::cout << "Enter the desired amount:";
  std::cin >> qntdEntry;
  PrintProductsBelowInternal(produto,m_Root,qntdEntry);
}

void PrintProductsBelowInternal(Produto produto,NodeAVL *node,int qntdEntry){
  if (node != nullptr){
    produto = node->GetProduto();
    if (produto.GetQntd() < qntdEntry){
      std::cout << "\nProduct code:" << produto.GetCodigoProduto() << "\n"
      << "Product:" << produto.GetNome() << "\n"
      << "Quantity on stock:" << produto.GetQntd() << "\n"
      << "Price:" << produto.GetValorUnitario() << "\n";
    }
    PrintProductsBelowInternal(produto,node->GetLeft(),qntdEntry);
    PrintProductsBelowInternal(produto,node->GetRight(),qntdEntry);
  }
}

void PrintProductStockValue(AVL* avl) {
    std::string nameEntry;
    float result = 0;
    Produto produto(0, "", 0, 0);
    NodeAVL* m_Root = avl->GetRoot();
    std::cout << "Enter the desired product name:";
    getline(std::cin, nameEntry);
    std::transform(nameEntry.begin(), nameEntry.end(), nameEntry.begin(), ::toupper);
    PrintProductStockValueInternal(produto, m_Root, nameEntry, result);
}

void PrintProductStockValueInternal(Produto produto,NodeAVL *node,std::string nameEntry,float result) {
    if (node != nullptr) {
        int count_check = 0;
        produto = node->GetProduto();
        for (int i = 0; i < produto.GetNome().length(); i++) {
            if ((nameEntry.length() == produto.GetNome().length()) && (nameEntry[i] == produto.GetNome()[i]))
                count_check++;
        }
        if (count_check == nameEntry.length()) {
            result = produto.GetQntd() * produto.GetValorUnitario();
            std::cout << "The total value of " << nameEntry << " in stock is:" << result << "R$\n";;
        }
        else {
            PrintProductStockValueInternal(produto, node->GetLeft(), nameEntry, result);
            PrintProductStockValueInternal(produto, node->GetRight(), nameEntry, result);
        }
    }
}