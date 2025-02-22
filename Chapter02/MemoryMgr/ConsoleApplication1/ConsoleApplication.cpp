/*
    Copyright (c) 2016 Michael "Mickey" MacDonald.

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the Software
    is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "stdafx.h"
#include "MemoryMgr.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
	CMemoryMgr mgr(sizeof(unsigned), 1024, 4);

	unsigned* i = reinterpret_cast<unsigned*> (mgr.Allocate());

	*i = 0u;
	std::getchar();
	mgr.Deallocate(i);
	std::vector<unsigned*> j;
	
	for (int i = 0; i < 104857600 / 10; i++)
	{
		j.push_back(reinterpret_cast<unsigned*> (mgr.Allocate()));
	}
	std::getchar();
	
	for(auto* i : j)
		mgr.Deallocate(i);
	
	
    return 0;
}

