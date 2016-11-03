#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void quickSort(vector<int> &A, int start, int end);
int partition(vector<int> &A, int start, int end);

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
    int mid = partition(A, start, end);
    quickSort(A, start, mid-1);
    quickSort(A, mid+1, end);
}

int partition(vector<int> &A, int start, int end)
{
    int pivot, prefix, temp;
    pivot = A.at(end);
    prefix = start;
    for(int i=start; i<=end; i++)
    {
        if(A.at(i)<=pivot)
        {
            temp = A.at(prefix);
            A.at(prefix) = A.at(i);
            A.at(i) = temp;
            prefix++;
        }
    }
    prefix--;
    return prefix;
}
