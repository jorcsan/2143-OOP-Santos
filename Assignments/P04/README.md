## P04 - Roll Them Bones
### Jorge Santos
### Description:

This program will be a step towards creating a dungeon and dragons program. It is a prgram that can create a single die or
multiple dice and roll them and get a number result. It can create dice of varying sizes. There are four different types of rolls
a sum, maximum, minimum, and average. The names are pretty self explanatory.



### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [main.py]()   | Main driver that holds the tester function    |
|   2   |  [dice.py]()  | holds the die and dice classes       |


### Instructions

- make sure to import sys and random



- Example Command:
  
  '''c++
  
  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)
  d4 = Dice("8.d.20")

  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 10, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")
  dieTester(d4, 20, "max")
  '''
