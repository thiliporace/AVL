// mainAVL.cpp

// Lucas Goulart de Farias Meres - 42127459
// Thiago Leandro Liporace - 42128481

#include <iostream>
#include <string>
#include "AVL.h"
#include "Produto.h"
#include "Utils.h"
#include <algorithm>
#include <string>

void Insert(AVL *avl)
{
	int prod_code,qntd;
  std::string name;
  float price;
  Produto prod(0,"",0,0);
	std::cout << "Insert the product code: ";
	std::cin >> prod_code;
  prod.SetCodigoProduto(prod_code);
  std::cout << "Insert the stock amount of this product: ";
	std::cin >> qntd;
  prod.SetQntd(qntd);
  std::cout << "Insert the name of this product: ";
  std::cin.ignore();
	getline(std::cin,name);
	std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  prod.SetNome(name);
  std::cout << "Insert its price: ";
	std::cin >> price;
  prod.SetValorUnitario(price);
	NodeAVL* node = avl->Insert(prod);
	if (node)
		std::cout << "Node inserted!\n";
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(AVL *avl)
{
	int cod_prod;
	std::cout << "Remove a product by its ID: ";
	std::cin >> cod_prod;
	avl->Remove(cod_prod);
}

void Search(AVL* avl)
{
	int prod_code;
	std::cout << "Search a product: ";
	std::cin >> prod_code;
	NodeAVL* node = avl->Search(prod_code);
	if (node)
		std::cout << "Node found:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(AVL* avl)
{
	int num;
	std::cout << "Find predecessor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Predecessor(num);
	if (node)
		std::cout << "Predecessor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no predecessor of " << num << "!\n";
}

void Successor(AVL* avl)
{
	int num;
	std::cout << "Find successor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Successor(num);
	if (node)
		std::cout << "Successor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no successor of " << num << "!\n";
}

void FindMin(AVL* avl)
{
	NodeAVL* node = avl->FindMin();
	if (node)
		std::cout << "Minimum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(AVL* avl)
{
	NodeAVL* node = avl->FindMax();
	if (node)
		std::cout << "Maximum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}

void TraverseInOrder(AVL* avl)
{
	std::cout << avl->TraverseInOrder() << '\n';
}

void TraversePreOrder(AVL* avl)
{
	std::cout << avl->TraversePreOrder() << '\n';
}

void TraversePostOrder(AVL* avl)
{
	std::cout << avl->TraversePostOrder() << '\n';
}

void Clear(AVL* avl)
{
	avl->Clear();
}


int main()
{
	AVL* avl = new AVL();
  
  Produto produto = Produto(1,"COCA COLA LIGHT",10,5.00);
  avl->Insert(produto);
  produto = Produto(2,"GELO",50,100.00);
  avl->Insert(produto);
  produto = Produto(3,"COCA COLA NORMAL",30,5.00);
  avl->Insert(produto);
  produto = Produto(4,"COCA COLA ZERO",20,70.99);
  avl->Insert(produto);
  produto = Produto(5,"COROTE",100,0.99);
  avl->Insert(produto);
  produto = Produto(6,"BONECO PEPSI-MAN",1,4000.99);
  avl->Insert(produto);

	int option = 0;
	do
	{
	std::cout << "--- Supermarket Console ---\n"
	<< "[1] Insert product\n"
	<< "[2] Remove product\n"
	<< "[3] Search product\n"
	<< "[4] Show the stock value\n"
	<< "[5] Show products below the desired quantity\n"
	<< "[6] Show all products in order\n"
	<< "[7] Show the stock value of a specified product\n"
	<< "[8] Clear all product\n"
    << "[0] Exit terminal\n"
	<< "Option: ";
	std::cin >> option;
    std::cin.ignore();
	std::cout << '\n';

	switch (option)
	{
	case 1: Insert(avl); break;
	case 2: Remove(avl); break;
	case 3: Search(avl); break;
	case 4: PrintStockValue(avl); break;
	case 5: PrintProductsBelow(avl); break;
	case 6: TraverseInOrder(avl); break;
	case 7: PrintProductStockValue(avl); break;
	case 8: Clear(avl); break;
	}

	std::cout << '\n';
	} while (option != 0);

	delete avl;
}