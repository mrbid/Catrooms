mkdir -p high
for file in ply/*.ply; do
	./ptf "$( basename $file )" > /dev/null 2>&1 &
done;
