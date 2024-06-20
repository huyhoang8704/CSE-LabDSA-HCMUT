#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";

        cout << endl;
    }

public:
    // TODO: Write your code here
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total);
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases);
};
template <class T>
static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total){
        int n=end-start;
        for(int i=segment_idx;i<n;i+=cur_segment_total){
            for(int j=i+cur_segment_total; j<n; j+=cur_segment_total){
                if(start[j]<start[i]){
                    int temp=start[j];
                    start[j]=start[i];
                    start[i]=temp;
                }
            }
        }
    } 
template <class T>
static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases){
        for(int i=num_phases-1;i>=0;i--){
            cout<<num_segment_list[i]<<" segments: ";
            for(int j=0;j<num_segment_list[i];j++){
                sortSegment(start,end,j,num_segment_list[i]);
            }
        printArray(start,end);
        }
}
int main(){

int num_segment_list[] = {1, 3, 5};
int num_phases = 3;
int array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
    //!5 segments: 5 4 3 2 1 10 9 8 7 6 
    //!3 segments: 2 1 3 5 4 7 6 8 10 9 
    //!1 segments: 1 2 3 4 5 6 7 8 9 10 
}