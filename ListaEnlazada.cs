using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ListaEnlazada {

    class Program {

        static void Main(string[] args) {


            /*
            ListaEnlazada LE = new ListaEnlazada();

            LE.AgregarValores(1);
            LE.AgregarValores(2);
            LE.AgregarValores(3);
            LE.ImprimirNodos();

            LE.BorrarNodo(2);
            LE.ImprimirNodos();

            LE.AgregarValores(2);
            LE.AgregarValores(4);
            LE.ImprimirNodos();

            LE.EncontrarNodo(2);


            Console.WriteLine((LE.GetNodo(1)).Valor + "  ---");
            Console.ReadLine();
            */

            ListaEnlazadaDoble LE = new ListaEnlazadaDoble();

            LE.Agregar(1);
            LE.Agregar(2);
            LE.Agregar(3);
            LE.ImprimirNodos();

            Console.WriteLine(LE.Pop().Valor + " - Pop");
            LE.ImprimirNodos();

            LE.Push(3);
            LE.ImprimirNodos();

            Console.WriteLine(LE.Unshift().Valor + " Unshift");
            LE.ImprimirNodos();

            LE.Shift(1);
            LE.ImprimirNodos();

            
            Console.ReadLine();
        }
    }


    class Nodo {
        ///
        public int Valor { get; set; }
        public Nodo Siguiente { get; set; }
        
        
        /// <summary>
        /// Crea un nuevo nodo
        /// </summary>
        public Nodo() {

            this.Valor = 0;
        }
        
        /// <summary>
        /// Crea un nuevo nodo
        /// </summary>
        /// <param name="Valor">Asigna un nuevo valor para un nuevo codigo</param>
        public Nodo(int Valor) {
            this.Valor = Valor;
        }

        public Nodo(int Valor, Nodo Siguiente) {

            this.Valor = Valor;
            this.Siguiente = Siguiente;

        }

    }

    class ListaEnlazada {

        public Nodo Raiz { get; set; }

        public int Length {
            get {
                return this.GetLength();
            }
        }

        public void ImprimirNodos() {

            Nodo nodo = Raiz;
            Console.Write("[ ");
            while (nodo != null) {
                Console.Write(nodo.Valor + ", ");
                nodo = nodo.Siguiente;
            }
            Console.WriteLine(" ]");
        }

        public void AgregarValores(int valor) {


            if (Raiz == null) {
                Raiz = new Nodo(valor);
                return;
            }

            Nodo n = Raiz;

            while (n.Siguiente != null) {
                n = n.Siguiente;
            }

            n.Siguiente = new Nodo(valor);
        }

        public void BorrarNodo(int Valor) {

            Nodo n = Raiz;

            if (n != null && Raiz.Valor == Valor) {

                Raiz = Raiz.Siguiente;
                return;
            }


            while (n.Siguiente != null) {

                if (n.Siguiente.Valor == Valor) {
                    n.Siguiente = n.Siguiente.Siguiente;
                    return;
                }
            }

        }

        public Nodo EncontrarNodo(int valor) {

            int orden = 1;
            Nodo n = Raiz;

            while (n != null) {

                if (n.Valor == valor) {
                    Console.WriteLine("Encontrado en posicion {0}", orden);
                    return null;
                }
                n = n.Siguiente;
                orden++;
            }

            return null;
        }

        public Nodo GetNodo(int index) {

            if (index < 0 || index >= this.Length) {
                throw new IndexOutOfRangeException("The index is either less than 0 or more the Length");
                
            }

            Nodo nodo = Raiz;
            int count = 0;

            for (int i = 0; i < index; i++) {
                nodo = nodo.Siguiente;
            }

            return nodo;
        }

        private int GetLength() {

            Nodo nodo = Raiz;
            int count = 0;

            while (nodo != null) {

                nodo = nodo.Siguiente;
                count++;

            }

            return count;
        }



    }


    class NodoD {

        public int Valor { get; set; }
        public NodoD Siguiente { get; set; }
        public NodoD Anterior { get; set; }

        public NodoD(int Valor) {
            this.Valor = Valor;

        }

        public NodoD(int Valor, NodoD Siguiente) {

            this.Valor = Valor;
            this.Siguiente = Siguiente;
            this.Siguiente.Anterior = this;

        }
    }

    class ListaEnlazadaDoble {

        private NodoD Raiz;

        public void Agregar(int valor) {

            if (Raiz == null) {
                Raiz = new NodoD(valor);
                return;
            }

            NodoD n = Raiz, anterior = null;

            while (n.Siguiente != null) {
                //anterior = n;
                n = n.Siguiente;
            }
            //n.Anterior = anterior;
            
            n.Siguiente = new NodoD(valor);
            n.Siguiente.Anterior = n;
        }

        public void Borrar(int Valor) {

            NodoD n = Raiz;

            if (n == null) {
                return;
            }

            if (n.Valor == Valor) {

                Raiz = Raiz.Siguiente;
                return;
            } 

            //NodoD anterior = null;

            while (n.Siguiente != null) {

                if (n.Siguiente.Valor == Valor) {
                    if (n.Siguiente.Siguiente != null) {
                        n.Siguiente.Siguiente.Anterior = n; 
                    }
                    //n.Siguiente.Anterior = n;
                    n.Siguiente = n.Siguiente.Siguiente;
                    return;
                }
                //anterior = n;
                n = n.Siguiente;
            }
        }

        public void ImprimirNodos() {

            NodoD nodo = Raiz;
            Console.Write("[ ");
            while (nodo != null) {
                Console.Write(nodo.Valor + ", ");
                nodo = nodo.Siguiente;
            }
            Console.WriteLine(" ]");
        }

        public NodoD Pop() {
            NodoD n = Raiz;

            if (n == null) {
                return null;
            }

            while (n.Siguiente != null) {

                n = n.Siguiente;
            }

            n.Anterior.Siguiente = null;
            n.Anterior = null;

            return n;

            
        }

        public void Push(int num) {


            NodoD n = this.Raiz;

            if (n == null) {
                this.Raiz = new NodoD(num);
                return;
            }

            while (n.Siguiente != null) {

                n = n.Siguiente;
            }

            n.Siguiente = new NodoD(num);
            n.Siguiente.Anterior = n;
        }

        public NodoD Unshift() {


            if (Raiz == null) {

                return null;


            } else if (Raiz.Siguiente == null) {

                NodoD n = Raiz;
                Raiz = null;
                return n;
            } else {

                NodoD n = Raiz;
                Raiz = n.Siguiente;
                n.Siguiente.Anterior = null;

                return n;
            }

            
        }

        public void Shift(int num) {

            if (Raiz == null) {

                Raiz = new NodoD(num);


            } else  {

                

                NodoD n = new NodoD(num);
                Raiz.Anterior = n;
                n.Siguiente = Raiz;
                Raiz = n;

            } 
        }

    }


    

}
