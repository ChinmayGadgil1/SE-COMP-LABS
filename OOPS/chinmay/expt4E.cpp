#include <iostream>
#include <vector>

struct Vector {
    double x, y, z;
};

int main() {
    int n;
    double scalar;

    std::cout << "Enter the number of elements in the vector: ";
    std::cin >> n;

    std::vector<Vector*> vector1(n);
    std::vector<Vector*> vector2(n);
    std::vector<Vector*> result(n);

    std::cout << "Enter the scalar value: ";
    std::cin >> scalar;

    // Input vector1
    std::cout << "Enter the elements of vector1 (x y z):" << std::endl;
    for (int i = 0; i < n; i++) {
        vector1[i] = new Vector;
        std::cin >> vector1[i]->x >> vector1[i]->y >> vector1[i]->z;
    }

    // Input vector2
    std::cout << "Enter the elements of vector2 (x y z):" << std::endl;
    for (int i = 0; i < n; i++) {
        vector2[i] = new Vector;
        std::cin >> vector2[i]->x >> vector2[i]->y >> vector2[i]->z;
    }

    // Multiply scalar with each element of vector1
    for (int i = 0; i < n; i++) {
        result[i] = new Vector;
        result[i]->x = scalar * vector1[i]->x;
        result[i]->y = scalar * vector1[i]->y;
        result[i]->z = scalar * vector1[i]->z;
    }

    // Display the result of scalar multiplication
    std::cout << "Result of scalar multiplication:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << result[i]->x << " " << result[i]->y << " " << result[i]->z << std::endl;
    }

    // Add vector1 and vector2
    for (int i = 0; i < n; i++) {
        result[i]->x = vector1[i]->x + vector2[i]->x;
        result[i]->y = vector1[i]->y + vector2[i]->y;
        result[i]->z = vector1[i]->z + vector2[i]->z;
    }

    // Display the result of vector addition
    std::cout << "Result of vector addition:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << result[i]->x << " " << result[i]->y << " " << result[i]->z << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete vector1[i];
        delete vector2[i];
        delete result[i];
    }

    return 0;
}