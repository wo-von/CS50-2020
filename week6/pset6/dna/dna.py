#!/usr/bin/python3

###===
# Standard library imports

import sys
import csv
###===

def sequence_profiler(sequenceFile, srts):
    '''
    gets the string of the sequnece and a list of strring s of SRTs
    and marks how far each SRT runs in the sequence
    '''
    # First read the sequnece
    f = open(sequenceFile)
    seq = f.read()
    f.close()
    # We read this string into a list of tuple with first item the SRT and the second
    # one its longest run from there on
    flag = 0 # where we are in the sequence
    while flag < len(seq):
        
    
    # profile = dict()
    # for srt in srts:
    #     max = count = flag = 0
    #     while flag < len(seq):
    #         if seq[flag:flag+len(srt)] == srt:
    #             count += 1
    #             flag += len(srt)
    #         else:
    #             flag += 1
    #             if count > max:
    #                 max = count
    #             else:
    #                 count = 0
    #     profile[srt] = max
    # return profile    


def databasereader(csvfile, seqfile):
    '''
    Reads the database ask the seuence to be profiled and tries to find a match at each lien with the profile
    '''
    with open(csvfile) as f:
        rows = csv.DictReader(f)
        # What SRTs are of interest
        SRTList = rows.fieldnames[1:]
        # Calculate the longest consequetive SRTs for the sequence
        profiledict = sequence_profiler(seqfile, SRTList)
        found = False
        for suspect in rows:
            suspect = dict(suspect)
            for srt in SRTList:
                if profiledict[srt] == int(suspect[srt]):
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
    