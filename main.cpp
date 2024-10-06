#include <iostream>
#include <cstddef>

template <typename T>
class Array
{
public:
	/*ctor*/
	explicit Array(size_t size, const T& value)
	{
		_size = size;
		/*using placement new*/
		_data = reinterpret_cast<T*>(new char[_size * sizeof(T)]);
		for (size_t i = 0; i < _size; i++)
			new (_data + i) T(value);
	}
	/*defautl ctor*/
	Array() = default;
	/*dtor*/
	~Array()
	{
		for (size_t i = 0; i < _size; i++)
			_data[i].~T();
		delete[] reinterpret_cast<char*>(_data);
	}
	/*copy ctor*/
	Array(const Array& other)
	{
		this->~Array();
		_size = other._size;
		_data = reinterpret_cast<T*>(new char[_size * sizeof(T)]);
		for (size_t i = 0; i < _size; i++)
			new (_data + i) T(other[i]);
	}
	/*assignment copy ctor*/
	Array& operator=(const Array& other)
	{
		if (this == &other)
			return *this;
		this->~Array();

		_size = other._size;
		_data = reinterpret_cast<T*>(new char[_size * sizeof(T)]);
		for (size_t i = 0; i < _size; i++)
			new (_data + i) T(other[i]);
		return *this;
	}
	/*size of array*/
	size_t size() const
	{
		return _size;
	}
	/*operator []*/
	T& operator[](size_t index)
	{
		return *(_data + index);
	}
	const T& operator[](size_t index) const
	{
		return *(_data + index);
	}
private:
	size_t _size = 0;
	T* _data = nullptr;
};

/*for tests*/
template<typename T>
void printArr(Array<T>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	printf("\n");
}

/*main func*/
int main()
{
	Array<int> arr_0(10, 4);

	printArr(arr_0);

	return 0;
}