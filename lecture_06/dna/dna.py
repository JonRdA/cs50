"""
DNA identifying program
"""

"""
STEPS

* Open CSV file and read content
* Open DNA sequence
  * For each STR, compute longest run of repeats in DNA

* Compare with csv & see if matches
"""

import sys
import csv

def main():
    # Check for correct arg number
    if len(sys.argv) != 3:
        print("Usage: dna.py database sequence")
    else:
        data_f, seq_f = sys.argv[1:3]
        seq = read_sequence(seq_f)
        print(seq)
        b = count_max(seq, "AGAT")
        b = count_max(seq, "AATG")
        b = count_max(seq, "TATC")
        print(b)

def read_database(data_f):
    """Read database file as list of dicts.
    Args:
        data_f (str): database path

    Returns: 
        database (list): list of dictionaries containing table data.
    """
    with open(data_f, 'r') as db:
        reader = csv.DictReader(db)
        database = [i for i in reader]
    return database

def read_sequence(seq_f):
    """Read sequence file & return dictionary with max counts.

    Args:
        seq_f (str): sequences file

    Returns:
        sequence (str): dna sequence as a string
    """
    with open(seq_f, 'r') as seq:
        sequence = seq.read()
        sequence = sequence.replace('\n', '')
    return sequence

def count_max(sequence, subset):
    """Count maximum number of consecutive occurences of subset in sequence.

    Args:
        sequence (str): sequence where to find the subset.
        subset (str): subset string to find.

    Returns:
        n (int): number of times repeated.
    """
    repeated = [0]
    founds = 0

    i = 0
    while i <= len(sequence) - len(subset):
        sub = sequence[i: i + len(subset)]
        print(f"i: {i}, subset: {sub}")

        # Found a match
        if subset == sub:
            founds += 1
            print(f"i: {i}, subset: {sub}, Found it!!, founds: {founds}")
            i += len(subset)

        else:
            if founds != 0:
                repeated.append(founds)
                founds = 0
            i += 1

    print(repeated)
    return max(repeated)


if __name__ == "__main__":
    main()
