#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <vector>
using namespace std::chrono;
using namespace std;
int rrand(int range_min, int range_max) 
{
    return rand() % (range_max - range_min + 1) + range_min;
}
const unsigned int arrSIZE = 100;
const int arrLIMIT = 99;
int arr[arrSIZE];
int Search_Binary(int arr[], int left, int right, int key)
{
   
    int midd = 0;
    while (1)
    {
        midd = (left + right) / 2;

        if (key < arr[midd])       
            right = midd - 1;      
        else if (key > arr[midd])  
            left = midd + 1;	   
        else                       
            return midd;           

        if (left > right)          
            return -1;
    }
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void printArray(int arr[], int size)
{
    cout << "Несортированный массив:\n ";
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " " ;
    cout <<"\n\n\n";
}
void printArrayS(int arr[], int size)
{
    cout << "Сортированный массив:\n";
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " " ;
    cout << "\n\n";
}
int main() 
{  
    setlocale(LC_ALL, "rus");
    int a, b,c,d,e,f,g,j,l,w,buf;
    c = 0; d = 0; e = 0; f = 0;
    srand(static_cast<unsigned int>(time(NULL)));
    for (unsigned int i = 0; i < arrSIZE; i++) 
    {
        arr[i] = rrand(-arrLIMIT, arrLIMIT);

    }
    printArray(arr, arrLIMIT);
    auto start = steady_clock::now();
    int min = arr[0];
    for (int i = 0; i < 100; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    int max = arr[0];
    for (int i = 0; i < 100; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    auto finish = steady_clock::now();
    auto Elapsed_1 = duration_cast<nanoseconds>(finish - start);
    cout <<"Минимальное: " << min << "\n" <<"Максимальное: " << max << " \n" << "Время поиска Мин. и Макс. : " << Elapsed_1.count() << " " << "NANOseconds\n";
    a = (min + max) / 2;
    cout <<"Среднее значение: " << a << "\n";
    cout << "Индексы элементов, равных среднему значению: ";
    auto Start3 = steady_clock::now();
    for (int i = 0; i < 100; ++i)
    {
        if (arr[i] == a)
        {
            c = c++;
            cout << i << " ";
            
        }
        if (c == 0 && i == 99) cout << "Индексы отсутствуют";
    }
    auto Finish3 = steady_clock::now();
    cout << "\n";
    cout << "Количество индексов элементов, равных среднему значению: " << c <<"\n";
    auto ELapsed5 = duration_cast<nanoseconds>(Finish3 - Start3);
    cout << "Время поиска индекса: " << ELapsed5.count() << " " << "NANOseconds\n\n";

    auto begin = steady_clock::now();
    bubbleSort(arr, arrLIMIT);
    auto end = steady_clock::now();
    printArrayS(arr, arrLIMIT);
    auto Start = steady_clock::now();
    int min1 = arr[0];
    int max1 = arr[98];
    auto Finish = steady_clock::now();
    cout << "Минимальное: " << min1 << "\n"  <<"Максимальное: " << max1 << " \n";
    auto ELapsed2 = duration_cast<nanoseconds>(Finish - Start);
    cout << "Время поиска Мин. и Макс. : " << ELapsed2.count() << " " << "NANOseconds\n";
    auto elapsed_3 = duration_cast<microseconds>(end - begin);
    cout << "Время сортировки: " << elapsed_3.count() <<" " << "MICROseconds\n";
    b = (min1 + max1) / 2;
    cout << "Среднее значение: " << b << "\n";
    cout << "Индекс элементов, равные среднему значению: ";
    auto Start2 = steady_clock::now();
    for (int i = 0; i < 100; ++i)
    {
        if (arr[i] == b)
        {
            d = d++;
            cout << i << " ";
        }
        if (b == 0 && i == 99) cout << "Индексы отсутствуют";
    }
    auto Finish2 = steady_clock::now();
    cout << "\n";
    cout << "Количество индексов элементов, равных среднему значению: " << d << "\n";
    auto ELapsed4 = duration_cast<nanoseconds>(Finish2 - Start2);
    cout << "Время на поиск индекса: " << ELapsed4.count() << " " << "NANOseconds\n";
    cout << "Введите элемент (a), который есть в массиве: ";
    cin >> g;
    for (int i = 0; i < 100; ++i)
    {
        if (arr[i] < g)
        {
            e = e++;
        }
    }
    cout <<"Число элементов < a: " << e <<"\n";
    cout << "Введите элемент (b), который есть в массиве: ";
    cin >> j;
    for (int i = 0; i < 100; ++i)
    {
        if (arr[i] > j)
        {
            f = f++;
        }
    }
    cout << "Число элементов > b: " << f << "\n";

    int key = 0;
    int index = 0; 
    cout << "\nВведите любое число: ";
    cin >> key;
    auto start3 = steady_clock::now();
    index = Search_Binary(arr, 0, arrSIZE, key);
    auto finish3 = steady_clock::now();
    auto eLapsed5 = duration_cast<nanoseconds>(finish3 - start3);
    if (index >= 0)
        cout << "Указанное число находится в ячейке с индексом: " << index << "\n\n";
    else
        cout << "В массиве нет такого числа!\n\n";
    
    cout << "Перебором индексы массивов: ";
    auto start4 = steady_clock::now();
    for (int i = 0; i < 100; ++i)
    {
        if (arr[i] == key)
        {
            cout << i << " ";
        }
    }
    auto finish4 = steady_clock::now();
    auto eLapsed6 = duration_cast<nanoseconds>(finish4 - start4);
    cout << "\n";
    cout << "Время затраченное бинарным поиском: " << eLapsed5.count() << " " << "NANOseconds" <<"  <  " << "Время затраченное пиребором: " << eLapsed6.count() << " " << "NANOseconds\n";
    cout << "Введите индексы массива, которые нужно поменять местами(через пробел): ";
    cin >> l >> w;
    swap(arr[l], arr[w]);
    printArray(arr, arrLIMIT);
    return 0;
}
