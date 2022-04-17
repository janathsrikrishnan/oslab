VAR=$(awk '{sum+=$4}END{print sum/NR}' sales.txt)
echo "average sales is $VAR"
awk -v var=$VAR '{
	if($4 >= var) 
	print $1,$2,$3,$4;
}' sales.txt 
awk -v var=$VAR '{
	if($4 >= var) 
	print $1,$2,$3,$4;
}' sales.txt > greaterThanAverage.txt