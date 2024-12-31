#include <iostream>
#include <chrono>
#include <cmath>
#include <thread>
#include <vector>

void cpuTask(int iterations, double& result) {
    double local_result = 0.0;
    for (int i = 0; i < iterations; ++i) {
        local_result += std::sin(i) * std::cos(i) + std::sqrt(i);
    }
    result = local_result; // Store the result to prevent compiler optimizations
}

int main() {
    // Configuration
    const int numThreads = std::thread::hardware_concurrency(); // Detect available cores
    const int iterationsPerThread = 50'000'000; // Number of iterations per thread
    std::vector<std::thread> threads;
    std::vector<double> results(numThreads, 0.0);

    std::cout << "CPU Stress Test Starting...\n";
    std::cout << "Detected " << numThreads << " CPU cores.\n";

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // Launch threads to perform CPU-intensive tasks
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(cpuTask, iterationsPerThread, std::ref(results[i]));
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    // Calculate performance score
    double totalResult = 0.0;
    for (const auto& res : results) {
        totalResult += res; // Sum up results to ensure work was done
    }

    double score = (numThreads * iterationsPerThread) / duration.count();
    std::cout << "\n--- CPU Test Complete ---\n";
    std::cout << "Execution Time: " << duration.count() << " seconds\n";
    std::cout << "Performance Score: " << static_cast<int>(score) << " FLOPS (approx.)\n";
    std::cout << "Verification Output: " << totalResult << " (ignore this)\n";

    return 0;
}
