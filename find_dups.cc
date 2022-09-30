
// Finding Duplicates Using in place hash map
//

#include <iostream>

using namespace std;
  
int main()
{
    int numRay[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
    int arr_size = sizeof(numRay) / sizeof(numRay[0]);
    // count the frequency
    for (int i = 0; i < arr_size; i++) {

            cout << " for value " << numRay[i] ;
            cout << " putting " << numRay[numRay[i] % arr_size] + arr_size <<
			" into index " << numRay[i] % arr_size << endl;


        numRay[numRay[i] % arr_size]
            = numRay[numRay[i] % arr_size] + arr_size;
    }
    cout << "The repeating elements are : " << endl;
    for (int i = 0; i < arr_size; i++) {

        if (numRay[i] >= arr_size * 2) {
            cout << i << " " << endl;
        }
    }
    return 0;
}
