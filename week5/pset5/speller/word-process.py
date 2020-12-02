#!/usr/bin/python3
####
# Standard library imports
####====
from collections import Counter
import pylab as plt
import sys
import string
####====

dict_large = 'dictionaries/large'
dict_small = 'dictionaries/small'
# A dictionary with ascii alphas and codes starting from 0
letter_codes = dict([pair for pair in zip(string.ascii_lowercase + "'", range(27))])

def readDictintolist(dictFile) -> list :
    '''
    opens the dictionar file and reads it into a list
    '''
    dicList = list()
    with open(dictFile) as f:
        for line in f:
            dicList.append(line.strip())
    return dicList

# FIXME actually a hash function should retuen and unsigned int
def hash_function_first_letter(word : str) -> str:
    '''
    Just the first letter
    '''
    return word[0]

# FIXME actually a hash function should retuen and unsigned int
def hash_function_first_2(word : str) -> int :
    '''
    use first two letters as hash code
    '''
    hash_code = ''.join([e for e in word if e is not "'"])
    if len(hash_code) >= 2:
        hash_code = hash_code[:2]
    else:
        hash_code += hash_code
        print(hash_code)
    return hash_code
# Sum of the letter codes as hash code
def hash_function_sum(word: str) -> int:
    hash_code = ''.join([e for e in word if e is not "'"])
    hash_code = sum([letter_codes[e] for e in hash_code])
    return hash_code

def hash_function_djb2(word: str) -> int:
    '''
    djb2 hash by dan bernstein
    '''
    hash_salt = 5381
    print(word, end=" hash")
    for letter in word:
        hash_salt = hash_salt * 33 + letter_codes[letter]
    print(hash_salt)
    return hash_salt

def generate_hash_table(initialwordlist : list, func) -> dict:
    '''
    Reads the dictionary as a list of words and the hash function return a Counter with
    hash values and number of members of the value
    '''
    h_list = list()
    for word in initialwordlist:
        h_list.append(func(word))
    cnt = Counter(h_list)
    return cnt

def plt_hash(hash_table : dict):
    '''
    Gets the hash table (dictionary) and plots it
    '''
    testList = [str(x) for x in hash_table.keys()]
    print(testList)
    print(hash_table)
    plt.figure('Sum')
    plt.clf()
    plt.plot([str(x) for x in hash_table.keys()], list(hash_table.values()))
    plt.title("use of sum of letter codes")
    plt.show(block = False)

if __name__ == '__main__':
    
    if len(sys.argv) == 1:
        word_dictinary = dict_large
    elif len(sys.argv) == 2:
        word_dictinary = sys.argv[1]
    else:
        raise SystemExit(f"Usage: {sys.argv[0]} dictionary-file")

    hash_table = generate_hash_table(readDictintolist(), hash_function_sum)
    # plt_hash(hash_table)
