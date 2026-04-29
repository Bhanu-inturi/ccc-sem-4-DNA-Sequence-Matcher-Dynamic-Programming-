#include <bits/stdc++.h>
using namespace std;

// Global DP table to reuse for printing
vector<vector<int>> dp;
string X, Y;

// Validate DNA string
bool isValidDNA(string s) {
    for (char c : s) {
        if (c != 'A' && c != 'T' && c != 'G' && c != 'C') {
            return false;
        }
    }
    return true;
}

// Compute LCS
pair<int, string> computeLCS() {
    int n = X.size(), m = Y.size();
    dp.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct LCS
    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs += X[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return {dp[n][m], lcs};
}

// Print DP Table
void printDPTable() {
    if (dp.empty()) {
        cout << "\n⚠️ Run comparison first!\n";
        return;
    }

    cout << "\nDP Table:\n\n   ";
    for (char c : Y) cout << c << " ";
    cout << "\n";

    for (int i = 0; i < dp.size(); i++) {
        if (i == 0) cout << " ";
        else cout << X[i - 1];

        cout << " ";
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n===== DNA Sequence Matcher =====\n";
        cout << "1. Compare DNA Sequences\n";
        cout << "2. Show DP Table\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "\nEnter DNA Sequence 1: ";
            cin >> X;

            cout << "Enter DNA Sequence 2: ";
            cin >> Y;

            if (!isValidDNA(X) || !isValidDNA(Y)) {
                cout << "❌ Invalid DNA sequence! Use only A, T, G, C.\n";
                break;
            }

            auto result = computeLCS();

            int len = result.first;
            string lcs = result.second;

            double similarity = (2.0 * len) / (X.length() + Y.length()) * 100;

            cout << "\n✅ LCS: " << lcs << endl;
            cout << "Length: " << len << endl;
            cout << "Similarity: " << similarity << "%\n";

            break;
        }

        case 2:
            printDPTable();
            break;

        case 3:
            cout << "\nExiting...\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
