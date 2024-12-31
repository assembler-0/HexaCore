#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>
#include <cmath>

using namespace std;

// Atomic counter to track operations
atomic<long long> operation_count(0);

// Worker function to perform calculations
void cpu_stress_worker(int duration_seconds) {
    auto end_time = chrono::high_resolution_clock::now() + chrono::seconds(duration_seconds);
    while (chrono::high_resolution_clock::now() < end_time) {
        // Perform some intensive math calculations
        for (int i = 0; i < 1000000; ++i) {
            double result = sqrt(pow(i, 2.0)) * sin(i) / cos(i + 1);
            (void)result; // Prevent compiler optimizations
        }
        operation_count.fetch_add(1000000); // Increment the counter
    }
}

// Main function
int main() {
    cout << "CPU Stress Tester with Scoring System" << endl;
    cout << "=====================================" << endl;

    int num_threads = thread::hardware_concurrency();
    int duration_seconds = 10; // Run the test for 10 seconds

    cout << "Number of threads: " << num_threads << endl;
    cout << "Test duration: " << duration_seconds << " seconds" << endl;

    // Create and start threads
    vector<thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(cpu_stress_worker, duration_seconds);
    }

    // Wait for all threads to finish
    for (auto &t : threads) {
        t.join();
    }

    // Calculate the score
    long long total_operations = operation_count.load();
    double score = total_operations / (double)duration_seconds;

    cout << "=====================================" << endl;
    cout << "Test completed!" << endl;
    cout << "Total operations: " << total_operations << endl;
    cout << "Score: " << score << " ops/sec" << endl;

    return 0;
}
