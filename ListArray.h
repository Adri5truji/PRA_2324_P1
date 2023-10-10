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
		T* new_arr = new T[new_size];
		for(int i = 0; i < n; i++)
			new_arr[i] = arr[i];
		delete[] arr;
		arr = new_arr;
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
		for(int i = 0; i < list.n; i++){
			out << list.arr[i];
			if(i < list.n - 1)
				out << ", ";
		}
		out <<"]";
		return out;
	}

	void insert(int pos, T e) override{
                if(pos > max || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array ");
		arr[pos] = e;
	}
        void append(T e) override{
		if(n >= max)
			resize(max * 2);	
		arr[n] = e;
		n++;
	}
        void prepend(T e) override{
		arr[0] = e;
	}
       	T remove(int pos) override{
                if(pos > max || pos < 0)
			throw std::out_of_range("La posicion no esta en el array ");
		T aux = arr[pos];
		for(int i = 0; i < n; i++)
			arr[i] = arr[i + 1];
		max--;
		n--;
		return aux;
	}
        T get(int pos) override{
                if(pos > max || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array ");
		return arr[pos];
	}
        int search(T e) override{
		for(int i = 0; i < max; i++){
			if(arr[i] == e)
				return i;
		}
		return -1;
	}
        bool empty() override{
		for(int i = 0; i < max; i++){
			if(arr[i] != 0)
				return false;
		}
		return true;
	}
	int size() override{
                return max;
        }
};
