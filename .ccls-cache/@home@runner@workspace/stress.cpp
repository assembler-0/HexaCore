#include <atomic>
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

std::atomic<int> score(0);
void stressCPU(int threadId, int workDurationSeconds) {
  auto start = std::chrono::high_resolution_clock::now();
  int workDone = 0;

  while (std::chrono::duration<double>(
             std::chrono::high_resolution_clock::now() - start)
             .count() < workDurationSeconds) {
    for (int i = 2; i < 10000; ++i) {
      bool isPrime = true;
      for (int j = 2; j <= std::sqrt(i); ++j) {
        if (i % j == 0) {
          isPrime = false;
          break;
        }
      }
      if (isPrime) {
        workDone++;
      }
    }
  }
  score.fetch_add(workDone, std::memory_order_relaxed);
  std::cout << "Thread " << threadId << " completed with " << workDone
            << " primes calculated.\n";
}

int main() {
  int numCores = std::thread::hardware_concurrency();
  int workDurationSeconds = 5;
  std::cout << "Starting CPU stress test for " << workDurationSeconds
            << " seconds using " << numCores << " cores...\n";

  std::vector<std::thread> threads;
  for (int i = 0; i < numCores; ++i) {
    threads.push_back(std::thread(stressCPU, i + 1, workDurationSeconds));
  }
  for (auto &t : threads) {
    t.join();
  }
  std::cout << "Stress test completed. Total work done: " << score.load()
            << " prime numbers calculated.\n";

  return 0;
}
