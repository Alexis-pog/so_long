foo=$(ls | grep "o_files" | wc -l)

if [ $foo == 1 ]; then 
    echo "$foo";
else 
    echo "no such file"
    exit
fi