#include <algorithm>  // for std::max, std::min
#include <array>      // for std::array
#include <cmath>      // for log2
#include <iostream>   // for IO operations

/**
 * @namespace game_theory
 * @brief  game_theory algorithms
 */
namespace game_theory {
/**
 * @brief Check which is the maximum/minimum number in the array
 * @param depth current depth in game tree
 * @param node_index current index in array
 * @param is_max if current index is the longest number
 * @param scores saved numbers in array
 * @param height maximum height for game tree
 * @param memo memoization table to store intermediate results
 * @returns the maximum or minimum number
 */
template <size_t T>
int minimax(int depth, int node_index, bool is_max, const std::array<int, T>& scores,
            double height, std::array<std::array<int, T>, T>& memo) {
    if (depth == height) {
        return scores[node_index];
    }

    if (memo[depth][node_index] != -1) {
        return memo[depth][node_index];
    }

    int v1 = minimax(depth + 1, node_index * 2, !is_max, scores, height, memo);
    int v2 = minimax(depth + 1, node_index * 2 + 1, !is_max, scores, height, memo);

    memo[depth][node_index] = is_max ? std::max(v1, v2) : std::min(v1, v2);
    return memo[depth][node_index];
}
}  // namespace game_theory

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    size_t size;
    std::cout << "Enter the size of the scores array: ";
    std::cin >> size;

    std::array<int, 100> scores;  // Assuming a maximum size of 100 for the scores array
    std::cout << "Enter the scores: ";
    for (size_t i = 0; i < size; i++) {
        std::cin >> scores[i];
    }

    double height = log2(size);

    std::array<std::array<int, 100>, 100> memo;
    for (auto& row : memo) {
        row.fill(-1);
    }

    std::cout << "Optimal value: "
              << game_theory::minimax(0, 0, true, scores, height, memo) << std::endl;
    return 0;
}


//Enter the size of the scores array: 8
//Enter the scores: 90 23 6 33 21 65 123 34423

