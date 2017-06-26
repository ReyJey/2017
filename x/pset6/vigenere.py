#!/usr/bin/env python3
import sys
import cs50

def main():
    if len(sys.argv) != 2:
        print("Usage: ./vigenere k")
        exit(1)
    else:
        key = sys.argv[1]
        for z in range(len(key)):
            if key.isalpha() == 0:
                print("Usage: ./vigenere k")
                exit(1)
    print("plaintext: ", end="")
    p = cs50.get_string()
    print("ciphertext: ", end="")
    funcvigenere(p, key)
	
def funcvigenere(strl, key):
    counter = 0
    counter2 = 0
    number = 0
    for i in range(len(strl)):
        o = len(key)
        symbol = strl[i]
        if symbol.isalpha():
            counter = counter % o
            number = key[counter].upper()
            number = ord(number)
            counter2 = (number - 65)%26
            if symbol.isupper():
                numb = ord(symbol)
                l = ((numb - 65) + counter2) % 26
                l = l + 65
                print("{}".format(chr(l)), end="")
            if symbol.islower():
                numb = ord(symbol)
                l = ((numb - 97) + counter2) % 26
                l = l + 97
                print("{}".format(chr(l)), end="")
            counter += 1
        else:
            print("{}".format(symbol), end="")
    print("")
        
	
if __name__ == "__main__":
    main()