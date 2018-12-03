#include <string>
#include "pq.hpp"

using std::string;

int main() {
    pq<string> pq1;
    pq1.insert("seven", 7);
    pq1.insert("four", 4);
    pq1.insert("nine", 9);
    pq1.insert("three", 3);
    pq1.insert("five", 5);
    pq1.insert("eleven", 11);
    pq1.insert("two", 2);
    pq1.display_heap();
    pq1.remove_first();
    pq1.display_heap();

    return 0;
}