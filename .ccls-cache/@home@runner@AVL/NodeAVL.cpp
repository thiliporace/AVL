// NodeAVL.cpp
#include "NodeAVL.h"
#include "Utils.h"
#include <sstream>
#include "Produto.h"

NodeAVL::NodeAVL(Produto produto,NodeAVL* parent, NodeAVL* left, NodeAVL* right)
	: m_Produto(produto)
	, m_Parent(parent)
	, m_Left(left)
	, m_Right(right)
	, m_BalanceFactor(0)
{
}

NodeAVL::~NodeAVL()
{
	m_Parent = nullptr;
	m_Left = nullptr;
	m_Right = nullptr;
}

Produto NodeAVL::GetProduto() const{
  return m_Produto;
}
void NodeAVL::SetProduto(Produto produto){
  m_Produto = produto;
}

void NodeAVL::CopyDataFrom(const NodeAVL* node)
{
	m_Produto = node->GetProduto();
}

int NodeAVL::GetID() const
{
	return GetProduto().GetCodigoProduto();
}

//void NodeAVL::SetID(int id)
//{
//	m_ID = id;
//}

NodeAVL* NodeAVL::GetParent() const
{
	return m_Parent;
}

void NodeAVL::SetParent(NodeAVL* parent)
{
	m_Parent = parent;
}

NodeAVL* NodeAVL::GetLeft() const
{
	return m_Left;
}

void NodeAVL::SetLeft(NodeAVL* left)
{
	m_Left = left;
}

NodeAVL* NodeAVL::GetRight() const
{
	return m_Right;
}

void NodeAVL::SetRight(NodeAVL* right)
{
	m_Right = right;
}

bool NodeAVL::IsRoot() const
{
	return m_Parent == nullptr;
}

bool NodeAVL::IsLeaf() const
{
	return m_Left == nullptr && m_Right == nullptr;
}

int NodeAVL::GetDegree() const
{
	int degree = 0;

	if (m_Left != nullptr)
		++degree;
	if (m_Right != nullptr)
		++degree;

	return degree;
}

int NodeAVL::GetDepth() const
{
	return GetDepthInternal(this);
}

int NodeAVL::GetDepthInternal(const NodeAVL* node) const
{
	if (node->IsRoot())
	{
		return 0;
	}
	else
	{
		return 1 + GetDepthInternal(node->GetParent());
	}
}

int NodeAVL::GetHeight() const
{
	return GetHeightInternal(this);
}

int NodeAVL::GetHeightInternal(const NodeAVL* node) const
{
	if (node == nullptr || node->IsLeaf())
	{
		return 0;
	}
	else
	{
		return 1 + Utils::Max(GetHeightInternal(node->GetLeft()), GetHeightInternal(node->GetRight()));
	}
}

int NodeAVL::GetBalanceFactor() const
{
	return m_BalanceFactor;
}

void NodeAVL::UpdateBalanceFactor()
{
	int leftHeight = m_Left == nullptr ? -1 : GetHeightInternal(m_Left);
	int rightHeight = m_Right == nullptr ? -1 : GetHeightInternal(m_Right);
	m_BalanceFactor = rightHeight - leftHeight;

	// Read the comments inside AVL::Balance().
	//m_BalanceFactor = leftHeight - rightHeight;
}

std::string NodeAVL::ToString() const
{
	std::ostringstream oss;

	oss
		<< "\nProduct code:" << GetProduto().GetCodigoProduto() << "\n"
    << "Product:" << GetProduto().GetNome() << "\n"
    << "Quantity on stock:" << GetProduto().GetQntd() << "\n"
    << "Price:" << GetProduto().GetValorUnitario() << "\n";
		// << " Parent:" << (m_Parent != nullptr ? m_Parent->GetID() : -1)
		// << " Left:" << (m_Left != nullptr ? m_Left->GetID() : -1)
		// << " Right:" << (m_Right != nullptr ? m_Right->GetID() : -1)
		// << " Degree: " << GetDegree()
		// << " Depth: " << GetDepth()
		// << " Height: " << GetHeight()
		// << " Balance: " << m_BalanceFactor << '\n';

	return oss.str();
}
