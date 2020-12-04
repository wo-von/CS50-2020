#!/usr/bin/python3

###===
# Standard library imports

import sys
import csv
###===

def updateProfileDict(Prof, count, flag, STR):
    seq, max = Prof[STR]
    if count > max:
        max = count
    for _ in range(count):
        seq[flag] = count
        flag += len(STR)
    Prof[STR] = seq, max


def STR_hunter(seq, flag, STR):
    '''
    Once a `specific` STR is found, the sequence is passed to this function and it 
    tries to find out how far it goes
    '''
    count = 0
    while flag < len(seq):
        if seq[flag:flag + len(STR)] == STR:
            flag += len(STR)
            count += 1
        else:
            flag += 1
            return count
    return count


def sequence_profiler(sequenceFile, strs):
    '''
    opens the sequnece file into a string and a list of string s of STRs
    and marks how far each STR runs in the sequence
    '''
    # First read the sequnece
    f = open(sequenceFile)
    seq = f.read()
    f.close()
    
    # Sequence is profiled in a dictionary with strs as keys and a tuple of (string, max)
    # as value, string shows where each sequence of str starts and for how long
    # if str = "AGATC", then 
    # GGAGATCAGATCAGATCAGATCTAT
    # 0040000300002000010000
    profileDict = {}
    for str in strs:
        profileDict[str] = ([0] * len(seq), 0)

    flag = 0 # where we are in the sequence
    count  = 0 # For each STR, after one is found
    while flag < len(seq):
        for str in strs:
            if seq[flag:flag+len(str)] == str:
                count = STR_hunter(seq, flag, str)
                updateProfileDict(profileDict, count, flag, str)
                flag += count * len(str) - 1 # -1 since it gets added a 1 anyway
                count = 0
                break
        flag += 1
    return profileDict

    # profile = dict()
    # for str in strs:
    #     max = count = flag = 0
    #     while flag < len(seq):
    #         if seq[flag:flag+len(str)] == str:
    #             count += 1
    #             flag += len(str)
    #         else:
    #             flag += 1
    #             if count > max:
    #                 max = count
    #             else:
    #                 count = 0
    #     profile[str] = max
    # return profile    


def databasereader(csvfile, seqfile):
    '''
    Reads the database ask the seuence to be profiled and tries to find a match at each lien with the profile
    '''
    with open(csvfile) as f:
        rows = csv.DictReader(f)
        # What STRs are of interest
        STRList = rows.fieldnames[1:]
        # Calculate the longest consequetive STRs for the sequence
        profiledict = sequence_profiler(seqfile, STRList)
        found = False
        for suspect in rows:
            suspect = dict(suspect)
            for str in STRList:
                profileseq, max = profiledict[str]
                if max == int(suspect[str]):
                    found = True
                    continue
                else:
                    found = False
                    break
            if found:
                print(suspect['name'])
                break
        if not found:
            print("No Match")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 dna.py database.csv sequence.txt")
        exit(1)
    else:
        databasefile = sys.argv[1]
        sequencefile = sys.argv[2]
    databasereader(databasefile, sequencefile)
    