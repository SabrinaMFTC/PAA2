#include <stdio.h>
#define MAXM 400    // Maximum number of connections between buildings (m)
#define MAXN 20     // Maximum number of buildings (n)


typedef struct {
    int id;
    char name[100];
    int distances[MAXM];
} Building;


int max(Building b[], Building c[], int n) {
    for (int i = )
}


void kcenters(Building b[], int n, int k) {
    // Struct array of k centers
    Building centers[k];
    // First center is chosen to be the first building
    centers[0] = b[0];

    for (int i = 1; i < k; ++i) {
        int maxD = 0;
        int idx = 1;

        for (int j = 2; j < n; ++j)
            if (b[0].distances[j] > maxD) {
                maxD = b[0].distances[j];
                idx = j;
            }
        
        centers[i] = b[idx];
    }

}


int main() {

    FILE *input = fopen("input.txt", "r");

    if (input == NULL) {
        printf("Error while trying to open the file \"input.txt\".\n");
        return -1;
    }

    // Number of buildings
    int n;
    // Number of desired centers
    int k;
    fscanf(input, "%d %d", &n, &k);

    // Array of Building structs
    Building buildings[MAXN];

    // Store building's names and ids
    for (int i = 0; i < n; ++i) {
        fscanf(input, " %[^\n]", buildings[i].name);
        buildings[i].id = (i + 1);
    }

    // Number of connections between buildings
    int m;
    fscanf(input, "%d", &m);

    // Store distances between buildings
    int x, y, z;

    for (int i = 0; i < m; ++i) {
        fscanf(input, "%d %d %d", &x, &y, &z);
        buildings[x - 1].distances[y - 1] = z;
        buildings[y - 1].distances[x - 1] = z;
    }

    // Debugging: print all data from buildings
    for (int i = 0; i < n; ++i) {
        printf("Name: %s\nID: %d\n", buildings[i].name, buildings[i].id);

        for (int j = 0; j < n; ++j) 
            printf("Distance between building %d and %d: %d\n", buildings[i].id, buildings[j].id, buildings[i].distances[j]);
    }

    kcenters(buildings, n, k);

    // Close file
    fclose(input);

    return 0;
}