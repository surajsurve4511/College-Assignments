'''
Title: - Python program to write different functions to perform operations on student records.

Aim: - Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students in the class. Write functions to compute following:

a) The average score of class

b) Highest score and lowest score of class

c) Count of students who were absent for the test

d) Display mark with highest frequency
'''

def student_marks():
  number_of_students = int(input("Enter the number of students: "))
  student_marks = []
  print("If a student is absent give him zero marks.")
  for i in range(number_of_students):
    marks = int(input(f"Enter marks for student {i+1}: "))
    student_marks.append(marks)
  print("Student Marks:", student_marks)
  return student_marks

def average_score(student_marks):
  total_marks = 0
  for marks in student_marks:
    total_marks += marks
  average = total_marks / len(student_marks)
  return average

def highest_score(student_marks):
  highest = student_marks[0]
  for marks in student_marks:
    if marks > highest:
      highest = marks
  return highest

def lowest_score(student_marks):
  lowest = student_marks[0]
  for marks in student_marks:
    if marks < lowest:
      lowest = marks
  return lowest

def absent_students(student_marks):
  absent_count = 0
  for marks in student_marks:
    if marks == 0:
      absent_count += 1
  return absent_count

def highest_frequency(student_marks):
  marks_count = {}
  #for marks in student_marks:
  #  if marks in marks_count:
  #    marks_count[marks] += 1
   # else:
   #   marks_count[marks] = 1

  #highest_frequency_mark = None
 # highest_frequency_count = 0
  #for mark, count in marks_count.items():
 #   if count > highest_frequency_count:
 #     highest_frequency_mark = mark
  #    highest_frequency_count = count
 # return highest_frequency_mark
  for marks in student_marks :
    i= 0
    if marks == student_marks[i]:
      highest_frequency = marks
      i += 1
  return highest_frequency

student_marks_list = student_marks()
print("Average Score:", average_score(student_marks_list))
print("Highest Score:", highest_score(student_marks_list))
print("Lowest Score:", lowest_score(student_marks_list))
print("Absent Students:", absent_students(student_marks_list))
print("Highest Frequency Mark:", highest_frequency(student_marks_list))
