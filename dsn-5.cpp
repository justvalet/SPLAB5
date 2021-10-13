#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include <cmath>
using namespace std;
    pthread_t m;     
	void* func(void *);
int main()
{
    setlocale(LC_ALL, "rus");
        pthread_t id[16];
		int t = 0;                                                        
		int a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for (int i = 0; i < 16; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 16; i++)
    {
        pthread_create(&id[i], NULL, func, (void*)&a[i]);//&-берет адресс и переводит в void
    }
        for (int i = 0; i < 16; i++)
		{
            pthread_join (id[i], NULL);
			if (a[i] == 1){
				t++;
			}
        }
    cout << "Всего простых чисел: " << t << endl;
    return (0);
}
void * func(void *arg){

    setlocale(LC_ALL, "rus");
    int j=0;
        cout << *((int*)arg) << endl;
        int n = *((int*)arg);                                                                                       
		long long req = sqrt(n);
        for(long long i=2;i<=req;i++)
                if(n%i==0){
                        *((int*)arg) = 0;
                        return arg;
                }
                *((int*)arg) = 1;
                return arg;
}
