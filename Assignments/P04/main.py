                  
#  Author:           Jorge Santos
#  Title:            Roll them bones!
#  Course:           2143
#  Semester:         Spring 2021
# 
#  Description:
#        initializes die or dice and rolls them. Roll produces a 
# random number in the range of the die. There are different types of
#  rolls
#Usage:
#      create  die and dice and find the result of different types
# of rolls.
#  Files: TBD

from dice import Die
from dice import Dice

# Description:
#     will roll a instance of a dice 10 times by default
# the type of roll will depend on the testType parameter
# Params:
#      die, runs=10, testType="sum
# 
# Returns: void
#      
def dieTester(die, runs=10, testType="sum"):
    """Example function to test a die or dice.
    """
    if isinstance(die, Die):
      print(f"Testing {die.sides} sided die for {runs} rolls:")
      print("    [ ", end="")
      for i in range(runs):
        print(die.roll(), end=" ")
      print("]")
    else:
      print(f"Rolling {len(die.dice)} {die.sides} sided die {runs}   times to get the {testType} value:")
      print("    [ ", end="")
      for i in range(runs):
          if testType == "avg":
            print(die.avg(), end=" ")
          elif testType == "min":
            print(die.min(), end=" ")
          elif testType == "max":
            print(die.max(), end=" ")
          else:
            print(die.sum(), end=" ")
      print("]")


if __name__ == '__main__':
  
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