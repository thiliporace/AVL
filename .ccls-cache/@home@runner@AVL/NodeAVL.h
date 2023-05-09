// NodeAVL.h
#ifndef __NODE_AVL_H__
#define __NODE_AVL_H__

#include <string>
#include "Produto.h"

class NodeAVL
{
public:
	NodeAVL(Produto produto, NodeAVL* parent = nullptr, NodeAVL* left = nullptr, NodeAVL* right = nullptr);
	~NodeAVL();

	void CopyDataFrom(const NodeAVL* node);

	int GetID() const;
	//void SetID(int id);

  Produto GetProduto() const;
  void SetProduto(Produto produto);

	std::string GetData() const;
	void SetData(const std::string& data);

	NodeAVL* GetParent() const;
	void SetParent(NodeAVL* parent);

	NodeAVL* GetLeft() const;
	void SetLeft(NodeAVL* left);

	NodeAVL* GetRight() const;
	void SetRight(NodeAVL* right);

	bool IsRoot() const;
	bool IsLeaf() const;

	int GetDegree() const;
	int GetDepth() const;
	int GetHeight() const;

	int GetBalanceFactor() const;
	void UpdateBalanceFactor();

	std::string ToString() const;

private:
  Produto m_Produto;
	
	NodeAVL* m_Parent;
	NodeAVL* m_Left;
	NodeAVL* m_Right;

	int m_BalanceFactor;

	int GetDepthInternal(const NodeAVL* node) const;
	int GetHeightInternal(const NodeAVL* node) const;
};

#endif