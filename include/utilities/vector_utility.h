#pragma once
#include <vector>
#include "engine/globals.h"

template<typename T>
void ResizeIfNecessary(std::vector<T>& vector, size_t index)
{
	if(vector.size() <= index)
	{
		size_t futureSize = vector.size();
		if(futureSize == 0u)
		{
			futureSize = neko::INIT_ENTITY_NMB;
		}
		while (futureSize <= index)
		{
			futureSize *= 2;
		}
		vector.resize(futureSize);
	}
}
