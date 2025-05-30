#include <iostream>
#include <array>
#include <vector>

std::vector<std::pair<int, int>> priority_queue;

void remove_max() {
    if (priority_queue.size() <= 1) return;

    priority_queue[1] = priority_queue.back();
    priority_queue.pop_back();
    long long queue_len = priority_queue.size();
    int i = 1;
    while (true) {
        int j = i;
        if (2*j < queue_len && (long long)priority_queue[i].first * priority_queue[i].second < (long long)priority_queue[2*j].first * priority_queue[2*j].second) {
            i = 2*j;
        }
        if (2*j+1 < queue_len && (long long)priority_queue[i].first * priority_queue[i].second < (long long)priority_queue[2*j+1].first * priority_queue[2*j+1].second) {
            i = 2*j + 1;
        }

        if (j == i) {
            break;  
        }

        std::swap(priority_queue[i], priority_queue[j]);
    }
}

void add_elem(std::pair<int, int> elem) {
    priority_queue.push_back(elem);
    long long i = priority_queue.size() - 1;
    while (true) {
        long long j = i;
        if (j > 1 && (long long)priority_queue[i].first * priority_queue[i].second > (long long)priority_queue[j/2].first * priority_queue[j/2].second) {
            i = j/2;
        }

        if (j == i) {
            break;  
        }

        std::swap(priority_queue[i], priority_queue[j]);
    }
}

int main() {
    int M1, k;
    scanf("%d %d", &M1, &k);
    int M2 = M1;
    priority_queue.reserve(k);
    priority_queue.push_back({-1, -1});
    long long last = 1000000000001;
    priority_queue.push_back({M1, M2});
    while (k > 0) {
        // we only operate on the top triangle of the multiplication table
        auto [bigger, smaller] = priority_queue[1]; 
        long long product = (long long)bigger * smaller;
        if (last > product) {
            last = product;
            std::cout << product << "\n";
            k--;
        }
        remove_max();

        if (bigger == smaller + 1 && bigger > 1) {
            add_elem({bigger - 1, smaller});
        }
        if (smaller > 1) add_elem({bigger, smaller - 1});
    }
    return 0;
}