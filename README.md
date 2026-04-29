# ccc-sem-4-DNA-Sequence-Matcher-Dynamic-Programming-

-- DNA Sequence Matcher using Dynamic Programming
-- Problem Statement

This project compares two DNA sequences and finds their similarity using the Longest Common Subsequence (LCS) algorithm.

-- Algorithm Used

Dynamic Programming (LCS)

Builds a 2D table storing subproblem results
Avoids recomputation
Efficient for sequence comparison
-- Features
Compare two DNA sequences
Input validation (only A, T, G, C allowed)
Displays:
Longest Common Subsequence
Length
Similarity percentage
DP Table visualization
Menu-driven interface
-- Sample Run

Input:

DNA1: AGGTAB
DNA2: GXTXAYB

Output:

LCS: GTAB
Length: 4
Similarity: 57.14%
-- Time & Space Complexity
Time Complexity: O(n × m)
Space Complexity: O(n × m)


-- How to Run
g++ dna.cpp -o dna
./dna

-- Conclusion

This project demonstrates how Dynamic Programming can efficiently solve sequence comparison problems like DNA matching.
