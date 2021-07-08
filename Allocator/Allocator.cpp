#include "Allocator.h"

using namespace std;

Allocator::Allocator(size_t i_size) : m_data(reinterpret_cast<byte*>(operator new(i_size))), m_size(i_size)
    {}

void* Allocator::allocate(size_t i_size)
	{
	for (auto ite = begin(m_busy), itb = ite++; ite != end(m_busy); itb++, ite++)
		{
		if (ite->first - itb->second >= i_size)
			{
			m_busy.insert({itb->second, itb->second + i_size});
			return m_data + itb->second;
			}
		}
	return nullptr;
	}

void Allocator::deallocate(void* i_ptr)
	{
	auto it = m_busy.upper_bound({reinterpret_cast<byte*>(i_ptr) - m_data, 0});
	if (it->first == reinterpret_cast<byte*>(i_ptr) - m_data)
		m_busy.erase(it);
	}
