#!/usr/bin/python3
####
# Standard library imports
####
from collections import Counter
from numpy.core.shape_base import block
import pylab as plt
import sys

dict_large = 'dictionaries/large'
dict_small = 'dictionaries/small'

def readDictintolist(dictFile = dict_large) -> list :
    '''
    opens the dictionar file and reads it into a list
    '''
    dicList = list()
    with open(dictFile) as f:
        for line in f:
            dicList.append(line.strip())
    return dicList

def hash_function_first_letter(word : str) -> int:
    '''
    Just the first letter
    '''
    return word[0]

def hash_function_first_2(word : str) -> int :
    hash_code = ''.join([e for e in word if e is not "'"])
    if len(hash_code) >= 2:
        hash_code = hash_code[:2]
    else:
        hash_code += hash_code
        print(hash_code)
    return hash_code

def generate_hash_table(initialwordlist : list, func) -> dict:
    '''
    Reads the dictionary as a list of words and the hash function return a Counter with
    hash values and number of members of the value
    '''
    h_list = list()
    for word in initialwordlist:
        h_list.append(func(word))
    cnt = Counter(h_list)
    print(cnt)
    return cnt

def plt_hash(hash_table : dict):
    '''
    Gets the hash table (dictionary) and plots it
    '''
    plt.figure('first')
    plt.clf()
    plt.plot(list(hash_table.keys()), list(hash_table.values()))
    plt.show(block = False)

if __name__ == '__main__':
    
    if len(sys.argv) == 1:
        word_dictinary = dict_large
    elif len(sys.argv) == 2:
        word_dictinary = sys.argv[1]
    else:
        raise SystemExit(f"Usage: {sys.argv[0]} dictionary-file")

    hash_table = generate_hash_table(readDictintolist(), hash_function_first_2)
    plt_hash(hash_table)
    