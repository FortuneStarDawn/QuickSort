#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void quickSort(vector<int> &A, int start, int end);
int Hoare_partition(vector<int> &A, int start, int end);

int main()
{
    string line;
    stringstream ss;
    int element;
    vector<int> A;

    getline(cin, line);
    ss<<line;
    while(ss>>element) A.push_back(element);

    quickSort(A, 0, A.size()-1);
    for(int i=0; i<A.size(); i++) cout<<A.at(i)<<' ';
    cout<<endl;
    return 0;
}

void quickSort(vector<int> &A, int start, int end)
{
    if(start >= end) return;
    int mid = Hoare_partition(A, start, end);
    quickSort(A, start, mid);
    quickSort(A, mid+1, end);
}

int Hoare_partition(vector<int> &A, int start, int end)
{
    int pivot, left, right, temp;
    pivot = A.at(start);
    left = start - 1;
    right = end + 1;

    while(1)
    {
        do{left++;}  while(A.at(left) < pivot);
        do{right--;} while(A.at(right) > pivot);
        if(left >= right) return right;
        temp = A.at(left);
        A.at(left) = A.at(right);
        A.at(right) = temp;
    }
}
