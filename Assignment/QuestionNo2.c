#include <stdio.h>

// Recursive function to calculate fuel and return remaining fuel
int calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets)
{
    // Base case: fuel exhausted
    if (fuel <= 0) {
        printf("Planet %d: Fuel depleted. Mission failed!\n", planet);
        return 0;
    }

    // Base case: all planets visited
    if (planet > totalPlanets) {
        printf("All planets visited. Fuel remaining = %d. Mission successful!\n", fuel);
        return fuel;
    }

    // Consume fuel for this planet
    fuel -= consumption;

    // Apply gravitational recharge (if any)
    fuel += recharge;

    // Apply solar recharge every 4th planet
    if (planet % 4 == 0) {
        fuel += solarBonus;
    }

    // Print remaining fuel after this planet
    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);

    // Recursive call for the next planet and return the final fuel
    return calculateFuel(fuel, consumption, recharge, solarBonus, planet + 1, totalPlanets);
}

int main()
{
    int initialFuel = 1000;     // initial fuel
    int consumption = 150;      // fuel consumed per planet
    int recharge = 30;          // gravitational assist bonus
    int solarBonus = 100;       // solar recharge every 4th planet
    int totalPlanets = 10;      // total planets in journey

    int remainingFuel = calculateFuel(initialFuel, consumption, recharge, solarBonus, 1, totalPlanets);

    printf("\nRemaining fuel at the end of journey = %d\n", remainingFuel);

    return 0;
}
