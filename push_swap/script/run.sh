read range
for((i = 1; i <= $range; i++))
do
	var=$(python3 random_number.py)
	./../push_swap "${var}" > test.txt
	cat test.txt | ./Checker_Mac "${var}"
	cat test.txt | wc -l
done
for((i = 1; i <= $range; i++))
do
	var=$(python3 random_number1-100.py)
	./../push_swap "${var}" > test.txt
	cat test.txt | ./Checker_Mac "${var}"
	cat test.txt | wc -l
	
done
