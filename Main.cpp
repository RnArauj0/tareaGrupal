#include <iostream>
#include<conio.h>
using namespace std;
class Tren {
    class Vagon {
       
    public:
        int elemento;//Niños
        Vagon* sig;
        Vagon* ant;// NUEVO
        Vagon(int e) {
            elemento = e;
            sig = nullptr;
            ant = nullptr;//  NUEVO
        }
    };
    
    Vagon* inicio;
    size_t cantidad;
public:
    Tren() {
        inicio = nullptr;
        cantidad = 0;
    }


    void borrar(int n) {
        Vagon* lista = inicio;
        if (lista != nullptr) {
            Vagon* aux;
            Vagon* anterior = nullptr;
            aux = lista;

            //recorrer lista
            for (int i = 0; i < n; ++i) {
                anterior = aux;
                aux = aux->sig;
            }
            //si es el primer elemento
            if (anterior == nullptr) {
                lista = lista->sig;
                delete aux;
            }
            //si no es el primer elemento
            else {
                anterior->sig = aux->sig;
                delete aux;
            }
        }

        inicio = lista;
    }

    //3-eliminar al inicio
    void borrarinicio() {
        borrar(0);
    }

    //4-eliminar al final
    void borrarfinal() {
        Vagon* lista = inicio;
        if (lista != nullptr) {
            Vagon* aux;
            Vagon* anterior = nullptr;
            aux = lista;

            //recorrer lista
            while (aux->sig != nullptr) {
                anterior = aux;
                aux = aux->sig;
            }
            //si es el primer elemento
            if (anterior == nullptr) {
                lista = lista->sig;
                delete aux;
            }
            //si no es el primer elemento
            else {
                anterior->sig = aux->sig;
                delete aux;
            }
        }

        inicio = lista;
    }
    //5->ordenar elementos(n^2)
    void ordenar() {
        Vagon* p=inicio;
        while (p != nullptr) {
            Vagon* j = p->sig;
            while (j != nullptr) {
                if (p->elemento > j->elemento) {
                    int aux = j->elemento;
                    j->elemento = p->elemento;
                    p->elemento = aux;
                }
                j = j->sig;
            }
            p = p->sig;
        }
        p = inicio;
     }

    
    //6-buscar por valor(n)
    void BuscarPorValor(int n) {
        Vagon* lista = inicio;
        bool founded = false;
        if (lista != nullptr) {
            Vagon* aux;
            Vagon* anterior = nullptr;
            aux = lista;

            //recorrer lista
            while (true) {
                if (aux->sig != nullptr) {
                    if (aux->elemento != n) {
                        anterior = aux;
                        aux = aux->sig;
                    }
                    else { founded = true; break; }
                }
                else { founded = false; break; }
            }
            //si es el primer elemento
            if (anterior == nullptr) {
                lista = lista->sig;
                delete aux;
            }
            //si no es el primer elemento
            else {
                anterior->sig = aux->sig;
                delete aux;
            }

            //Ahora mostramos si hay elementos
            if (founded) { cout << "Elemento encontrado"; }
            else { cout << "Elemento no encontrado"; }
        }
        else {
            cout << "No hay elementos en esta lista";
        }
    }
    //7->invertir lista
     
  /* void invertir() {
        Vagon* lista = inicio;
        Vagon* aux;        
        aux = lista;
        if (lista != nullptr) {
            while (aux->sig != nullptr) {
                aux = aux->sig;
            }
            while (aux != nullptr) {
                cout << aux->elemento << "->";
                aux = aux->ant;               
            }
            
        }
        else cout << "!! sin elementos ¡¡";       
    }*/
    void invertir(){
      for(int i=cantidad-2;i>=0;--i){
         cout<<at(i)<<"-->";
      }
    }
    
    void insert(int e) {
        Vagon* n = new Vagon(e);
        if (cantidad == 0)
            inicio = n;
        else {
            n->ant = nullptr; //   NUEVO
            n->sig = inicio;
            
            inicio = n;
            
        }
        ++cantidad;
       
    }
    void print() {
        Vagon* aux = inicio;
        while (aux->sig != nullptr) {
            cout << aux->elemento << "-->";
            aux = aux->sig;
        }
        cout << endl;
    }
    
    //1-obtener objeto en posicion = at()
    int at(int n) {
        Vagon* aux = inicio;

        for (size_t i = 0; i < n; ++i) {
            aux = aux->sig;
        }
        return aux->elemento;
    }
};
int main() {
    Tren t;
    
    for (size_t i = 0; i < 20; ++i) {
        t.insert(i);
    }

    t.print();
    cout << endl;
    cout << t.at(5);
    cout << endl;
    cout << "buscar 14" << endl;
   // t.BuscarPorValor(14);
   // cout << endl;
   // t.borrar(5);
   // cout << endl;
    //t.print();
   // t.borrarinicio();
  //  t.print();
   // t.borrarfinal();
   // t.print();
  //  cout << "buscar 14" << endl;
  //  t.BuscarPorValor(14);
  //  cout << endl;
    //cout << "ELEMENTOS ORDENADOS:\n";
  //  t.ordenar();
  //  t.print();
    cout << endl;
    cout << "ELEMENTOS INVERTIDOS: \n";
    t.invertir();
    
    _getch();
}