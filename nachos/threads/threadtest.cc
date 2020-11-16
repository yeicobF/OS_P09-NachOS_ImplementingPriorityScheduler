// threadtest.cc
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield,
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include <iostream> // No dio problemas al compilar.
#include <cmath> // Para sacar el std::floor, std::ceil.
/* For the stream check (std::cin in our case):
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
	*/
#include <limits>
//#include <algorithm> // std::sort, max // Tampoco la deja.
// Las siguientes librerías daban problemas al compilar:
// #include<bits/stdc++.h> // sort, reverse
// #include <cstdlib> //para limpiar pantalla

// Tamaño máximo del arreglo.
// Maximum size of the array.
#define MAX 6
// Valores de las prioridades de los hilos. Constante para no cambiarlo.
const int maxPriority = 0, minPriority = 5;

// Not to include everything in the std namespace, just what we want.
// using std::cin;
// using std::cout;
// using std::endl;

// At the end it was better to use all of the namespace. A lot of it was necessary.
using namespace std;

/*

    - PRACTICE 8: MODIFY Threadtest.cc

    Esquivel Garza Hosue Israel
    Dominguez Perez Ulises Uriel
    Flores Rodríguez Francisco Jacob
    Garza Medina Luis Eduardo
    Gomez Arreguin Sonni Augusto

    Monday, November 9th, 2020
    Thursday, November 10th, 2020
*/

// Arreglo compartido entre los hilos/hebras.
// Shared array for threads. Changes will be made globally.
int Buffer[MAX];// = {}; // Initialize array with 0s. // This is done automatically.

// Method that checks if an entered value is valid (Integer) or not.
// The stream (std::cin in this case) is sent this way as a parameter. I found it that way.
// SOURCE: Stack Overflow: How to pass cin to a function?
bool isEnteredValueNotInt(std::istream& stream, float value){
    // It returns true if the entered value is not an int (float or string).
    // !stream = input stream is not valid = string or something similar.
    // (value - floor(value) > 0) = positive float
    // (value  - ceil(value) < 0) = negative float.
    return !stream || (value - floor(value) > 0) || (value  - ceil(value) < 0);
}

// Method that clears the input stream and allows user to input a value again.
// The stream (std::cin in this case) is sent this way as a parameter. I found it that way.
// SOURCE: Stack Overflow: How to pass cin to a function?
void allowInputNumberAgain(std::istream& stream){
    /* Last read failed either due to I/O error EOF.
        Or the last stream of chars wasn't a valid number.*/
    cout << "\n - ENTER A VALID NUMBER - \n";
    // Establecer el stream como true para que no se cicle después.
    // Esto se logra limpiando el mal estado del input stream.
    stream.clear(); // Reset failbit. Reset the state of the stream.

    /* Skip bad input.
        We use cin.ignore to expunge the remaining input,
            and then request that the user re-input.
        SOURCE: Stack Overflow: How to check if input is numeric in C++.*/
    stream.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}
// Function that allows the user to choose what to do from the menu.
// Option passes by reference not to return it from the function.
void selectOption(int *option){
    float auxOption = 0; // Por si se ingresa una opción que sea float.
    bool validNumber = false;

    while(!validNumber){
		// system("clear"); // Limpia la pantalla, pero no se pudo incluir su biblioteca.
		cout<< "\n - MENU:\n\t1. Simple Thread.\n\t2. Example of threads (FCFS).";
        cout << "\n\t3. Producer-Consumer (FCFS)\n\t4. Threads (Priority)\n\t5. Exit";
        cout << "\n\n ->  Select one option: ";
		cin >> auxOption;

		// También valida que el número ingresado no sea flotante.
		// Si la diferencia entre el floor y el valor es > 0, es flotante (decimales).
		if(isEnteredValueNotInt(cin, auxOption)){ // !std::cin || std::cin.fail();
            // Here the input stream is cleaned, wich allows user to input data again.
            allowInputNumberAgain(cin);
			continue; // Volver al inicio del ciclo.
		}
		*option = auxOption; // Si el auxiliar no es flotante ni cadena o no válido, asignarlo.
		/* Si se estableció un número válido (no se reinició el proceso con
			el continue), hacer la variable true y salir del ciclo.*/
		validNumber = true;
	}
    cout << endl;
}

// Método que preguntará por la prioridad del hilo del 0 al 5.
int askPriority(int threadNumber){
    float priority = 0.0;
    bool validNumber = false;

    while(!validNumber){
        cout << "\n - Enter the priority number of the thread" << threadNumber << "\n [" << maxPriority << " is the most priority and " << minPriority << " is the least]: ";
        cin >> priority;

		// También valida que el número ingresado no sea flotante.
		// Si la diferencia entre el floor y el valor es > 0, es flotante (decimales).
		if(isEnteredValueNotInt(cin, priority) || priority < maxPriority || priority > minPriority){ // !std::cin || std::cin.fail();
            // Here the input stream is cleaned, wich allows user to input data again.
            allowInputNumberAgain(cin);
			continue; // Volver al inicio del ciclo.
		}
		/* Si se estableció un número válido (no se reinició el proceso con
			el continue), hacer la variable true y salir del ciclo.*/
		validNumber = true;
    }
    // Regresar la prioridad.
    return priority;
}

// For ordering in a simple way in descending order (largest to shortest).
void bubbleSortDescending(int array[MAX]){
    int temp = 0;
    bool swapped = false; // To check if the value was already swapped.
    // Walking through the array.
    for(int step = 0; step < MAX - 1; step++){
    	// Make the comparisons.
		for(int i = 0; i < MAX - 1; i++)
		    // Si el siguiente es mayor que el actual.
		    if(array[i + 1] > array[i]){
		        temp = array[i];
		        array[i] = array[i + 1];
		        array[i + 1] = temp;
                swapped = true;
		    }
        // If there is no swapping in the last swap,
        //  then the array is already sorted.
        if(!swapped) break;
    }
}

// Returns the max value between 2 values.
/* Had to change the name because it had conflict with:
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
	*/
int findMax(int a, int b){
    // If a is more than b, returns a. Else, it return b.
    return a > b? a : b;
}

// Función recursiva que calcula el factorial de un número.
// Recursive function that calculates the factorial of a number.
int factorial(int n){
    /* This is the same as:
        if(n <= 1)
            return 1;
        else
            return n * factorial(n - 1); */
    return n <= 1? 1 : n * factorial(n - 1);
}

// Función para que el usuario llene el arreglo.
// Function for the user to fill the array.
void fillArray(){
	float value; // To check if a float is given, keep the floor.
    cout << "\n - Enter the " << MAX << " elements: " << endl;
    for(int i = 0; i < MAX; ){
        cout << "[" << i << "]: ";
		cin >> value;

		/* To check if the entered value is a number or not:
			"Under normal circumstances the std::cin as all istreams does not
				throw an exception when the data provided does not fit. The
				stream changes its internal state to false. So you may simply
				do something like:"*/
        /* This checks if the entered value is a float.
            (value - floor(value) > 0)*/
		if(isEnteredValueNotInt(cin, value)){ // !std::cin || std::cin.fail()
            // Here the input stream is cleaned, wich allows user to input data again.
            allowInputNumberAgain(cin);
			continue; // Volver al inicio del ciclo.
		}

		// El valor es entero, por lo que se le asigna al arreglo (de enteros).
        Buffer[i] = value;
        cout << endl;
        // Como no entró a la condición anterior y no falló, aumentar el iterador.
        i++;
    }
}

// Función que imprime el arreglo.
// Function that prints the array.
void printArray(){
    for(int i = 0; i < MAX; i++)
        cout << "[" << Buffer[i] << "] ";
    cout << endl;
}

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(int which)
{
    int num;

    for (num = 0; num < 5; num++) {
	    printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}

/* Thread 1 –it needs to sort the numbers in Buffer in
descending order. Once the numbers are sorted, it prints out the
array. */
void Thread1_Actions(int which){
    // Prints the number of the thread. Just to use the parameter, which must be
        // a parameter.
    printf("\n*** thread %d\n", which);

    // Ordena el arreglo de menor a mayor.
    // Sorting the array in descending order.
    // sort(Buffer, Buffer + sizeof(Buffer) / sizeof(int));

    // Sorts the array in descending order.
    bubbleSortDescending(Buffer);

    /* Invierte los elementos del arreglo. Ahora está ordenados
    descendientementede, es decir, mayor a menor. */
    /* Reversing the elements of the array. This means they are in
        descending order.*/
    // reverse(Buffer, Buffer + sizeof(Buffer) / sizeof(int));

    // Imprime el arreglo ordenado.
    // Printing the sorted array.
    cout<<"\n - Sorted Array: ";
    printArray();

    /* Context switch back and forth between Threads by calling Thread::Yield.
        This allows to go back to the main Thread (ThreadTest) and continue
            its execution.*/
    currentThread->Yield();
}

/* Thread 2 –it finds the largest number in Buffer, and
calculates its factorial. It prints the array, the largest
number, and its factorial. */
void Thread2_Actions(int which){

    // Prints the number of the thread. Just to use the parameter, which must be
        // a parameter.
    printf("\n*** thread %d\n", which);

    /* Tomando en cuenta que el arreglo está en orden
        descendiente (mayor a menor), el primer elemento es el máximo.*/
    /* Taking in count the array is already in descending order, the first
        element is the largest. */
    int maxElement = Buffer[0];
    // Aún así, la instrucción pide que se encuentre el número más grande.
    // Finding the largest number iterating through the array.
    for(int i = 0; i < MAX; i++)
        maxElement = findMax(maxElement, Buffer[i]);
    if(maxElement >= 0) // Sí tiene factorial por ser positivo el valor.
        // Se imprime el factorial del número más grande.
        // Printing the factorial of the largest number.
        cout << "\n - [Factorial of maximum element [" << maxElement << "]: " << factorial(maxElement) << "]" << endl;
    else
        /* Al ser número negativo el máximo no tiene factorial en
            números reales, solo en números complejos.*/
        cout << "\n -> Maximum element [" << maxElement << "] is negative. Real number factorial is not possible." << endl;

    /* Context switch back and forth between Threads by calling Thread::Yield.
        This allows to go back to the main Thread (ThreadTest) and continue
            its execution.*/
    currentThread->Yield();
}

/* Thread 3 –it calculates the average of the numbers in Buffer.
It prints the array, and the average value of its numbers.*/
void Thread3_Actions(int which){
    float avg = 0; // For the average of the values of the array.
    int sum = 0; // Acumulator of values of the array.

    // Prints the number of the thread. Just to use the parameter, which must be
        // a parameter.
    printf("\n*** thread %d\n", which);

    // Hace la sumatoria de los valores del arreglo.
    // It sums all the values of the array.
    for(int i = 0; i < MAX; i++)
        sum += Buffer[i];

    // Printing the array.
    cout << "\n - Elements: ";
    printArray();

    // Calcula y muestra el promedio de los elementos del arreglo.
    // Calculating and showing the average of the elements of the array.
    // avg = (float)sum / sizeof(Buffer) / sizeof(int);
    // I think it is necessary to use the CAST in order to save the value.
    avg = (float)sum / (float)MAX;
    cout << "\n - [Average: " << avg << "]\n" << endl;

    /* Context switch back and forth between Threads by calling Thread::Yield.
      This allows to go back to the main Thread (ThreadTest) and continue
          its execution.*/
    currentThread->Yield();
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between two threads, by forking a thread
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest()
{
    DEBUG('t', "Entering SimpleTest");
    // Buffer[MAX] = {}; // Initialize array with 0s. // Enabled by default.
    int option = 0, maxOption = 5;
    // Thread *tSimple;
    // Thread *t[3]; // Array of Threads.
    // Thread* t; // This was possible for this, but not for the others.
    while(option != maxOption){
        /* Option chosen by the user is executed once, and the program finishes
            regardless what option was chosen. (Once code has been compiled,
            every single option can be modified without modifying the code
            again). */
        selectOption(&option);
        switch(option){
            case 1:
            {   // Creamos un ámbito para declarar variable en el case.
                /* Option 1 –the original code of NachOS will be executed
                (2 threads are created and execute SimpleThread() function) */
                Thread *t = new Thread("forked thread");

                t->Fork(SimpleThread, 1);
                SimpleThread(0);
                break;
            }
            case 2:
            {   /* Iniciamos ámbito para declarar variables en el case.
                    FUENTE: Tengo un error "crosses initialization of 'jugador
                    p3' al usar el switch en C++

                    https://es.stackoverflow.com/questions/103834/tengo-un-error-crosses-initialization-of-jugador-p3-al-usar-el-switch-en-c*/

                // Para declarar las variables aquí.
                /* Option 2 –the program will create 3 threads that will share
                an array of integers, named Buffer. Size of the array is 6, and
                the elements of this array will be asked the user to be entered.
                */
                // Que el usuario ingrese los datos del arreglo.
                // The user will enter the values of the array.
                fillArray();
                /* Thread 1 –it needs to sort the numbers in Buffer in
                descending order. Once the numbers are sorted, it prints out the
                array. */
                Thread *t1 = new Thread("Forked thread 1.");
                // *t[0] = new Thread("Forked thread 1.");
                t1->Fork(Thread1_Actions, 1);

                /* Thread 2 –it finds the largest number in Buffer, and
                calculates its factorial. It prints the array, the largest
                number, and its factorial. */
                Thread *t2 = new Thread("Forked thread 2.");
                // *t[1] = new Thread("Forked thread 2.");
                t2->Fork(Thread2_Actions, 2);

                /* Thread 3 –it calculates the average of the numbers in Buffer.
                Itprints the array, and the average value of its numbers.*/
                Thread *t3 = new Thread("Forked thread 3.");
                // *t[2] = new Thread("Forked thread 3.");
                t3->Fork(Thread3_Actions, 3);

                /* Context switch back and forth between Threads by calling Thread::Yield.
				  This allows to go back to the main Thread (ThreadTest) and continue
					  its execution.*/
				/* This allows to show the result of the
					past Threads (execute them), or at least that is
					what I understood.*/
                currentThread->Yield();
                break;
            }
            case 3: cout << "\n 3. Producer-Consumer (FCFS) IS NOT AVAILABLE YET." << endl; break;
            case 4: /* The same as Option 2 but with priorities.*/
            {   /* Threads (Priority)*/
                // Que el usuario ingrese los datos del arreglo.
                // The user will enter the values of the array.
                fillArray();
                /* If user choses option 4, he needs to enter a priority value
                    for each thread. Give values from 0 to 5 to these
                    priorities, where 0 is the highest priority. */
                Thread *t1P = new Thread("Priority Thread 1.");
                t1P->setPriority(askPriority(1));
                Thread *t2P = new Thread("Priority Thread 2.");
                t2P->setPriority(askPriority(2));
                Thread *t3P = new Thread("Priority Thread 3.");
                t3P->setPriority(askPriority(3));
                /* Luego de haber ingresado la prioridad de cada uno de los
                    hilos, hacer un while o algo para que se ejecute el de menor
                    prioridad. Si tienen la misma prioridad, se ejecutará el
                    que haya llegado antes.
                    - Ahora que revisé el código, creo que el mismo Yield haría
                        esta revisión.*/

                // Ya que están todos los hilos listos, utilizar el Fork.
                t1P->Fork(Thread1_Actions, 1);
                t2P->Fork(Thread2_Actions, 2);
                t3P->Fork(Thread3_Actions, 3);
                
                // Como los hilos no corren en orden, hay que darles el CPU
                // 	manualmente.
                currentThread->Yield(); // 1
                currentThread->Yield(); // 2
                currentThread->Yield(); // 3
                break;
            }
            case 5: cout << "\n -> You have exited selection." << endl; break;
            default: cout << "\n -> Enter a valid number between 1 and " + maxOption << endl; break;
        }
    }
}
