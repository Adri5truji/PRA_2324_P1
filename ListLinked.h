#include <ostream>
#include <iostream>
#include "List.h"
#include "Node.h"
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
    private:
        Node<T>* first;
        int n;

    public:
        ListLinked(){
                first = nullptr;
                n = 0;
        }

        ~ListLinked(){
                while(first != nullptr){
                Node<T>* aux = first->next;
                delete first;
                first = aux;
                }
                n = 0;
        }

        virtual int size() override{
               return n;
        }

        T operator[](int pos){
                if(pos > size() || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array");

		Node<T>* aux = first; 
		Node<T>* prevAux = nullptr;

                for(int i = 0; i < pos; i++){
			prevAux = aux;
			aux = aux->next;
		}			
		return aux->data;
        }

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T>&list){
		out <<"List => [";
		Node<T>* aux = list.first;
		while(aux){
                        out << aux->data;
                        if(aux->next != nullptr)
                                out << ", ";
			aux = aux->next;
                }
                out <<"]";
		return out;
	}
	
	virtual void prepend(T e) override{
		Node<T>* nuevo = new Node<T>(e, first);
		
		first = nuevo;
                n++;
        }

        virtual void append(T e) override{
		if(first == nullptr)
			prepend(e);

		Node<T>* aux = first;
		while(aux->next != nullptr)
			aux = aux->next; 
			
		Node<T>* nuevo = new Node<T>(e, nullptr);
		aux->next = nuevo;
                n++;
        }

        virtual void insert(int pos, T e) override{
                if(pos > size() || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array");

                else if(pos == 0)
                        prepend(e);

                else if(pos == size())
                        append(e);

		else{
		Node<T>* aux = first;

                for(int i = 1; i < pos; i++)
                        aux = aux->next;
		
		Node<T>* nuevo = new Node<T>(e, aux->next);
		aux->next = nuevo;
                n++;
                }
        }

        virtual T remove(int pos) override{
                if(pos > size() - 1 || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array");

                Node<T>* eliminado;
		Node<T>* aux = first;
		if(pos == 0){
			first = aux->next;
			eliminado = aux;
		}
		
		else{
                for(int i = 0; i < pos - 1; i++)
                        aux = aux->next;

		eliminado = aux->next;
		aux->next = eliminado->next;
		}

		T num = eliminado->data;
		delete eliminado;
                n--;

                return num;
        }

         virtual T get(int pos) override{
                if(pos > size() - 1 || pos < 0)
                        throw std::out_of_range("La posicion no esta en el array");

		Node<T>* aux = first;
                for(int i = 0; i < pos; i++)
			aux = aux->next;

		return aux->data;
        }

        virtual int search(T e) override{
		Node<T>* aux = first;
		for(int i = 1; i < size(); i++){
			aux = aux->next;
			if(aux->data == e)
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
