#   files can be opened in read mode 'r'
#   write mode 'w'
#   append mode 'a'
#   read and write mode 'r+'
file_is = 'programming.txt'
with open(file_is, 'w') as file_o:
    file_o.write("I love programming.")
    file_o.write("\nBoom boom chicka boom.")