#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

template<typename T>
class DataStructure
{
	protected:
		static const unsigned short INITIAL_CAPACITY = 5;
		T* data;
		unsigned int size;
		unsigned int capacity;

		void copy(const DataStructure&);
		void deleteInternals();
		void reserve();
		bool isFull() const;

	public:
		DataStructure(const unsigned int& = INITIAL_CAPACITY);
		DataStructure(const DataStructure&);
		DataStructure& operator=(const DataStructure&);
		virtual ~DataStructure() = 0;
};

#endif