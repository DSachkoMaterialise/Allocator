#include <iostream>
#include "Allocator.h"

int main()
	{
	Allocator alloc(100);
	void* p1 = alloc.allocate(10), * p2 = alloc.allocate(20), * p3 = alloc.allocate(30);
	alloc.deallocate(p2);
	void* p4 = alloc.allocate(15);
	std::cout << p2 << std::endl << p4;
	}