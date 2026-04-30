# ccc-sem-4-DNA-Sequence-Matcher-Dynamic-Programming-

DNA Sequence Matcher (Tkinter GUI)
-- Overview

The DNA Sequence Matcher is a simple Python GUI application built using Tkinter. It allows users to input two DNA sequences and compare them to determine:

Number of matching bases
Match percentage
Position-wise comparison

This tool is useful for basic bioinformatics learning and sequence analysis.

-- Features
. User-friendly GUI
. Validates DNA sequences (only A, T, G, C allowed)
. Calculates match count and percentage
. Displays aligned comparison of sequences
. Error handling for invalid or empty inputs
-- Technologies Used
Python 3
Tkinter (built-in GUI library)
 Project Structure
dna-sequence-matcher/
│
├── main.py        # Main application file
└── README.md      # Project documentation
-- How to Run
1. Clone or Download the Repository
git clone <your-repo-link>
cd dna-sequence-matcher
2. Run the Application
python main.py
-- How It Works
Enter two DNA sequences in the input fields
Click the Compare button
The program will:
Validate sequences
Compare base-by-base
Display:
Matches (e.g., 5/8)
Match Percentage
Detailed comparison
   --Example Output
Matches: 5/8
Match Percentage: 62.50%

Comparison:
A T (G/C) A (T/G) C A T
Validation Rules
Only characters allowed: A, T, G, C
Inputs cannot be empty
- Future Improvements
Add support for RNA sequences
Highlight mismatches with colors
File upload for large sequences
Alignment algorithms (Needleman-Wunsch, etc.)
Export results to file
