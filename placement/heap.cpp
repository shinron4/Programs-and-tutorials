#include <climits>
#include <iostream>

using namespace std;

class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
public:
MinHeap(int cap=100) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};

/* Removes min element from min heap and returns it */

int MinHeap ::  extractMin()
{   
    cout << "extractMin\n";
    if(heap_size == 0) return -1;
    int x = harr[0];
    swap(harr[0], harr[heap_size - 1]);
    heap_size--;
    int i = 1, l = i << 1, r = i << 1 | 1;
    while(l <= heap_size){
        cout << i << " " << l << " " << r << "\n";
        int m = i;
        if(l <= heap_size && harr[l - 1] < harr[i - 1]) m = l;
        if(r <= heap_size && harr[r - 1] < harr[m - 1]) m = r;
        if(m != i){
            swap(harr[m - 1], harr[i - 1]);
            i = m;
            l = i << 1;
            r = i << 1 | 1;
        }
        else break;
    }
    return x;
}

/* Removes element from position x in the min heap  */

void MinHeap :: deleteKey(int x)
{
    cout << "delete\n";
   x++;
   if(x >= 1 && x <= heap_size){
        harr[x - 1] = -INT_MAX;
        int q = x, p = x >> 1;
        while(p > 0 && harr[q - 1] < harr[p - 1]){
            cout << p << " " << q << "\n";
            swap(harr[q - 1], harr[p - 1]);
            q = p;
            p = q >> 1;
        }
        extractMin();
   }
}

/* Inserts an element with value x into the min heap*/

void MinHeap ::insertKey(int x)
{
    cout << "insertKey\n";
    if(heap_size < capacity){
        harr[heap_size] = x;
        int q = heap_size + 1, p = q >> 1;
        while(p > 0 && harr[q - 1] < harr[p - 1]){
            cout << p << " " << q << "\n";
            swap(harr[q - 1], harr[p - 1]);
            q = p;
            p = q >> 1;
        }
        heap_size = heap_size + 1;
    }
}

int main(){
    int t, q;
    MinHeap h;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> q;
        for(int j = 0; j < q; j++){
            int type, x;
            cin >> type;
            switch(type){
                case 1: cin >> x;
                        h.insertKey(x);
                        break;
                case 2: cin >> x;
                        h.deleteKey(x);
                        break;
                case 3: cout << h.extractMin();
                        break;
            }
        }
    }
    return 0; 
}
