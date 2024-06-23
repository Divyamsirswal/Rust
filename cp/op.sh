echo -n "Enter a number : "
read n

a=0
b=1

echo -n "$a $b "
for((i=2; i<=n; i++))
do
	f=$((a+b))
	echo -n "$f "
	a=$b
	b=$f
done
echo

