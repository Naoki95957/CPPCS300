#include <iostream>
#include "Queue/ArrayQueue.h"
#include "Queue/LinkedQueue.h"

int main()
{   
    ArrayQueue<int> arrTest = ArrayQueue<int>(5);
    arrTest.enqueue(1);
    arrTest.enqueue(2);
    arrTest.enqueue(3);
    arrTest.enqueue(4);
    arrTest.enqueue(5);

    int count = 3;

    while(!arrTest.isEmpty() && count != 0)
    {
        std::cout << arrTest.dequeue() << std::endl;
        --count;
    }

    arrTest.enqueue(1);
    arrTest.enqueue(2);
    arrTest.enqueue(3);

    while(!arrTest.isEmpty())
    {
        std::cout << arrTest.dequeue() << std::endl;
    }

    /**
     * I expect this output in the terminal regardless of which type it is:
     * 1
     * 2
     * 3
     * 4
     * 5
     * 1
     * 2
     * 3
     * */

    return 0;
}