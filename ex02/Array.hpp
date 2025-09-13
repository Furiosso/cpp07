#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class	Array
{
	private:
		T*				_array;
		unsigned int	_len;
	public:
		Array() : _array(NULL), _len(0) {}

		Array(unsigned int n) : _len(n)
		{
			switch (n)
			{
				case 0:
					this->_array = NULL;
					return ;
				default:
					this->_array = new T[n];
			}
		}

		Array(const Array& src) : _len(src._len)
		{
			switch (src._len)
			{
				case 0:
					this->_array = NULL;
					return ;
				default:
					this->_array = new T[src._len];
			}
			for (unsigned int i = 0; i < this->_len; i++)
				this->_array[i] = src._array[i];
		}

		Array& operator=(const Array& rhs)
		{
			if (this == &rhs)
				return *this;
			delete[] this->_array;
			this->_len = rhs._len;
			switch (rhs._len)
			{
				case 0:
					this->_array = NULL;
					return *this;
				default:
					this->_array = new T[rhs._len];
			}
			for (unsigned int i = 0; i < rhs._len; i++)
				this->_array[i] = rhs._array[i];
			return *this;	
		}

		T&	operator[](const unsigned int index)
		{
			if (index >= this->_len)
				throw std::exception();
			return this->_array[index];
		}

		~Array()
		{
			if (this->_array)
				delete[] this->_array;
		}

		unsigned int	size() const { return _len; }
};

#endif
