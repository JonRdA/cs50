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

        # Read input files.
        data_f, seq_f = sys.argv[1:3]
        seq_raw = read_sequence(seq_f)
        db = read_database(data_f)

        # Create dictionary with max repeated seqs.
        seq = {}
        strs = list(db[0].keys())[1:]
        for st in strs:
            max_repeat = count_max(seq_raw, st)
            seq[st] = max_repeat
        print(match(db, seq))

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
    """Read sequence file & return formatted string.

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

        # Found a match
        if subset == sub:
            founds += 1
            i += len(subset)

        else:
            if founds != 0:
                repeated.append(founds)
                founds = 0
            i += 1

    return max(repeated)

def match(db, seq):
    """Find a match of the sequence in the database

    Args:
        db (dict): database of person's dna containing STR repetitions.
        seq (dict): max STR repetitions found in sequence.

    Returns:
        person (string): name of person that matches, otherwise empty string.
    """
    for i in db:
        flag = 0
        for key, val in seq.items():
            if int(i[key]) == val:
                flag += 1
        if flag == len(seq):
            return i['name']
    return 'No match'

if __name__ == "__main__":
    main()
