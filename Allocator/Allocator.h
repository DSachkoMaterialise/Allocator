#pragma once
#include <set>
#include <utility>

class Allocator
	{
	private:
		using byte = unsigned char;
		byte* m_data;
		size_t m_size;
		std::set<std::pair<size_t, size_t>> m_busy = {{0, 0}, {m_size, m_size}};

	public:
		explicit Allocator(size_t i_size);
		void* allocate(size_t i_size);
		void deallocate(void* i_ptr);
	};

