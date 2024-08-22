'''
Title: - Python program to perform different set operations.

Aim: - In second year computer engineering class, group A student’s play cricket, group B students play badminton and group C students play football. Write a Python program using functions to compute following: -

a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
'''

groupA = []
groupB = []
groupC = []
for i in range(int(input("Enter number of students who play cricket : "))):
  groupA.append(input("Cricket players: "))
print("Group A:", groupA)
for i in range(int(input("Enter number of students who play badminton: "))):
    groupB.append(input("badminton players: "))
print("Group B:", groupB)
for i in range(int(input("Enter number of students who play football: "))):
    groupC.append(input("football players: "))
print("Group C:", groupC)

#list of students who play cricket
def groupA_cricket_groupB_badminton_groupC_football(groupA,groupB,groupC):
  def cri_bad(groupA, groupB):
    cri_bad = []
    for i in groupA:
       if i in groupB:
        cri_bad.append(i)
    print("Student who play both Cricket and badmintion: ", cri_bad)
    return cri_bad

  cri_bad(groupA, groupB)

  def cri_foo(groupA, groupC):
    cri_foo = []
    for i in groupA:
      if i in groupC:
       cri_foo.append(i)
    print("Student who play both Cricket and football: ", cri_foo)
    return cri_foo

  cri_foo(groupA, groupC)

  def cri_bad_foo(groupA, groupB, groupC):
    cri_bad_foo = []
    for i in groupA:
      if i in groupB and i in groupC:
        cri_bad_foo.append(i)
    print("Student who play both Cricket and badmintion and football: ", cri_bad_foo)
    return cri_bad_foo

  cri_bad_foo(groupA, groupB, groupC)



groupA_cricket_groupB_badminton_groupC_football(groupA,groupB,groupC)
