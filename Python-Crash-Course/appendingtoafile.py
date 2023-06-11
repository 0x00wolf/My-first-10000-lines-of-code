#   files can be opened in read mode 'r'
#   write mode 'w'
#   append mode 'a'
#   read and write mode 'r+'
file_is = 'programming.txt'
with open(file_is, 'a') as file_o:
    file_o.write("\nI will put on the mask\n")
    file_o.write("Good luck if you plan on getting in my way.\n")
    file_o.write("I wish you the best.")
    