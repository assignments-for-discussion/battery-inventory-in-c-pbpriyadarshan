/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
    int healthy;
    int exchange;
    int failed;
};

// Function to classify batteries by their state of health (SoH)
struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) 
{
    struct CountsBySoH counts = {0, 0, 0};
    const int ratedCapacity = 120; // Rated capacity of new batteries which can be accepted from users also

    for (int i = 0; i < nBatteries; i++)
    {
        double sohPercentage = (100.0 * presentCapacities[i]) / ratedCapacity;

        if (sohPercentage > 80.0) 
        {
            counts.healthy++;
        }
        else if (sohPercentage > 62.0) 
        {
            counts.exchange++;
        } 
        else
        {
            counts.failed++;
        }
    }

    return counts;
}

void displayBatteryCounts(struct CountsBySoH counts) 
{
    printf("\nHealthy batteries: %d\n", counts.healthy);
    printf("Batteries for exchange: %d\n", counts.exchange);
    printf("Failed batteries: %d\n\n", counts.failed);
}

void testBucketingByHealth()
{
    const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
    const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
    printf("Counting batteries by SoH with capacity  ");
    for(int i=0;i<numberOfBatteries;i++)
    printf("%d " ,presentCapacities[i]);
    
    
    
    struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
    
    assert(counts.healthy == 2);  // 113, 116 -> healthy
    assert(counts.exchange == 3);  // 80, 95, 92 -> exchange
    assert(counts.failed == 1);     // 70 -> failed
    displayBatteryCounts(counts);
    
    // Additional test cases for boundary conditions
    const int boundaryCases[] = {120, 96, 79, 61, 0};
    const int numberOfBoundaryBatteries = sizeof(boundaryCases) / sizeof(boundaryCases[0]);
    printf("Counting batteries by SoH with capacity  ");
    for(int i=0;i<numberOfBoundaryBatteries;i++)
    printf("%d " ,boundaryCases[i]);
    
    struct CountsBySoH boundaryCounts = countBatteriesByHealth(boundaryCases, numberOfBoundaryBatteries);
    
    assert(boundaryCounts.healthy == 1);   // 120 -> healthy
    assert(boundaryCounts.exchange == 2);   // 96, 79 -> exchange
    assert(boundaryCounts.failed == 2);      // 61, 0 -> failed
    displayBatteryCounts(boundaryCounts);
    printf("Done counting :)\n");
}

int main() {
    testBucketingByHealth();
    return 0;
}


