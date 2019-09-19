input="file.txt"

ln "$input" "$input.lock"

for (( c=1; c<=1000; c++ ))
do
	last_num="$(tail -n 1 $input)"
	next_num=$(($last_num + 1))
	echo $next_num >> $input
done


