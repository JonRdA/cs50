"""
Program that computes the readability using the Coleman-Liau index.
"""

""" 
TODO
Count the number of letters, words & sentences.
* Count letters: only chars a to z.
* Count words: sequence of chars separated by spaces.
* Count sentences: separated by period,, exclamation point or question mark.
"""

import cs50
import string

def count_in_text(text):
    """Count number of letters, words & sentences in text.

    Args:
        text (str): Text to be analized.

    Returns:
        (letters, words, sentences): tuple of ints with number of each.

    """
        
    letters, words, sentences = 0, 0, 0
    for i in text:
        if i in string.ascii_letters:
            letters += 1
        elif i == ' ':
            words += 1
        elif i in ['.', '!', '?']:
            sentences += 1

    return (letters, words + 1, sentences)

def coleman_liau(letters, words, sentences):
    """Compute the Coleman-Liau index as [.0488 * L - .296 * S - 15.8'

    Args:
        letters (int): number of letters is text.
        words (int): number of words in text.
        sentences (int): number of sentences in text.

    Returns:
        cli (int): Coleman-Liau index.

    """
    l = letters / words * 100
    s = sentences / words * 100
    cli = 0.0588 * l - .296 * s - 15.8
    return cli

def main():
    text = cs50.get_string("Text: ")
    l, w, s = count_in_text(text)
    cli = coleman_liau(l, w, s)

    if round(cli) < 1:
        print("Before Grade 1")
        return 8

    suffix = ''
    if cli > 16:
        print("Grade 16+")
        return 8

    print("Grade", str(round(cli)) + suffix)
    
if __name__ == '__main__':
    main()
