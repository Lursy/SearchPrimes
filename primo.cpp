#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

std::vector<bool> is_prime(int limit) {
    std::vector<bool> primes(limit + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= limit; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= limit; j += i) {
                primes[j] = false;
            }
        }
    }

    for (int i = 3; i * i <= limit; i += 2) {
        if (primes[i]) {
            for (int j = i * i; j <= limit; j += i * i) {
                primes[j] = false;
            }
        }
    }

    return primes;
}

int main() {
    long int limit = 10000000;
    // scanf("%ld", &limit);

    auto start = std::chrono::steady_clock::now();

    std::vector<bool> primes = is_prime(limit);

    // Use a vector of integers to store the prime numbers.
    std::vector<int> prime_numbers;
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            prime_numbers.push_back(i);
        }
    }

    std::sort(prime_numbers.begin(), prime_numbers.end());

    // Print the list of prime numbers.
    for (int i = 0; i < prime_numbers.size(); i++) {
        std::cout << prime_numbers[i] << " ";
    }

    std::cout << std::endl;

    // Print the execution time.
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_elapsed = end - start;
    std::cout << "Execution time: " << time_elapsed.count() << " seconds" << std::endl;

    return 0;
}
