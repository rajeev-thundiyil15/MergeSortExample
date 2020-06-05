#include<stdlib.h> 
#include<stdio.h> 
#include <vector>
#include<iostream>

using namespace std;

void merge(vector<int> a, int Firstindex, int m, int Lastindex); 

void mergeSort(vector <int> a, int Firstindex, int Lastindex)
{
    if (Firstindex < Lastindex)
    {

        int m = Firstindex + (Lastindex - Firstindex) / 2;


        mergeSort(a, Firstindex, m);
        mergeSort(a, m + 1, Lastindex);

        merge(a, Firstindex, m, Lastindex);
    }
}

void merge(vector<int> a, int Firstindex, int m, int Lastindex)
{
    int x;
    int y;
    int z;
    int sub1 = m - Firstindex + 1;
    int sub2 = Lastindex - m;


    vector<int> First (sub1); 


    vector<int> Second(sub2);


    for (x = 0; x < sub1; x++) 
        First[x] = a[Firstindex + x];
    for (y = 0; y < sub2; y++)
        Second[y] = a[m + 1 + y];


    x = 0;
    y = 0;
    z = Firstindex;
    while (x < sub1 && y < sub2)
    {
        if (First[x] <= Second[y])
        {
            a[z] = First[x];
            x++;
        }
        else
        {
            a[z] = Second[y];
            y++;
        }
        z++;
    }
    while (x < sub1)
    {
        a[z] = First[x];
        x++;
        z++;
    }
    while (y < sub2)
    {
        a[z] = Second[y];
        y++;
        z++;
    }
}
int main()
{
    int size;
    int sum = 0;
    cout << "This program will take all of your test scores (by percentage) and have them sorted and to calculate average " << endl;
    cout << "First input how many test scores you have: " << endl;
    cin >> size;
    
    vector<int> data (size);
    
    int num;
    cout << "Enter the elements of the test scores one by one: ";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i << endl;
        cin >> num;
        data[i] = num;
        sum += num;

    }
    mergeSort(data, 0, size - 1);
    cout << "The Sorted List isn";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << "Average is " << (sum/size) << endl;
    return 0;
}