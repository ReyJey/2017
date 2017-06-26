#!/usr/bin/env python3

import cs50

def main():
    counter = 0
    n = get_positive()
    dolar = round(n*100)
    while dolar>=25:
        dolar = dolar - 25
        counter += 1
    while dolar>=10:
        dolar = dolar - 10
        counter += 1
    while dolar>=5:
        dolar = dolar - 5
        counter += 1
    while dolar>=1:
        dolar = dolar - 1
        counter += 1
    print("{}".format(counter))


def get_positive():
    while True:
        print("O hai! How much change is owed?")
        n = cs50.get_float()
        if n > 0:
            break
    return n


if __name__ == "__main__":
    main()