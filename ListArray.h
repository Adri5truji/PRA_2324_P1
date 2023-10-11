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
	static const int MINSIZE = 2;
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
		max = MINSIZE;
		n = 0;
	}

	~ListArray(){
		delete[] arr;
		n = 0;
	}

	virtual int size() override{
      	       return n;
        }

	T operator[](int pos){
		if(pos > size() || pos < 0)
			throw std::out_of_range("La posicion no esta en el array");

		return arr[pos];
	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T>&list){
		out <<"List => [";
		for(int i = 0; i < list.n; i++){
			out << list.arr[i];
			if(i < list.n - 1)
				out << ", ";
		}
		out <<"]";
		return out;
		}

	virtual void prepend(T e) override{
                if(size() == max - 1)
                        resize(max * 2);

                for(int i = size() - 1; i > 0; i--)
                        arr[i] = arr[i - 1];

                arr[0] = e;
                n++;
        }

        virtual void append(T e) override{
                if(size() == max - 1)
                        resize(max * 2);

                arr[size() + 1] = e;
                n++;
        }

	virtual void insert(int pos, T e) override{
		if(pos > size() || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array");

		else if(pos == 0)
			prepend(e);

		else if(pos == max - 1)
			append(e);

		else{
		for(int i = size(); i > pos; i--)
			arr[i] = arr[i - 1];

		arr[pos] = e;
		n++;
		}
	}

       	virtual T remove(int pos) override{
		if(pos > size() - 1 || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array");

		T num = arr[pos];

		for(int i = pos; i < size() - 1; i++)
			arr[i] = arr[i + 1];

		n--;
		return num;
	}

        virtual T get(int pos) override{
		if(pos > size() - 1 || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array");

		return arr[pos];
	}
	
       	virtual int search(T e) override{
		for(int i = 0; i < size(); i++){
			if(arr[i] == e)
				return i;
		}

		return -1;
	}

        virtual bool empty() override{
		if(n == 0)
			return true;
		else
			return false;
	}
};
