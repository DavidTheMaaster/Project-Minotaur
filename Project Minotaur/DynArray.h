#ifndef _DYNARRAY_H__
#define _DYNARRAY_H__

#include "Defines.h"
#include <assert.h>

template<class VALUE>
class DynArray
{
private:
	VALUE*		data = nullptr;
	uint		mem_capacity = 0;
	uint		num_elements = 0;

public:
	DynArray() : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(16);
	}

	DynArray(uint capacity) : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(capacity);
	}
	~DynArray()
	{
		delete[] data;
	}

	VALUE& operator[](uint index)
	{
		assert(index < num_elements);
		return data[index];
	}

	const VALUE& operator[](uint index) const
	{
		assert(index < num_elements);
		return date[index];
	}

	void PushBack(const VALUE& element)
	{
		if (num_elements >= mem_capacity)
		{
			Alloc(mem_capacity + 16);
		}
		data[num_elements++] = element;
	}

	bool RemoveAt(uint x) 
	{


		for (int i = 0; i < num_elements; i++)
		{
			if (i == x)
			{
				for (; i < num_elements - 1; i++)
				{
					data[i] = data[i + 1];
				}
				data[num_elements - 1] = 0;
				num_elements = num_elements - 1;
				 
				return true;
			}
			return false;
		}
	}
	VALUE* At(uint index)
	{
		VALUE* result = NULL;

		if (result > num_elements)
		{
			return result;
		}
		else
		{
			result = &data[index];
		}

		return result;
	}

	const VALUE* At(uint index) const
	{
		VALUE* result = NULL;

		if (result > num_elements)
		{
			return result;
		}
		else
		{
			result = &data[index];
		}

		return result;
	}

	uint Count() const
	{
		return num_elements;
	}

private:
	void Alloc(unsigned int mem)
	{
		VALUE* tmp = data;

		mem_capacity = mem;
		data = new VALUE[mem_capacity];

		num_elements = MIN(mem_capacity, num_elements);

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < num_elements; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}

};


#endif // !_DYNARRAY_H__


