import tkinter as tk
from tkinter import messagebox

# Function to validate DNA sequence
def is_valid_dna(seq):
    for char in seq:
        if char not in "ATGC":
            return False
    return True

# Function to compare sequences
def compare_sequences():
    seq1 = entry_seq1.get().upper()
    seq2 = entry_seq2.get().upper()

    if not seq1 or not seq2:
        messagebox.showerror("Error", "Please enter both sequences!")
        return

    if not is_valid_dna(seq1) or not is_valid_dna(seq2):
        messagebox.showerror("Error", "DNA sequence must contain only A, T, G, C!")
        return

    min_len = min(len(seq1), len(seq2))
    matches = 0
    result_str = ""

    for i in range(min_len):
        if seq1[i] == seq2[i]:
            matches += 1
            result_str += f"{seq1[i]} "
        else:
            result_str += f"({seq1[i]}/{seq2[i]}) "

    match_percent = (matches / min_len) * 100

    output_text.delete("1.0", tk.END)
    output_text.insert(tk.END, f"Matches: {matches}/{min_len}\n")
    output_text.insert(tk.END, f"Match Percentage: {match_percent:.2f}%\n\n")
    output_text.insert(tk.END, "Comparison:\n")
    output_text.insert(tk.END, result_str)

# Create main window
root = tk.Tk()
root.title("DNA Sequence Matcher")
root.geometry("500x400")

# Labels and inputs
tk.Label(root, text="Enter DNA Sequence 1:").pack(pady=5)
entry_seq1 = tk.Entry(root, width=50)
entry_seq1.pack()

tk.Label(root, text="Enter DNA Sequence 2:").pack(pady=5)
entry_seq2 = tk.Entry(root, width=50)
entry_seq2.pack()

# Compare button
tk.Button(root, text="Compare", command=compare_sequences, bg="green", fg="white").pack(pady=10)

# Output box
output_text = tk.Text(root, height=10, width=60)
output_text.pack(pady=10)

# Run app
root.mainloop()
