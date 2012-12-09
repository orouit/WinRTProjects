#pragma once

namespace CoreImpl
{
	class RefCount
	{
		private:
		int count; // Reference count

		public:
		void AddRef()
		{
			// Increment the reference count
			count++;
		}

		int Release()
		{
			// Decrement the reference count and
			// return the reference count.
			return --count;
		}
	};

	template < typename T > class SP
	{
	private:
		T*    pData;       // pointer
		RefCount* reference; // Reference count

	public:
		SP() : pData(0), reference(0) 
		{
			// Create a new reference 
			reference = new RefCount();
			// Increment the reference count
			reference->AddRef();
		}

		SP(T* pValue) : pData(pValue), reference(0)
		{
			// Create a new reference 
			reference = new RefCount();
			// Increment the reference count
			reference->AddRef();
		}

		SP(const SP<T>& sp) : pData(sp.pData), reference(sp.reference)
		{
			// Copy constructor
			// Copy the data and reference pointer
			// and increment the reference count
			reference->AddRef();
		}

		~SP()
		{
			// Destructor
			// Decrement the reference count
			// if reference become zero delete the data
			if(reference->Release() == 0)
			{
				delete pData;
				delete reference;
			}
		}

		// Overloading operator *
		T& operator* ()
		{
			return *pData;
		}

		// Overloading operator ->
		T* operator-> ()
		{
			return pData;
		}
    
		// Overloading operator &
		T* operator&()
		{
			return pData;
		}

		SP<T>& operator = (const SP<T>& sp)
		{
			// Assignment operator
			if (this != &sp) // Avoid self assignment
			{
				// Decrement the old reference count
				// if reference become zero delete the old data
				if(reference->Release() == 0)
				{
					delete pData;
					delete reference;
				}

				// Copy the data and reference pointer
				// and increment the reference count
				pData = sp.pData;
				reference = sp.reference;
				reference->AddRef();
			}
			return *this;
		}
	};
}