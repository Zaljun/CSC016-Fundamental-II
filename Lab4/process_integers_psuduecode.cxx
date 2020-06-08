// includes

// function declarations
void sort(int array[], int size);

int main()
{
    const int MAX_SIZE = 30;
    int hours[MAX_SIZE;

    int actual_size = read_input(hours, MAX_SIZE);  // function call
    // read the input file inside the function read_input
    // testing: print all values in hours from index 0 to actual_size - 1 

    sort(hours, actual_size);
    // testing: print all values in hours from index 0 to actual_size-1

    int search_value;
    cout << "Enter a search value";
    cin  >> search_value;

    while (search_value > 0)
    {
        int index_found = binary_search(hours, actual_size, search_value);
        if  (index_found != -1)
            cout << " Found " << search_value << " at " << index_found << endl;
        else
            cout << search_value << " not found " << endl;

        cout << "Enter a search value";
        cin  >> search_value;
    }
} // end main()

// inside read_input()
    // int index = 0;   
    // while (index < max_size && inFile >> array[index]) index++;  


// implement x sorting algorithm
// function definition
void sort(int array[], int size)
{

}
