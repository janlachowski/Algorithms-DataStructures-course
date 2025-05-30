#include <iostream>
#include <array>
#include <vector>

std::vector<std::array<int, 3>> bricks;
std::vector<std::vector<int>> left_len(10001);
std::vector<char> visited;
std::vector<int> stack;
std::vector<std::array<int, 3>> answer;

void dfs(int length) {
    for (int value : left_len[length]) { // adding neighbours to the stack
        stack.push_back(value);
    }
    std::vector<int> empty;
    left_len[length].swap(empty);

    while (!stack.empty()) {
        int brick = stack.back(); // taking last node from stack
        if (visited[brick]) {
            answer.pop_back();
            stack.pop_back();
            continue;
        }
        visited[brick] = 1;

        int brick_right_len = bricks[brick][2];
        
        answer.push_back(bricks[brick]); // adding this node to the answer
        if (brick_right_len == 0) { // if the right length is 0, we've found the answer
            return;
        }

        bool false_end = true;
        if (!left_len[brick_right_len].empty()) {
            for (int value : left_len[brick_right_len]) { // adding neighbours to the stack
                stack.push_back(value);
                false_end = false;
            }
            std::vector<int> temp;
            left_len[brick_right_len].swap(temp);
        }
        
        if (false_end) {
            answer.pop_back();
            stack.pop_back();
        }
    }
    return;
}

int main() {
    int a, b, c, n;
    scanf("%d", &n);
    bricks.resize(n);
    visited.resize(n, 0);
    stack.reserve(n);
    answer.reserve(n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        bricks[i] = {a, b, c};
        left_len[a].push_back(i); // adding i's brick to the container with the same left value
    }

    dfs(0);

    int number_of_bricks = answer.size();

    if (number_of_bricks == 0) {
        printf("BRAK\n");
        fflush(stdout);
        return 0;
    }

    printf("%d\n", number_of_bricks);
    for (const auto& brick : answer) {
        printf("%d %d %d\n", brick[0], brick[1], brick[2]);
    }
    return 0;
}