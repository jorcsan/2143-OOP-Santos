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
import sys
import random

#this class creates a single die
#
#def __init__(self,sides=None)
#def roll(self)
# def __str__(self)
#
#
#
#
class Die(object):
  def __init__(self,sides=None):
    if not sides:
      self.sides = 6
    else:
      if not isinstance(sides, int):
        print("error: sides is not an integer!")
        sys.exit()
      self.sides = sides

  def roll(self):
    values = [x for x in range(self.sides)]
    
    random.shuffle(values)
    
    return values[0] + 1
    
  def __str__(self):
    return f"[sides: {self.sides}]"
    
#this class creates multiple die, hence it is called dice
#
#
# def __init__(self,sides=None,num_dice=1)
#def sum(self)
#def max(self)
#def min(self)
#def avg(self)
#def roll(self,rollType=None)
#def __str__(self)
#
class Dice:
  def __init__(self,sides=None,num_dice=1):
    if not sides:
      print("Need to pass in sides!!!")
      sys.exit()
    elif isinstance(sides, str):
      print("sides is now a str (like 4.d.8)")
      parts = sides.split(".")
      num_dice = int(parts[0])
      sides = int(parts[2])
    self.sides = sides
    
    # create a container
    self.dice = []
    
    for die in range(num_dice):
      self.dice.append(Die(sides))

  #will roll all the dice and put each result in a list
  #Then we find the biggest roll result using the max() function
  def sum(self):
    total = 0
    for d in self.dice:
      total += d.roll()
      
    return total

  #will roll all the dice and put each result in a list
  #Then we find the biggest roll result using the max() function
  def max(self):
    maxval = 0
    rolls = []
    
    for d in self.dice:
      rolls.append(d.roll())
      
    maxval = max(rolls)
    
    return maxval

  #will roll all the dice and put each result in a list
  #Then we find the smallest roll result using the min() function
  def min(self):
    minval = 0
    rolls = []
    
    for d in self.dice:
      rolls.append(d.roll())
      
    minval = min(rolls)
    
    return minval

  #will roll all the dice and put each result in a list
  #Then we find the average roll result using the sum() function
  # then dividing it by the length of the list
  def avg(self):
    average = 0
    rolls = []
    
    for d in self.dice:
      rolls.append(d.roll())
      
    average = sum(rolls)/len(rolls)

    return average

  #will roll all the dice 
  #There are different types of roll
  def roll(self,rollType=None):

    if rollType =='max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()

  def __str__(self):
    s = "Dice:[\n"
    for d in self.dice:
      s = s + str(d)
    s = s+"\n]\n"
    return s




