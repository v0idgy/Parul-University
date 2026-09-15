#include <iostream>
using namespace std;
// Recursive function to solve Tower of Hanoi puzzle
void towerOfHanoi(int n, char source_rod, char destination_rod, char auxiliary_rod)
{
    // Base case: If there is only 1 disk left, move it directly
    if (n == 1)
    {
        std::cout << "Move disk 1 from rod " << source_rod << " to rod " << destination_rod << "\n";
        return;
    }
    // Step 1: Move top n-1 disks from source to auxiliary rod
    towerOfHanoi(n - 1, source_rod, auxiliary_rod, destination_rod);
    // Step 2: Move the remaining largest disk from source to destination rod
    std::cout << "Move disk " << n << " from rod " << source_rod << " to rod " << destination_rod << "\n";
    // Step 3: Move the n-1 disks from auxiliary to destination rod
    towerOfHanoi(n - 1, auxiliary_rod, destination_rod, source_rod);
}
int main()
{
    int num_disks = 3; // You can change this value for more disks

    std::cout << "Steps to solve Tower of Hanoi with " << num_disks << " disks:\n";
    towerOfHanoi(num_disks, 'A', 'C', 'B'); // A = Source, C = Destination, B = Auxiliary

    return 0;
}
