awk -F ',' -v no=0 'BEGIN{print "s.no,","reg.no,","ca_mark"}
NR > 1{
if ($3 >= $5 && $4 >= $5)
avg=($3+$4)/2
else if ($3 >= $4 && $5 >= $4)
avg=($3+$5)/2
else
avg=($4+$5)/2;
if (avg < 15) no+=1;
print NR-1,",",$1,",",$2,",",avg
}END{print "no of student below 15 is",no}' Mark.csv > AvgMark.csv