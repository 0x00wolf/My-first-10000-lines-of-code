#! /bin/bash

# script to convert three files designated by the user into a tarball
echo "First file:"
read file_1
echo "Second file:"
read file_2
echo "Third file:"
read file_3
echo "Output filename (do not add .tar):"
read filenameis
tar -cvf $filenameis $file_1 $file_2 $file_3a