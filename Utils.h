// Utils.h
#ifndef __UTILS_H__
#define __UTILS_H__
#include "NodeAVL.h"
#include <sstream>
#include "Produto.h"
#include "AVL.h"
#include <iostream>

namespace Utils
{
	template <typename T>
	static T Max(T l, T r)
	{
		return (l > r) ? l : r;
	}
}

void PrintStockValueInternal(Produto produto,NodeAVL *node,float &total_value);
void PrintStockValue(AVL *avl);

void PrintProductsBelow(AVL *avl);
void PrintProductsBelowInternal(Produto produto,NodeAVL *node,int qntdEntry);

void PrintProductStockValue(AVL* avl);
void PrintProductStockValueInternal(Produto produto, NodeAVL* node,std::string nameEntry,float result);


#endif