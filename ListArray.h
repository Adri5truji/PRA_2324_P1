#include <ostream>
#include <iostream>
#include "List.h"
#include <stdexcept>

template <typename T> 
class ListArray : public List<T> {
    private:
       	T* arr;
	int max;
	int n;
	static const int MINSIZE;
 	void resize(int new_size){
		ListArray();
		this->arr = arr;
		~ListArray();
		*arr = this->arr;
		max = new_size;
	}

    public:
	ListArray(){
		arr = new T[MINSIZE];
	}
	~ListArray(){
		delete[] arr;
	}
	T operator[](int pos){
		if(pos > max || pos < 0)
			throw std::out_of_range("La posicion no esta en el array ");
		return arr[pos];
	}
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T>&list){
		out <<"[";
		for(int i = 0; i < list.max(); i++){
			out << list.arr[i];
			if(i < list.max() - 1)
				out << ", ";
		}
		out <<"]";
		return out;
	}

	virtual void insert(int pos, T e) override{
                if(pos > max || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array ");
		arr[pos] = e;
	}
        virtual void append(T e) override{
		arr[max] = e;
	}
        virtual void prepend(T e) override{
		arr[0] = e;
	}
       	virtual T remove(int pos) override{
                if(pos > max || pos < 0)
			throw std::out_of_range("La posicion no esta en el array ");
		T aux = arr[pos];
		delete pos;
		return aux;
	}
        virtual T get(int pos) override{
                if(pos > max || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array ");
		return arr[pos];
	}
        virtual int search(T e) override{
		for(int i = 0; i < max; i++){
			if(arr[i] == e)
				return i;
		}
		return -1;
	}
        virtual bool empty() override{
		for(int i = 0; i < max; i++){
			if(arr[i] != 0)
				return false;
		}
		return true;
	}
	       virtual int size() override{
                return max;
        }
};
