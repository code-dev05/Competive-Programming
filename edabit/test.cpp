#include <iostream>
#include <queue>
#include <vector>

struct Compare {
    bool operator()(int a, int b) {
        return a > b; // For min-heap, return true if a > b
    }
};

int main() {
    // Create a priority queue with a min-heap
    std::priority_queue<int, std::vector<int>, Compare> pq;

    // Add elements to the priority queue
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Print and remove elements from the priority queue
    while (!pq.empty()) {
        std::cout << pq.top() << std::endl; // Print the top element
        pq.pop(); // Remove the top element
    }

    return 0;
}
