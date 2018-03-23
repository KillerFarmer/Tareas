using System;

using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arboles {
    class Program {
        static void Main(string[] args) {

            ArbolAVL ar = new ArbolAVL();

            ar.AgregarValor(10);
            ar.AgregarValor(5);
            ar.AgregarValor(2);
            ar.AgregarValor(7);
            ar.AgregarValor(1);
            ar.AgregarValor(6);
            ar.AgregarValor(8);
            ar.AgregarValor(9);
            ar.AgregarValor(19);
            ar.AgregarValor(12);
            ar.AgregarValor(25);
            ar.AgregarValor(13);
            
            Console.WriteLine("Altura del arbol: " + ar.getAltura());
            ar.PrintBreadthFirst();
            //BuscarNumero(ar,7);
            //BuscarNumero(ar,11);


            Console.ReadLine();
        }


        static void BuscarNumero(ArbolAVL ar, int numero) {

            if (ar.EncontrarValor(numero)) {
                Console.WriteLine("El numero {0} se encontro en el arbol AVL", numero);
            } else {
                Console.WriteLine("No se encontro el numero {0} en el arbol", numero);
            }

        }
    }


    class Nodo {

        public int Valor { get; set; }
        public Nodo Padre { get; set; }
        public Nodo Derecha { get; set; }
        public Nodo Izquierda { get; set; }

        public Nodo() {
            this.Valor = 0;
        }

        public Nodo(int valor) {
            this.Valor = valor;
        }

        public Nodo(int valor, Nodo izquierda, Nodo derecha) {

            this.Valor = valor;
            Izquierda.Padre = this;
            this.Izquierda = izquierda;
            Derecha.Padre = this;
            this.Derecha = derecha;

        }
    }


    class ArbolBinario {

        private Nodo Raiz;

        public void AgregarValor(int valor) {


            if (Raiz == null) {
                Raiz = new Nodo(valor);
                return;
            }

            Nodo actual = Raiz;
            Nodo anterior = null;
            
            do {

                anterior = actual;
                if (valor < actual.Valor) {

                    actual = actual.Izquierda;

                } else {
                    actual = actual.Derecha;
                }

            } while (actual != null);

            if (valor < anterior.Valor) {
                anterior.Izquierda = new Nodo(valor);
                anterior.Izquierda.Padre = anterior;
                
            } else {
                anterior.Derecha = new Nodo(valor);
                anterior.Derecha.Padre = anterior;
            }
        }


        public int getAltura() {

            return CalcularAltura(this.Raiz, 0);
        }

        public int CalcularAltura(Nodo n, int altura) {

            int alturaIz = altura, alturaDer = altura;

            if (n.Izquierda != null) {
                alturaIz = CalcularAltura(n.Izquierda, ++alturaIz);

            }

            if (n.Derecha != null) {
                alturaDer = CalcularAltura(n.Derecha, ++alturaDer);
            }



            return Math.Max(alturaIz, alturaDer);
        }
    }


    class ArbolAVL {

        public Nodo Raiz;

        public void AgregarValor(int valor) {


            if (Raiz == null) {
                Raiz = new Nodo(valor);
                return;
            }

            Nodo actual = Raiz;
            Nodo anterior = null;

            do {

                anterior = actual;
                if (valor < actual.Valor) {

                    actual = actual.Izquierda;

                } else {
                    actual = actual.Derecha;
                }

            } while (actual != null);

            Nodo nuevo = new Nodo(valor);

            if (valor < anterior.Valor) {
                anterior.Izquierda = nuevo;
                anterior.Izquierda.Padre = anterior;

            } else {
                anterior.Derecha = nuevo;
                anterior.Derecha.Padre = anterior;
            }


            Nodo recorrer = nuevo.Padre;

            while (recorrer != null) {

                int altura = Balance(recorrer);

                if (altura < -1 || altura > 1) {

                    Balancear(recorrer, altura);
                    break;
                }
                recorrer = recorrer.Padre;
            }

        }

        public bool EncontrarValor(int valor) {

            if (Raiz == null) {
                return false;

            } else if (Raiz.Valor == valor) {
                return true;
            }

            Nodo este = Raiz;



            if (valor < este.Valor) {
                este = este.Izquierda;

            } else {
                este = este.Derecha;
            }


            do {

                if (este.Valor == valor) {
                    return true;
                }

                if (valor < este.Valor) {
                    este = este.Izquierda;

                } else {
                    este = este.Derecha;
                }




            } while (este != null);

            return false;


        }

        private void Balancear(Nodo pico, int altura) {

            if (altura > 0) {



                if (Balance(pico.Derecha) > 0) {
                    GiroIzquierda(pico);

                } else {

                    GiroDerecha(pico.Derecha);
                    GiroIzquierda(pico);
                }

            } else {



                if (Balance(pico.Izquierda) > 0) {

                    GiroIzquierda(pico.Izquierda);
                    GiroDerecha(pico);

                } else {
                    GiroDerecha(pico);
                }
            }


        }

        public int getAltura() {

            return CalcularAltura(this.Raiz, 0);
        }

        public int CalcularAltura(Nodo n, int altura) {

            int alturaIz = altura, alturaDer = altura;

            if (n.Izquierda != null) {
                alturaIz = CalcularAltura(n.Izquierda, ++alturaIz);

            }

            if (n.Derecha != null) {
                alturaDer = CalcularAltura(n.Derecha, ++alturaDer);
            }

            return Math.Max(alturaIz, alturaDer);
        }

        private int Balance(Nodo n) {

            int izq = 0, der = 0;
            if (n.Izquierda != null) {

                izq = CalcularAltura(n.Izquierda, 0) + 1;
            }

            if (n.Derecha != null) {

                der = CalcularAltura(n.Derecha, 0) + 1;
            }

            return der - izq;
        }

        private void GiroDerecha(Nodo n) {

            if (n == Raiz) {
                Raiz = n.Izquierda;

            }

            Nodo temp = n.Izquierda.Derecha, padre = n.Padre, izquierda = n.Izquierda;

            if (padre != null) {

                bool dir = false;

                if (n == padre.Derecha) {
                    dir = true;
                }

                if (dir) {
                    padre.Derecha = n.Izquierda;

                } else {

                    padre.Izquierda = n.Izquierda;
                }
                //padre.Derecha = n.Izquierda;
            }


            n.Izquierda.Padre = padre;
            n.Izquierda.Derecha = n;
            n.Padre = n.Izquierda;
            n.Izquierda = temp;



            if (temp != null) {
                temp.Padre = n;
            }


        }

        private void GiroIzquierda(Nodo n) {

            if (n == Raiz) {
                Raiz = n.Derecha;

            }

            Nodo temp = n.Derecha.Izquierda, padre = n.Padre, derecha = n.Derecha;



            if (padre != null) {
                bool dir = false;

                if (n == padre.Derecha) {
                    dir = true;
                }

                if (dir) {
                    padre.Derecha = n.Derecha;

                } else {
                    padre.Izquierda = n.Derecha;
                }

                //padre.Izquierda = n.Derecha;
            }


            n.Derecha.Padre = padre;
            n.Derecha.Izquierda = n;
            n.Padre = n.Derecha;
            n.Derecha = temp;



            if (temp != null) {
                temp.Padre = n;
            }
        }


        public void PrintDepthFirst() {
            if (Raiz != null) {
                PrintDepthFirstRecursive(Raiz);

            }
        }

        private void PrintDepthFirstRecursive(Nodo n) {
            Console.WriteLine(n.Valor + " ");

            if (n.Izquierda != null) {
                PrintDepthFirstRecursive(n.Izquierda);
            }
            if (n.Derecha != null) {
                PrintDepthFirstRecursive(n.Derecha);
            }
        }


        public void PrintBreadthFirst() {

            bool seguir = false;
            if (Raiz != null) {

                Console.Write(Raiz.Valor + " ");
                seguir = true;
            }

            int iter = 0;
            while (seguir) {


                iter++;
                seguir = PrintBreadthFirstRecursive(Raiz, iter);


            }


        }

        private bool PrintBreadthFirstRecursive(Nodo n, int iter) {

            bool seguir = false;

            if (iter == 0) {
                Console.Write(n.Valor + " ");
                return true;
            }
            bool uno = false, dos = false;
            if (n.Izquierda != null) {
                uno = PrintBreadthFirstRecursive(n.Izquierda, iter - 1);

            }
            if (n.Derecha != null) {
                dos = PrintBreadthFirstRecursive(n.Derecha, iter - 1);
            }

            return (uno || dos);

        }


        public void PrintBreadthFirst2() {
            List<Nodo> queue = new List<Nodo>();

            queue.Add(Raiz);

            while (queue.Count > 0) {

                Nodo temp = queue[0];
                queue.RemoveAt(0);
                Console.WriteLine(temp.Valor + " ");

                if (temp.Izquierda != null) {
                    queue.Add(temp.Izquierda);
                }
                if (temp.Derecha != null) {
                    queue.Add(temp.Derecha);
                }

            }
        }
    }
}
